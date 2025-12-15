#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <vector>
#include <string>
#include <array>

// ------------------------------------------------------------
// GradebookInfo
//
// Holds:
//   weights[]  - category weight percentages
//   counts[]   - number of items in each category
//   drops[]    - number of dropped scores per category
//   maxScores  - maximum scores for each individual item
// ------------------------------------------------------------
struct GradebookInfo
{
    std::array<double, 5> weights;  // Labs, Quizzes, Midterms, Project, Final
    std::array<int, 5> counts;
    std::array<int, 5> drops;
    std::vector<double> maxScores;
};

// ------------------------------------------------------------
// ReadScoreFile()
//   Reads the grading configuration and all student scores.
//   Handles files both WITH and WITHOUT max-score line.
// ------------------------------------------------------------
void ReadScoreFile(
    const std::string& filename,
    GradebookInfo& info,
    std::vector<int>& studentIDs,
    std::vector<std::vector<double>>& studentScores);

#endif
