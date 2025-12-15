#include <gtkmm.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include "FinalProject.h"
#include "GradeBook.h"

int main(int argc, char* argv[])
{
    auto app = Gtk::Application::create("grade.visualizer");

    // Load UI
    auto builder = Gtk::Builder::create_from_file("BarChart.glade");

    Gtk::Window* window = nullptr;
    Gtk::DrawingArea* bar_placeholder = nullptr;
    Gtk::DrawingArea* pie_placeholder = nullptr;
    Gtk::FileChooserButton* file_btn = nullptr;
    Gtk::ComboBoxText* student_selector = nullptr;
    Gtk::ComboBoxText* sort_selector = nullptr;
    Gtk::Button* sort_button = nullptr;
    Gtk::TextView* file_textview = nullptr;

    builder->get_widget("main_window", window);
    builder->get_widget("bar_chart_area", bar_placeholder);
    builder->get_widget("pie_chart_area", pie_placeholder);
    builder->get_widget("file_button", file_btn);
    builder->get_widget("student_selector", student_selector);
    builder->get_widget("sort_selector", sort_selector);
    builder->get_widget("sort_button", sort_button);
    builder->get_widget("file_textview", file_textview);

    // ---- Create chart widgets ----
    BarChart* chart = Gtk::make_managed<BarChart>();
    Gtk::Container* bar_parent = bar_placeholder->get_parent();
    bar_parent->remove(*bar_placeholder);
    bar_parent->add(*chart);
    chart->show();

    PieChart* pie = Gtk::make_managed<PieChart>();
    Gtk::Container* pie_parent = pie_placeholder->get_parent();
    pie_parent->remove(*pie_placeholder);
    pie_parent->add(*pie);
    pie->show();

    // ---- Data storage ----
    GradebookInfo info;
    std::vector<int> studentIDs;
    std::vector<std::vector<double>> studentScores;

    // ---- Helper function to update bar chart ----
    auto update_chart = [&](int index)
    {
        if (studentScores.empty()) return;

        CategoryScores S = compute_student(info, studentScores[index]);
        CategoryAverages A = compute_class_average(info, studentScores);

        chart->set_data(
            { S.lab, S.quiz, S.midterm, S.project, S.finalExam },
            { A.lab, A.quiz, A.midterm, A.project, A.finalExam },
            { "Labs", "Quizzes", "Midterms", "Project", "Final" }
        );
    };

    // ---- Helper: recompute and redraw pie chart ----
    auto update_pie = [&]()
    {
        GradeDistribution dist{0,0,0,0,0};

        for (auto& row : studentScores)
        {
            CategoryScores S = compute_student(info, row);
            double fp = compute_final_percent(S, info);

            if (fp >= 90) dist.countA++;
            else if (fp >= 80) dist.countB++;
            else if (fp >= 70) dist.countC++;
            else if (fp >= 60) dist.countD++;
            else dist.countF++;
        }

        pie->set_data(dist);
    };

    // ---- Loading the file ----
    file_btn->signal_file_set().connect([&]()
    {
        std::string filename = file_btn->get_filename();

        studentIDs.clear();
        studentScores.clear();

        ReadScoreFile(filename, info, studentIDs, studentScores);

        // Display file contents
        std::ifstream fin(filename);
        std::stringstream ss;
        ss << fin.rdbuf();
        file_textview->get_buffer()->set_text(ss.str());

        if (studentScores.empty()) return;

        // Fill student selector
        student_selector->remove_all();
        for (int id : studentIDs)
            student_selector->append(std::to_string(id));

        student_selector->set_active(0);

        // Draw charts immediately
        update_chart(0);
        update_pie();

        chart->queue_draw();
        pie->queue_draw();
        while (Gtk::Main::events_pending())
            Gtk::Main::iteration();
    });

    // ---- Student selection updates bar chart ----
    student_selector->signal_changed().connect([&]()
    {
        if (studentScores.empty()) return;
        update_chart(student_selector->get_active_row_number());
    });

    // ---- Apply sorting ----
    sort_button->signal_clicked().connect([&]()
    {
        if (studentScores.empty()) return;

        std::vector<int> order(studentIDs.size());
        std::iota(order.begin(), order.end(), 0);

        std::string mode = sort_selector->get_active_text();

        // Sort by ID
        if (mode == "ID")
        {
            std::sort(order.begin(), order.end(),
                [&](int a, int b){ return studentIDs[a] < studentIDs[b]; });
        }
        // Sort by final percent
        else if (mode == "Final %")
        {
            std::sort(order.begin(), order.end(),
                [&](int a, int b)
                {
                    double pa = compute_final_percent(compute_student(info, studentScores[a]), info);
                    double pb = compute_final_percent(compute_student(info, studentScores[b]), info);
                    return pa > pb;
                });
        }
        // Sort by letter grade
        else
        {
            auto rank = [&](double p)
            {
                if (p >= 90) return 0;
                if (p >= 80) return 1;
                if (p >= 70) return 2;
                if (p >= 60) return 3;
                return 4;
            };

            std::sort(order.begin(), order.end(),
                [&](int a, int b)
                {
                    double pa = compute_final_percent(compute_student(info, studentScores[a]), info);
                    double pb = compute_final_percent(compute_student(info, studentScores[b]), info);
                    return rank(pa) < rank(pb);
                });
        }

        // Reorder student lists
        std::vector<int> newIDs;
        std::vector<std::vector<double>> newScores;

        for (int idx : order)
        {
            newIDs.push_back(studentIDs[idx]);
            newScores.push_back(studentScores[idx]);
        }

        studentIDs = newIDs;
        studentScores = newScores;

        // Refresh the selector UI
        student_selector->remove_all();
        for (int id : studentIDs)
            student_selector->append(std::to_string(id));

        student_selector->set_active(0);
        update_chart(0);
        update_pie();
    });

    return app->run(*window);
}
