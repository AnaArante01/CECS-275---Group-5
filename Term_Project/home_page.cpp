/*
* This C++ file creates a HomePage class
* 
* CECS 275 - Fall 2025
* @authors Ana Jolynn Arante, Suphia Sidiqi
* @version 1.0.0
*/

#include <gtkmm.h>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

#include "home_page.h"

// Helper functions to save profile components
void save_profile_fields(const std::string& username, const std::string& password,
                         const std::string& name, const std::string& contact)
{
    std::ifstream in("profileInfo.txt");
    std::vector<std::string> lines;
    bool updated = false;

    std::string line;
    while (std::getline(in, line))
    {
        if (line.empty()) 
        {
            continue;
        }

        size_t firstSpace = line.find(' ');
        size_t secondSpace = line.find(' ', firstSpace + 1);
        if (firstSpace == std::string::npos || secondSpace == std::string::npos)
        {
            lines.push_back(line);
            continue;
        }

        std::string user = line.substr(0, firstSpace);
        std::string pass = line.substr(firstSpace + 1, secondSpace - firstSpace - 1);

        if (user == username && pass == password)
        {
            lines.push_back(username + " " + password + " |" + 
                name + "|" + contact + "|");
            updated = true;
        }
        else 
        {
            lines.push_back(line);
        }
    }

    if (!updated)
    {
        lines.push_back(username + " " + password + " |" + 
            name + "|" + contact);
    }

    std::ofstream out ("profileInfo.txt", std::ios::trunc);
    for (const auto& l : lines)
    {
        out << l << "\n";
    }
}

// Helper function to update profile components
bool update_profile(const std::string& username, const std::string& password,
                           std::string& nameOut, std::string& contactOut)
{
    std::ifstream input("profileInfo.txt");
    if (!input.is_open())
    {
        return false;
    }

    std::string line;
    while (std::getline(input, line))
    {
        if (line.empty())
        {
            continue;
        }

        size_t firstSpace = line.find(' ');
        size_t secondSpace = line.find(' ', firstSpace + 1);
        if (firstSpace == std::string::npos || secondSpace == std::string::npos)
        {
            continue;
        }

        std::string user = line.substr(0, firstSpace);
        std::string pass = line.substr(firstSpace + 1, secondSpace - firstSpace - 1);

        if (user != username || pass != password)
        {
            continue;
        }

        size_t a = line.find('|', secondSpace);
        size_t b = line.find('|', a + 1);
        size_t c = line.find('|', b + 1);
        
        if (a == std::string::npos || b == std::string::npos || c == std::string::npos)
        {
            return false;
        }

        nameOut = line.substr(a + 1, b - a - 1);
        contactOut = line.substr(b + 1, c - b - 1);
        return true;
    }
    return false;
}

/*
** Default constructor for HomePage class
*/
HomePage::HomePage()
    : builder_(nullptr), username_(""), password_("")
{
    // Empty constructor
}

/*
** Overloaded Constructor to initialize HomePage with stack widgets
*/
HomePage::HomePage(const Glib::RefPtr<Gtk::Builder>& builder) : builder_(builder)
{
    builder_->get_widget("home_stack", home_stack_);
    builder_->get_widget("home_fixed", home_fixed_);

    // Initialize pages
    accountPage();
    uploadPage();
    sortPage();
    piePage();
    barPage();
}

void HomePage::accountPage()
{
    // Get widgets from the builder
    builder_->get_widget("account_edit_btn", account_edit_btn_);
    builder_->get_widget("account_save_btn", account_save_btn_);

    builder_->get_widget("account_name_txt", account_name_txt_);
    builder_->get_widget("account_contact_txt", account_contact_txt_);

    builder_->get_widget("account_name_lbl", account_name_lbl_);
    builder_->get_widget("account_contact_lbl", account_contact_lbl_);

    if (!account_edit_btn_ || !account_save_btn_ || !account_name_txt_ || !account_contact_txt_ ||
        !account_name_lbl_ || !account_contact_lbl_)
    {
        std::cerr << "Error: One or more widgets could not be found in the builder.\n";
        return;
    }

    // Load saved profile if it exists
    std::string n, c;
    if (update_profile(username_, password_, n, c))
    {
        account_name_lbl_->set_text(n);
        account_contact_lbl_->set_text(c);
    }

    account_edit_btn_->signal_clicked().connect(sigc::mem_fun(*this, &HomePage::on_edit_clicked));
    account_save_btn_->signal_clicked().connect(sigc::mem_fun(*this, &HomePage::on_save_clicked));

    edit_profile_mode(false);
}


void HomePage::edit_profile_mode(bool edit_mode)
{
    account_save_btn_->set_visible(edit_mode);

    account_name_txt_->set_visible(edit_mode);
    account_contact_txt_->set_visible(edit_mode);

    account_name_lbl_->set_visible(!edit_mode);
    account_contact_lbl_->set_visible(!edit_mode);
}

void HomePage::enable_account_edit()
{
    account_name_txt_->set_text(account_name_lbl_->get_text());
    account_contact_txt_->set_text(account_contact_lbl_->get_text());
    edit_profile_mode(true);
}

void HomePage::save_profile_info()
{
    account_name_lbl_->set_text(account_name_txt_->get_text());
    account_contact_lbl_->set_text(account_contact_txt_->get_text());

    save_profile_fields(username_, password_, account_name_lbl_->get_text(), account_contact_lbl_->get_text());

    edit_profile_mode(false);
}

void HomePage::set_view_mode()
{
    edit_profile_mode(false);
}

void HomePage::on_edit_clicked()
{
    enable_account_edit();
}

void HomePage::on_save_clicked()
{
    save_profile_info();
}
