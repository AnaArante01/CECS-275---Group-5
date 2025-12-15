#include "GradeBook.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <limits>
#include <algorithm>

// ------------------------------------------------------------
// Reads score file format:
//
// Required:
//   Line 1: category weights
//   Line 2: item counts per category
//   Line 3: drops per category
//
// Optional (line 4):
//   Max scores for each item
//
// Remaining rows:
//   studentID  score1 score2 score3 ...
//
// This version automatically detects whether the max-score
// line exists and handles BOTH file formats correctly.
// ------------------------------------------------------------
void ReadScoreFile(
    const std::string& filename,
    GradebookInfo& info,
    std::vector<int>& studentIDs,
    std::vector<std::vector<double>>& studentScores)
{
    std::ifstream file(filename);
    if (!file)
    {
        std::cerr << "ERROR: Cannot open score file.\n";
        return;
    }

    // ---------- Read weights ----------
    for (int i = 0; i < 5; i++)
        file >> info.weights[i];

    // ---------- Read counts ----------
    int totalItems = 0;
    for (int i = 0; i < 5; i++)
    {
        file >> info.counts[i];
        totalItems += info.counts[i];
    }

    // ---------- Read drops ----------
    for (int i = 0; i < 5; i++)
        file >> info.drops[i];

    // Move to next line
    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    // =========================================================
    // DETECT IF NEXT LINE IS A MAX-SCORE LINE
    // =========================================================
    std::streampos posBefore = file.tellg();
    std::string line;
    std::getline(file, line);

    std::stringstream maxss(line);
    std::vector<double> maybeMax;
    double m;

    while (maxss >> m)
        maybeMax.push_back(m);

    bool isMaxLine =
        maybeMax.size() == (size_t)totalItems &&
        std::all_of(maybeMax.begin(), maybeMax.end(),
                    [](double v){ return v >= 0 && v <= 300; });

    if (isMaxLine)
    {
        // Use the detected max scores
        info.maxScores = maybeMax;
    }
    else
    {
        // No max-score line → infer later
        info.maxScores.assign(totalItems, 0.0);

        // Rewind to process as student row
        file.clear();
        file.seekg(posBefore);
    }


    // =========================================================
    // READ STUDENT DATA
    // =========================================================
    studentIDs.clear();
    studentScores.clear();

    while (std::getline(file, line))
    {
        if (line.empty()) continue;

        std::stringstream iss(line);
        int id;

        if (!(iss >> id))
            continue; // skip malformed lines

        studentIDs.push_back(id);

        std::vector<double> row;
        row.reserve(totalItems);

        double score;
        while (iss >> score)
            row.push_back(score);

        // Ensure exactly totalItems length
        if ((int)row.size() < totalItems)
            row.resize(totalItems, 0.0);
        else if ((int)row.size() > totalItems)
            row.resize(totalItems);

        studentScores.push_back(row);
    }


    // =========================================================
    // IF NO MAX-SCORE LINE, INFER IT
    // =========================================================
    bool missingMax =
        std::all_of(info.maxScores.begin(), info.maxScores.end(),
                    [](double x){ return x == 0.0; });

    if (missingMax)
    {
        for (auto &row : studentScores)
            for (int i = 0; i < totalItems; i++)
                info.maxScores[i] = std::max(info.maxScores[i], row[i]);

        // Prevent divide-by-zero
        for (double &v : info.maxScores)
            if (v <= 0)
                v = 1;
    }
}
