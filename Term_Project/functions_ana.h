/*
* This C++ header file contains the functions for a grade calculator program
* 
* CECS 275 - Fall 2025
* @authors Ana Jolynn Arante, Suphia Sidiqi
* @version 1.0.0
*/

#include <gtk/gtk.h>

void end_program (GtkWidget *wid, gpointer ptr)
{
    gtk_main_quit ();
}

// void copy_text (GtkWidget *wid, gpointer ptr)
// {
//     const char *input = gtk_entry_get_text (GTK_ENTRY (txt));
//     gtk_label_set_text (GTK_LABEL (ptr), input);
// }

void user_login (int argc, char *argv[])
{
    GtkWidget *userIn;
    GtkWidget *passIn;

    gtk_init (&argc, &argv);

    GtkWidget *win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    GtkWidget *btn = gtk_button_new_with_label ("Close Window");
    g_signal_connect (btn, "clicked", G_CALLBACK (end_program), NULL);
    g_signal_connect (win, "delete_event", G_CALLBACK (end_program), NULL);

    GtkWidget *user = gtk_label_new ("Enter Username: ");
    GtkWidget *pass = gtk_label_new ("Enter Password: ");
    
    userIn = gtk_entry_new ();
    passIn = gtk_entry_new ();

    GtkWidget *grd = gtk_grid_new ();
    gtk_grid_attach (GTK_GRID (grd), user, 0, 0, 1, 1);
    gtk_grid_attach (GTK_GRID (grd), userIn, 1, 0, 1, 1);
    gtk_grid_attach (GTK_GRID (grd), pass, 0, 1, 1, 1);
    gtk_grid_attach (GTK_GRID (grd), passIn, 1, 1, 1, 1);
    gtk_container_add (GTK_CONTAINER (win), grd);
    gtk_widget_show_all (win);


    //gtk_grid_attach (GTK_GRID (grd), lbl, 0, 0, 1, 1);
    //gtk_grid_attach (GTK_GRID (grd), btn2, 1, 0, 1, 1);
    // gtk_grid_attach (GTK_GRID (grd), btn, 0, 1, 1, 1);
    // //gtk_grid_attach (GTK_GRID (grd), txt, 1, 1, 1, 1);
    // gtk_container_add (GTK_CONTAINER (win), grd);
    // gtk_widget_show_all (win);
    gtk_main ();
    
}