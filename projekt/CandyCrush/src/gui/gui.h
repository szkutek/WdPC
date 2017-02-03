
#ifndef GUI_H
#define GUI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

#include "../types.h"
#include "../model/model.h"

bool play_again;

void redraw();

void button_clicked(GtkWidget *widget, GdkEvent *event, gpointer data);

int init_gui();


GtkWidget *main_window;
GtkWidget *main_hbox;
GtkWidget *menu;
GtkWidget *board;
GtkWidget *board_buttons[HEIGHT][WIDTH];
GtkWidget *time_lbl;

GtkWidget *time_count;
GtkWidget *lives_lbl;
GtkWidget *lives;
GtkWidget *score_lbl;
GtkWidget *score_show;

GdkRGBA blank;
GdkRGBA yellow;
GdkRGBA red;
GdkRGBA blue;
GdkRGBA green;
GdkRGBA purple;
GdkRGBA orange;

void end_game();

GtkWidget *dialog_window;
GtkWidget *play_again_dialog;

void show_play_again_dialog(GtkWidget *widget, gpointer window);

#endif
