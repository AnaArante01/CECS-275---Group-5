/*
* This C++ header file contains the HomePage class definitions
* 
* CECS 275 - Fall 2025
* @authors Ana Jolynn Arante, Suphia Sidiqi
* @version 1.0.0
*/

#ifndef HOME_PAGE_H
#define HOME_PAGE_H

#include <gtkmm.h>
#include <string>

class HomePage {
    // Public interface
    public:
        /*
        ** Default constructor for HomePage class
        */
        HomePage();
        /*
        ** Overloaded Constructor to initialize HomePage with stack widgets
        */
        HomePage(const Glib::RefPtr<Gtk::Builder>& builder);
        /*
        ** Overloaded Constructor to initialize HomePage with username and password
        */
        //HomePage(const Glib::RefPtr<Gtk::Builder>& builder, std::string username, std::string password);

        void accountPage();
        // void uploadPage();
        // void sortPage();
        // void piePage();
        // void barPage();
        
        void set_view_mode();
    // Private interface
    private:
        void upload_page();

        // Account helper fuctions
        void edit_profile_mode(bool edit_mode);
        void enable_account_edit();
        void save_profile_info();
        void on_edit_clicked();
        void on_save_clicked();

        Glib::RefPtr<Gtk::Builder> builder_;
        std::string username_;
        std::string password_;

        Gtk::Stack* home_stack_ = nullptr;
        Gtk::StackSwitcher* home_stack_sw_ = nullptr;

        // Stack pages
        Gtk::Fixed* account_home_fxd_ = nullptr;
        Gtk::Fixed* upload_home_fxd_ = nullptr;
        Gtk::Fixed* sort_home_fxd_ = nullptr;
        Gtk::Fixed* pie_home_fxd_ = nullptr;
        Gtk::Fixed* bar_home_fxd_ = nullptr;

        // Account Page Widgets
        Gtk::Button* account_edit_btn_ = nullptr;
        Gtk::Button* account_save_btn_ = nullptr;
        Gtk::Entry* account_name_txt_ = nullptr;
        Gtk::Entry* account_contact_txt_ = nullptr;
        Gtk::Label* account_name_lbl_ = nullptr;
        Gtk::Label* account_contact_lbl_ = nullptr;
};

#endif // HOME_PAGE_H