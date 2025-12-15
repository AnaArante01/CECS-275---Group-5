#include "FinalProject.h"
#include <gtkmm.h>
#include <cmath>
#include <iomanip>
#include <sstream>

// =============================================================
// SET DATA FOR BAR CHART
// =============================================================
void BarChart::set_data(
    const std::vector<double>& student,
    const std::vector<double>& average,
    const std::vector<std::string>& labels)
{
    student_scores = student;
    avg_scores = average;
    category_labels = labels;
    queue_draw();
}

// =============================================================
// DRAW BAR CHART
// =============================================================
bool BarChart::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
    if (student_scores.empty() || avg_scores.empty())
        return true;

    const int width  = get_allocated_width();
    const int height = get_allocated_height();

    // Background
    cr->set_source_rgb(103/255.0, 22/255.0, 72/255.0);
    cr->paint();

    const double left = 40, right = 40, top = 20, bottom = 70;
    const double usable_w = width - left - right;
    const double usable_h = height - top - bottom;
    const double baseline = height - bottom;

    double max_val = 1.0;
    for (double v : student_scores) max_val = std::max(max_val, v);
    for (double v : avg_scores)     max_val = std::max(max_val, v);

    const int n = student_scores.size();
    const double group_w = usable_w / n;

    const double gap = group_w * 0.10;
    const double bar_w = group_w * 0.28;
    const double total = gap + bar_w + gap + bar_w + gap;
    const double offset = (group_w - total) / 2.0;

    double x = left;

    cr->set_font_size(12);

    // DRAW EACH GROUP
    for (int i = 0; i < n; i++)
    {
        double sh = (student_scores[i] / max_val) * usable_h;
        double ah = (avg_scores[i] / max_val) * usable_h;

        double sx = x + offset + gap;
        double ax = sx + bar_w + gap;

        // Student bar
        cr->set_source_rgb(1.0, 0.4, 0.7);
        cr->rectangle(sx, baseline - sh, bar_w, sh);
        cr->fill();

        // Average bar
        cr->set_source_rgb(1.0, 0.65, 0.85);
        cr->rectangle(ax, baseline - ah, bar_w, ah);
        cr->fill();

        // Text color
        cr->set_source_rgb(1, 1, 1);

        // Category label
        cr->set_font_size(13);
        cr->move_to(x + group_w * 0.22, baseline + 20);
        cr->show_text(category_labels[i]);

        // Percent labels
        cr->set_font_size(12);
        char buf[32];

        snprintf(buf, sizeof(buf), "%.1f%%", student_scores[i]);
        cr->move_to(sx, baseline - sh - 5);
        cr->show_text(buf);

        snprintf(buf, sizeof(buf), "%.1f%%", avg_scores[i]);
        cr->move_to(ax, baseline - ah - 5);
        cr->show_text(buf);

        x += group_w;
    }

    return true;
}  
