/*
* This C++ header file contains the functions for a grade calculator program
* 
* CECS 275 - Fall 2025
* @authors Ana Jolynn Arante, Suphia Sidiqi
* @version 1.0.0
*/

//#include <gtk/gtk.h>
#include <gtkmm.h>
#include <fstream>
#include <string>

// struct GladeWidgets {
//     GtkWidget *username_txt;
//     GtkWidget *password_txt;
//     GtkWidget *msg_lbl;  // message label for feedback
// };

// struct LoginData {
//     GtkWidget *userIn;
//     GtkWidget *passIn;
//     GtkWidget *grd;
//     GtkWidget *msgLabel;
// };

void end_program (GtkWidget *wid, gpointer ptr)
{
    gtk_main_quit ();
}

// void verify_user (GtkWidget *wid, gpointer ptr);
// void register_user (GtkWidget *wid, gpointer ptr);

// void verify_user (GtkWidget *wid, gpointer ptr)
// {
//     GladeWidgets *widgets = (GladeWidgets *)ptr;
//     const char *username = gtk_entry_get_text (GTK_ENTRY (widgets->username_txt));
//     const char *password = gtk_entry_get_text (GTK_ENTRY (widgets->password_txt));
    
//     std::ifstream file("database.txt");
//     std::string dataUser, dataPass;
    
//     if (!file.is_open())
//     {
//         gtk_label_set_text (GTK_LABEL (widgets->reg_lbl), "Error: database.txt not found");
//         return;
//     }
    
//     file >> dataUser >> dataPass;
//     file.close();

//     if (std::string(username) == dataUser && std::string(password) == dataPass)
//     {
//         gtk_label_set_text (GTK_LABEL (widgets->reg_lbl), "Login Successful!");
//     }
//     else
//     {
//         gtk_label_set_text (GTK_LABEL (widgets->reg_lbl), "Login Failed. Invalid username or password.");
//     }
// }

// void register_user (GtkWidget *wid, gpointer ptr)
// {
//     LoginData *data = (LoginData *)ptr;

//     // Create a modal dialog for registration
//     GtkWidget *dlg = gtk_dialog_new_with_buttons ("Register New User", NULL, GTK_DIALOG_MODAL,
//         "Cancel", GTK_RESPONSE_CANCEL, "Register", GTK_RESPONSE_OK, NULL);

//     GtkWidget *content = gtk_dialog_get_content_area (GTK_DIALOG (dlg));
//     GtkWidget *grid = gtk_grid_new ();
//     gtk_grid_set_row_spacing (GTK_GRID (grid), 10);
//     gtk_grid_set_column_spacing (GTK_GRID (grid), 10);
//     gtk_container_set_border_width (GTK_CONTAINER (grid), 10);
//     gtk_container_add (GTK_CONTAINER (content), grid);

//     // Username label and entry
//     GtkWidget *user_lbl = gtk_label_new ("Username:");
//     GtkWidget *user_entry = gtk_entry_new ();
//     gtk_grid_attach (GTK_GRID (grid), user_lbl, 0, 0, 1, 1);
//     gtk_grid_attach (GTK_GRID (grid), user_entry, 1, 0, 1, 1);

//     // Password label and entry
//     GtkWidget *pass_lbl = gtk_label_new ("Password:");
//     GtkWidget *pass_entry = gtk_entry_new ();
//     gtk_entry_set_visibility (GTK_ENTRY (pass_entry), FALSE);
//     gtk_grid_attach (GTK_GRID (grid), pass_lbl, 0, 1, 1, 1);
//     gtk_grid_attach (GTK_GRID (grid), pass_entry, 1, 1, 1, 1);

//     // Confirm password label and entry
//     GtkWidget *confirm_lbl = gtk_label_new ("Confirm Password:");
//     GtkWidget *confirm_entry = gtk_entry_new ();
//     gtk_entry_set_visibility (GTK_ENTRY (confirm_entry), FALSE);
//     gtk_grid_attach (GTK_GRID (grid), confirm_lbl, 0, 2, 1, 1);
//     gtk_grid_attach (GTK_GRID (grid), confirm_entry, 1, 2, 1, 1);

//     gtk_widget_show_all (dlg);

//     int result = gtk_dialog_run (GTK_DIALOG (dlg));
//     if (result == GTK_RESPONSE_OK)
//     {
//         const char *username = gtk_entry_get_text (GTK_ENTRY (user_entry));
//         const char *password = gtk_entry_get_text (GTK_ENTRY (pass_entry));
//         const char *confirm = gtk_entry_get_text (GTK_ENTRY (confirm_entry));

//         // Validation
//         if (std::string(username).empty() || std::string(password).empty())
//         {
//             gtk_label_set_text (GTK_LABEL (data->msgLabel), "Error: Username and password cannot be empty");
//         }
//         else if (std::string(password) != std::string(confirm))
//         {
//             gtk_label_set_text (GTK_LABEL (data->msgLabel), "Error: Passwords do not match");
//         }
//         else
//         {
//             // Write to database
//             std::ofstream file("database.txt", std::ios::app);
//             if (!file.is_open())
//             {
//                 gtk_label_set_text (GTK_LABEL (data->msgLabel), "Error: Could not write to database.txt");
//             }
//             else
//             {
//                 file << std::endl;
//                 file << username << " " << password << "\n";
//                 file.close();
//                 gtk_label_set_text (GTK_LABEL (data->msgLabel), "Registration Successful!");
//             }
//         }
//     }
//     gtk_widget_destroy (dlg);
//     gtk_widget_show_all (data->grd);
// }

// void login_dialog (GtkWidget *wid, gpointer ptr)
// {
//     GtkWidget *dlg = gtk_dialog_new_with_buttons ("Login",
//         NULL,
//         GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
//         "Cancel", GTK_RESPONSE_CANCEL, "Login", GTK_RESPONSE_OK, NULL); 
//     GtkWidget *content = gtk_dialog_get_content_area (GTK_DIALOG (dlg));
//     GtkWidget *grid = gtk_grid_new (); 
//     gtk_grid_set_row_spacing (GTK_GRID (grid), 10);
//     gtk_grid_set_column_spacing (GTK_GRID (grid), 10);
//     gtk_container_set_border_width (GTK_CONTAINER (grid), 10);
//     gtk_container_add (GTK_CONTAINER (content), grid); 
//     GtkWidget *user_lbl = gtk_label_new ("Username:");
//     GtkWidget *pass_lbl = gtk_label_new ("Password:");
//     GtkWidget *user_entry = gtk_entry_new ();
//     GtkWidget *pass_entry = gtk_entry_new ();
//     gtk_entry_set_visibility (GTK_ENTRY (pass_entry), FALSE);
//     gtk_grid_attach (GTK_GRID (grid), user_lbl, 0, 0, 1, 1);
//     gtk_grid_attach (GTK_GRID (grid), user_entry, 1, 0, 1, 1);
//     gtk_grid_attach (GTK_GRID (grid), pass_lbl, 0, 1, 1, 1);
//     gtk_grid_attach (GTK_GRID (grid), pass_entry, 1, 1, 1, 1);
//     gtk_widget_show_all (dlg);
//     int result = gtk_dialog_run (GTK_DIALOG (dlg));
//     if (result == GTK_RESPONSE_OK)
//     {
//         const char *username = gtk_entry_get_text (GTK_ENTRY (user_entry));
//         const char *password = gtk_entry_get_text (GTK_ENTRY (pass_entry));
//         printf ("Username: %s\nPassword: %s\n", username, password);
//     }
//     gtk_widget_destroy (dlg);
//     gtk_widget_show_all (data->grd);
// }