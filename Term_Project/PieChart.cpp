#include "FinalProject.h"
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>

// ------------------------------------------------------------
// SET PIE CHART DATA
// ------------------------------------------------------------
void PieChart::set_data(const GradeDistribution& distribution)
{
    grades = distribution;
    queue_draw();
}

// ------------------------------------------------------------
// DRAW PIE CHART WITH PERCENT + LETTER LABELS
// ------------------------------------------------------------
bool PieChart::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
    int width  = get_allocated_width();
    int height = get_allocated_height();

    if (width <= 0 || height <= 0)
        return true;

    double cx = width / 2.0;
    double cy = height / 2.0;
    double radius = std::min(width, height) / 2.5;

    int total = grades.countA + grades.countB +
                grades.countC + grades.countD + grades.countF;

    if (total == 0)
        return true;

    // Background
    cr->set_source_rgb(103/255.0, 22/255.0, 72/255.0);
    cr->paint();

    double start_angle = 0.0;

    // Helper function to draw a slice
    auto draw_slice = [&](int count, double r, double g, double b,
                          const std::string& letter)
    {
        if (count <= 0) return;

        double frac = (double)count / total;
        double angle = frac * 2 * M_PI;

        // Slice color
        cr->set_source_rgb(r, g, b);
        cr->move_to(cx, cy);
        cr->arc(cx, cy, radius, start_angle, start_angle + angle);
        cr->close_path();
        cr->fill();

        // Position label at slice center
        double mid = start_angle + angle / 2.0;
        double lx = cx + std::cos(mid) * (radius * 0.70);
        double ly = cy + std::sin(mid) * (radius * 0.70);

        // Build label text
        char buf[64];
        double pct = frac * 100.0;
        snprintf(buf, sizeof(buf), "%s\n%.1f%%", letter.c_str(), pct);

        // Draw label
        cr->set_source_rgb(1, 1, 1);
        cr->set_font_size(16);

        cr->move_to(lx, ly);
        cr->show_text(buf);

        // Move start for next slice
        start_angle += angle;
    };

    // DRAW SLICES (A → F)
    draw_slice(grades.countA, 1.0, 0.5, 0.8, "A");
    draw_slice(grades.countB, 1.0, 0.4, 0.7, "B");
    draw_slice(grades.countC, 1.0, 0.3, 0.7, "C");
    draw_slice(grades.countD, 0.9, 0.3, 0.6, "D");
    draw_slice(grades.countF, 0.8, 0.2, 0.5, "F");

    return true;
}
