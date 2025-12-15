/*
* This C++ header file contains the functions for a grade calculator program
* 
* CECS 275 - Fall 2025
* @authors Ana Jolynn Arante, Suphia Sidiqi
* @version 1.0.0
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <gtkmm.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "home_page.h"

// Forward declarations
void home_page_win(Gtk::Window* login_win, const std::string& username, const std::string& password);
static std::string avatar_search(const std::string& username, const std::string& password);
static void save_avatar(const std::string& username, const std::string& password, const std::string& newPath);
void change_avatar(Gtk::Window* home_page, Gtk::Image* avatar_img, const std::string& username, const std::string& password);



// Function to end the program
inline void end_program()
{
    exit(0);
}

inline void user_login(Gtk::Window* login_win, Gtk::Entry* username_txt, Gtk::Entry* password_txt, Gtk::Label* auth_lbl)
{
    std::string username = username_txt->get_text();
    std::string password = password_txt->get_text();

    std::ifstream userInfo("database.txt");
    std::vector<std::string> usernames;
    std::vector<std::string> passwords;
    std::string userIn, passIn;

    // Read all usernames and passwords from database.txt file
    while (userInfo >> userIn >> passIn)
    {
        usernames.push_back(userIn);
        passwords.push_back(passIn);
    }
    userInfo.close();

    // Check if username and password match database
    bool exist = false;
    for (size_t i = 0; i < usernames.size(); i++)
    {
        if (usernames[i] == username && passwords[i] == password)
        {
            exist = true;
            break;
        }
    }

    if (!exist)
    {
        auth_lbl->set_text("Login Failed. Please try again.");
    }
    else
    {
        auth_lbl->set_text("Login Successful!");
        // Open home page window
        home_page_win(login_win, username, password);
    }
}

// Pseudocode for user registration function
/*
if user presses register button
    open registration dialog
    prompt user for new username and password
    if username already exists in database.txt
        display "Username already exists" message
    else
        add new username and password to new line in database.txt
        display "Registration successful" message
    prompt user to log in with new credentials
*/
// Cleanup helper for registration data
inline void submit_registration(Gtk::Window* reg_win, Gtk::Window* login_win, Gtk::Entry* new_user_txt, 
                         Gtk::Entry* new_pass_txt, Gtk::Label* success_lbl)
{
    std::string new_username = new_user_txt->get_text();
    std::string new_password = new_pass_txt->get_text();

    std::ifstream userData("database.txt");
    std::vector<std::string> usernames;
    std::vector<std::string> passwords;
    std::string dataUser, dataPass;

    std::ofstream avatarOut("avatars.txt", std::ios::app);

    // Read all usernames from database.txt file
    while (userData >> dataUser >> dataPass)
    {
        usernames.push_back(dataUser);
        passwords.push_back(dataPass);
    }
    userData.close();

    // Check if username already exists
    bool exist = false;
    for (size_t i = 0; i < usernames.size(); i++)
    {
        if (usernames[i] == new_username)
        {
            exist = true;
            break;
        }
    }

    if (exist)
    {
        success_lbl->set_text("Username already exists.");
    }
    else
    {
        std::ofstream newDataOut("database.txt", std::ios::app);
        newDataOut << new_username << " " << new_password << std::endl;
        newDataOut.close();
        success_lbl->set_text("New User Created!");

        // Add default avatar entry
        avatarOut << new_username << " " << new_password << " " << "default_profile_icon.png" << std::endl;
        avatarOut.close();

        // Add default profile info entry
        std::ofstream profileOut("profileInfo.txt", std::ios::app);
        profileOut << new_username << " " << new_password << " |" << "First Name, Last Name" << "|" << "emailaddress@student.com" << std::endl;
        profileOut.close();

        // Close registration window and show login window
        reg_win->hide();
        login_win->show_all();
    }
}

// Open registration window
inline void register_user_win(Gtk::Window* login_win)
{
    // Load the registration UI from glade file
    auto builder = Gtk::Builder::create_from_file("mylayout1.glade");

    Gtk::Window* reg_win = nullptr;
    Gtk::Entry* new_user_txt = nullptr;
    Gtk::Entry* new_pass_txt = nullptr;
    Gtk::Label* success_lbl = nullptr;
    Gtk::Button* register_btn = nullptr;
    Gtk::Button* reg_close_btn = nullptr;

    builder->get_widget("reg_win", reg_win);
    builder->get_widget("new_user_txt", new_user_txt);
    builder->get_widget("new_pass_txt", new_pass_txt);
    builder->get_widget("success_lbl", success_lbl);
    builder->get_widget("register_btn", register_btn);
    builder->get_widget("reg_close_btn", reg_close_btn);

    // Hide login window while register window is open
    login_win->hide();

    // Connect signals
    register_btn->signal_clicked().connect(
        sigc::bind(sigc::ptr_fun(submit_registration),
            reg_win, login_win, new_user_txt, new_pass_txt, success_lbl));

    // When close button is pressed, close reg window and show login
    reg_close_btn->signal_clicked().connect([reg_win, login_win]() {
        reg_win->hide();
        login_win->show_all();
    });

    reg_win->show_all();
}

// Pseudocode for home page after login
/*
if login is successful
    close login window
    open home page window
    display welcome message with username
    provide stack options for grade calculator features
*/
inline void home_page_win(Gtk::Window* login_win, const std::string& username, const std::string& password)
{
    // Hide login window
    login_win->hide();

    // Load the home page UI from glade file
    auto builder = Gtk::Builder::create_from_file("mylayout1.glade");
    Gtk::Window* home_win = nullptr;
    builder->get_widget("home_win", home_win);

    // Avatar components
    Gtk::Button* account_change_avatar_btn = nullptr;
    Gtk::Image* avatar_img = nullptr;
    builder->get_widget("account_change_avatar_btn", account_change_avatar_btn);
    builder->get_widget("avatar_img", avatar_img);

    std::string path = avatar_search(username, password);
    if(path.empty())
    {
        path = "default_profile_icon.png";
    }
    if (avatar_img)
    {
        try
        {
            auto pixbuf = Gdk::Pixbuf::create_from_file(path, 200, 200, true);
            avatar_img->set(pixbuf);
        }
        catch (const Glib::Error& error)
        {
            std::cerr << "Error loading image: " << error.what() << "\n";
        }
    }

    if (account_change_avatar_btn && avatar_img)
    {
        account_change_avatar_btn->signal_clicked().connect(sigc::bind(sigc::ptr_fun(change_avatar), 
                                   home_win, avatar_img, username, password));
    }

    HomePage* homePage = new HomePage(builder, username, password);

    home_win->signal_hide().connect(sigc::ptr_fun(end_program));

    home_win->show();

    homePage->set_view_mode();
}


// Pseudocode for change profile picture function
/*
The user can change their profile picture by selecting a .png or .jpg file from their computer.
void change_avatar()
{
    When change_avatar_btn is clicked
        Open file chooser dialog to select image file
        If user selects a file
            Update profile picture with selected image
    }
*/
static std::string avatar_search(const std::string& username, const std::string& password)
{
    std::ifstream in("avatars.txt");
    if (!in.is_open()) return "";

    std::string u, p, path;
    while (in >> u >> p)
    {
        std::getline(in, path);                 // rest of line is path
        if (!path.empty() && path[0] == ' ') path.erase(0, 1);

        if (u == username && p == password) return path;
    }
    return "";
}

static void save_avatar(const std::string& username, const std::string& password, const std::string& newPath)
{
    std::ifstream input("avatars.txt");
    std::vector<std::string> lines;
    bool updated = false;

    if (input.is_open())
    {
        std::string u, p, path;

        while (input >> u >> p)
        {
            std::getline(input, path);
            if (!path.empty() && path[0] == ' ') path.erase(0, 1);

            if (u == username && p == password)
            {
                lines.push_back(u + " " + p + " " + newPath);
                updated = true;
            }
            else
            {
                lines.push_back(u + " " + p + " " + path);
            }
        }
        input.close();
    }

    if (!updated)
        lines.push_back(username + " " + password + " " + newPath);

    std::ofstream output("avatars.txt", std::ios::trunc);
    for (const auto& line : lines) output << line << "\n";
}

inline void change_avatar(Gtk::Window* home_page, Gtk::Image* avatar_img,
                   const std::string& username, const std::string& password)
{
    Gtk::FileChooserDialog dialog(*home_page, "Select Profile Picture", Gtk::FILE_CHOOSER_ACTION_OPEN);

    dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
    dialog.add_button("_Open", Gtk::RESPONSE_OK);

    auto filter_image = Gtk::FileFilter::create();
    filter_image->set_name("Image files");
    filter_image->add_mime_type("image/png");
    filter_image->add_mime_type("image/jpeg");
    filter_image->add_mime_type("image/jpg");
    dialog.add_filter(filter_image);

    if (dialog.run() == Gtk::RESPONSE_OK)
    {
        std::string filename = dialog.get_filename();

        try
        {
            auto pixbuf = Gdk::Pixbuf::create_from_file(filename, 200, 200, true);
            avatar_img->set(pixbuf);

            save_avatar(username, password, filename);
        }
        catch (const Glib::Error& error)
        {
            std::cerr << "Error loading image: " << error.what() << "\n";
        }
    }
}

#endif // FUNCTIONS_H

 
