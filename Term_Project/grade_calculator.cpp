
#include <gtkmm.h>
#include "functions.h"

// static void add_custom_icons()
// {
//     auto theme = Gtk::IconTheme::get_default();
//     theme->append_search_path("data/icons");
// }

int main(int argc, char* argv[])
{
    //add_custom_icons();

    auto app = Gtk::Application::create(argc, argv, "com.example.gradecalc");

    // Load CSS styling
    auto css_provider = Gtk::CssProvider::create();
    css_provider->load_from_path("window_col.css");
    Gtk::StyleContext::add_provider_for_screen(Gdk::Screen::get_default(), css_provider, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    // Load the UI from glade file
    auto builder = Gtk::Builder::create_from_file("mylayout1.glade");

    // Get widgets from the builder
    Gtk::Window* login_win = nullptr;
    Gtk::Entry* username_txt = nullptr;
    Gtk::Entry* password_txt = nullptr;
    Gtk::Label* auth_lbl = nullptr;
    Gtk::Button* verify_btn = nullptr;
    Gtk::Button* login_close_btn = nullptr;
    Gtk::Button* reg_btn = nullptr;

    builder->get_widget("login_win", login_win);
    builder->get_widget("username_txt", username_txt);
    builder->get_widget("password_txt", password_txt);
    builder->get_widget("auth_lbl", auth_lbl);
    builder->get_widget("verify_btn", verify_btn);
    builder->get_widget("login_close_btn", login_close_btn);
    builder->get_widget("reg_btn", reg_btn);

    // Set password entry to hide text
    password_txt->set_visibility(false);

    // Connect signals
    verify_btn->signal_clicked().connect(
        sigc::bind(sigc::ptr_fun(user_login),
            login_win, username_txt, password_txt, auth_lbl));

    reg_btn->signal_clicked().connect(
        sigc::bind(sigc::ptr_fun(register_user_win), login_win));

    login_close_btn->signal_clicked().connect(sigc::ptr_fun(end_program));

    // Keep app alive even when windows are hidden
    app->hold();

    login_win->show_all();
    
    return app->run();
}



