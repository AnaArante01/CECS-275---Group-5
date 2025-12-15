#ifndef FINALPROJECT_H
#define FINALPROJECT_H

#include <gtkmm/drawingarea.h>
#include <vector>
#include <string>
#include "GradeBook.h"

// ============================================================
// CATEGORY STRUCTS
// ============================================================

struct CategoryScores {
    double lab = 0;
    double quiz = 0;
    double midterm = 0;
    double project = 0;
    double finalExam = 0;
};

struct CategoryAverages {
    double lab = 0;
    double quiz = 0;
    double midterm = 0;
    double project = 0;
    double finalExam = 0;
};

// Pie-chart grade distribution
struct GradeDistribution {
    int countA = 0;
    int countB = 0;
    int countC = 0;
    int countD = 0;
    int countF = 0;
};

// ============================================================
// BAR CHART CLASS
// ============================================================
class BarChart : public Gtk::DrawingArea
{
public:
    void set_data(const std::vector<double>& student,
                  const std::vector<double>& average,
                  const std::vector<std::string>& labels);

protected:
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

private:
    std::vector<double> student_scores;
    std::vector<double> avg_scores;
    std::vector<std::string> category_labels;
};

// ============================================================
// PIE CHART CLASS
// ============================================================
class PieChart : public Gtk::DrawingArea
{
public:
    void set_data(const GradeDistribution& dist);

protected:
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

private:
    GradeDistribution grades;
};

// ============================================================
// SCORE COMPUTATION FUNCTIONS
// ============================================================
CategoryScores compute_student(const GradebookInfo& info,
                               const std::vector<double>& row);

CategoryAverages compute_class_average(const GradebookInfo& info,
                                       const std::vector<std::vector<double>>& rows);

double compute_final_percent(const CategoryScores& s,
                             const GradebookInfo& info);

#endif
