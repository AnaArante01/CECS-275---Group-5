#include "FinalProject.h"
#include <numeric>
#include <algorithm>
#include <vector>

// ------------------------------------------------------------
// INTERNAL: Compute percent for a category with drops
// ------------------------------------------------------------
static double compute_category_percent(
    const std::vector<double>& scores,
    const std::vector<double>& maxScores,
    int start, int count, int drops)
{
    if (count <= 0)
        return 0.0;

    // Build index list and sort by score ascending for dropping
    std::vector<int> idx(count);
    std::iota(idx.begin(), idx.end(), 0);

    std::sort(idx.begin(), idx.end(),
        [&](int a, int b)
        {
            return scores[start + a] < scores[start + b];
        });

    double earn = 0.0;
    double possible = 0.0;

    // Skip the lowest "drops" scores
    for (int i = drops; i < count; i++)
    {
        int k = idx[i];
        earn += scores[start + k];
        possible += maxScores[start + k];
    }

    if (possible <= 0)
        return 0.0;

    return (earn / possible) * 100.0;
}

// ------------------------------------------------------------
// Compute percentages for ONE student across all categories
// ------------------------------------------------------------
CategoryScores compute_student(
    const GradebookInfo& info,
    const std::vector<double>& row)
{
    CategoryScores cs{};
    int pos = 0;

    cs.lab       = compute_category_percent(row, info.maxScores,
                                            pos, info.counts[0], info.drops[0]);
    pos += info.counts[0];

    cs.quiz      = compute_category_percent(row, info.maxScores,
                                            pos, info.counts[1], info.drops[1]);
    pos += info.counts[1];

    cs.midterm   = compute_category_percent(row, info.maxScores,
                                            pos, info.counts[2], info.drops[2]);
    pos += info.counts[2];

    cs.project   = compute_category_percent(row, info.maxScores,
                                            pos, info.counts[3], info.drops[3]);
    pos += info.counts[3];

    cs.finalExam = compute_category_percent(row, info.maxScores,
                                            pos, info.counts[4], info.drops[4]);

    return cs;
}

// ------------------------------------------------------------
// Compute CLASS AVERAGES for each category
// ------------------------------------------------------------
CategoryAverages compute_class_average(
    const GradebookInfo& info,
    const std::vector<std::vector<double>>& rows)
{
    CategoryAverages avg{0,0,0,0,0};
    if (rows.empty()) return avg;

    for (auto &row : rows)
    {
        CategoryScores s = compute_student(info, row);
        avg.lab       += s.lab;
        avg.quiz      += s.quiz;
        avg.midterm   += s.midterm;
        avg.project   += s.project;
        avg.finalExam += s.finalExam;
    }

    avg.lab       /= rows.size();
    avg.quiz      /= rows.size();
    avg.midterm   /= rows.size();
    avg.project   /= rows.size();
    avg.finalExam /= rows.size();

    return avg;
}

// ------------------------------------------------------------
// Compute weighted final percent according to weights
// ------------------------------------------------------------
double compute_final_percent(const CategoryScores& s,
                             const GradebookInfo& info)
{
    return
        s.lab       * (info.weights[0] / 100.0) +
        s.quiz      * (info.weights[1] / 100.0) +
        s.midterm   * (info.weights[2] / 100.0) +
        s.project   * (info.weights[3] / 100.0) +
        s.finalExam * (info.weights[4] / 100.0);
}
