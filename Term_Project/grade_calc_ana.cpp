#include <gtk/gtk.h>
#include "functions.h"

int main (int argc, char *argv[])
{
    gtk_init (&argc, &argv);
    GtkBuilder *builder = gtk_builder_new_from_file ("mylayout.glade");

    GtkWidget *win = (GtkWidget *) gtk_builder_get_object (builder, "window1");
    GtkWidget *btn1 = (GtkWidget *) gtk_builder_get_object (builder, "button1");
    GtkWidget *btn2 = (GtkWidget *) gtk_builder_get_object (builder, "button2");
    GtkWidget *btn3 = (GtkWidget *) gtk_builder_get_object (builder, "button3");
    
    g_signal_connect (btn1, "clicked", G_CALLBACK (user_login), NULL); // Button 1 does nothing for now but should be used to log in
    g_signal_connect (btn2, "clicked", G_CALLBACK (end_program), NULL); // Button 2 does nothing for now but should be used to register a new user
    g_signal_connect (btn3, "clicked", G_CALLBACK (end_program), NULL); // Button 3 does nothing for now but should be used to end the program -- close window
    gtk_widget_show_all (win);
    gtk_main ();

    return 0;
}