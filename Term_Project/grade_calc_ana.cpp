#include <gtkmm.h> // Header file for C++ GTKmm
#include "functions.h"

int main (int argc, char *argv[])
{
    gtk_init (&argc, &argv);
    GtkBuilder *builder = gtk_builder_new ();

    gtk_builder_add_from_file (builder, "mylayout1.glade", NULL);

    GtkWidget *login_win = GTK_WIDGET(gtk_builder_get_object(builder, "login_win")); // Starting window for login and registration
    GtkWidget *fixed1    = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));
    GtkWidget *logo      = GTK_WIDGET(gtk_builder_get_object(builder, "logo"));      // Logo image widget

    GtkWidget *reg_lbl   = GTK_WIDGET(gtk_builder_get_object(builder, "reg_lbl"));         // Registration label
    GtkWidget *reg_btn   = GTK_WIDGET(gtk_builder_get_object(builder, "reg_btn"));         // Registration button

    GtkWidget *username_lbl = GTK_WIDGET(gtk_builder_get_object(builder, "username_lbl")); // Username label
    GtkWidget *username_txt = GTK_WIDGET(gtk_builder_get_object(builder, "username_txt")); // Username text entry

    GtkWidget *password_lbl = GTK_WIDGET(gtk_builder_get_object(builder, "password_lbl")); // Password label
    GtkWidget *password_txt = GTK_WIDGET(gtk_builder_get_object(builder, "password_txt")); // Password text entry

    GtkWidget *msg_lbl    = GTK_WIDGET(gtk_builder_get_object(builder, "msg_lbl"));        // Message label for feedback
    GtkWidget *verify_btn = GTK_WIDGET(gtk_builder_get_object(builder, "verify_btn"));     // Verify login button
    GtkWidget *close_btn  = GTK_WIDGET(gtk_builder_get_object(builder, "close_btn"));      // Close program button

    g_signal_connect (login_win, "delete-event", G_CALLBACK (end_program), NULL);   // Close window
    g_signal_connect (verify_btn, "clicked", G_CALLBACK (end_program), NULL);  // Placeholder for login function
    g_signal_connect (close_btn, "clicked", G_CALLBACK (end_program), NULL);
    g_signal_connect (reg_btn, "clicked", G_CALLBACK (end_program), NULL);  // Placeholder for registration function
    
    //gtk_window_fullscreen(GTK_WINDOW(window));
    gtk_widget_show_all (login_win);
    gtk_main ();

    return 0;
}