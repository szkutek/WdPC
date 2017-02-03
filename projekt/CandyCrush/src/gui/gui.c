#include "gui.h"
#include "../types.h"


//void create_board(GtkWidget *widget){
//}
GtkButton *firstButton = NULL;
Point firstPoint;
GtkButton *secondButton = NULL;
Point secondPoint;


void init_colors() {
    blank.alpha = 1.0;
    blank.red = 0.933333;
    blank.green = 0.933333;
    blank.blue = 0.925490;

    yellow.alpha = 1.0;
    yellow.red = 1.0;
    yellow.green = 1.0;
    yellow.blue = 0.0;

    red.alpha = 1.0;
    red.red = 1.0;
    red.green = 0.0;
    red.blue = 0.0;

    blue.alpha = 1.0;
    blue.red = 0.0;
    blue.green = 0.0;
    blue.blue = 1.0;

    green.alpha = 1.0;
    green.red = 0.0;
    green.green = 1.0;
    green.blue = 0.0;

    purple.alpha = 1.0;
    purple.red = 204.0 / 255.0;
    purple.green = 0.0;
    purple.blue = 102.0 / 255.0;

    orange.alpha = 1.0;
    orange.red = 1.0;
    orange.green = 128.0 / 255.0;
    orange.blue = 0.0;

}

GdkRGBA get_color(int x) {
    switch (x) {
        case 0:
            return blank;
        case 1:
            return yellow;
        case 2:
            return red;
        case 3:
            return green;
        case 4:
            return blue;
        case 5:
            return purple;
        case 6:
            return orange;
    }
}


void redraw() {
    GdkRGBA color;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {

//            char str[7];
//            sprintf(str, "%d", candies[i][j].color);
//            gtk_button_set_label(board_buttons[i][j], str);
            color = get_color(candies[i][j].color);
            gtk_color_chooser_set_rgba(GTK_COLOR_CHOOSER(board_buttons[i][j]), &color);
        }
    }
}


void button_clicked(GtkWidget *widget, GdkEvent *event, gpointer data) {
    Point *point = (Point *) data;

    if (firstButton == NULL) {
        firstButton = (GtkButton *) widget;
        firstPoint.x = point->x;
        firstPoint.y = point->y;
    } else if (firstButton != NULL && secondButton == NULL) {
        if ((GtkButton *) widget == firstButton) {
            firstButton = NULL;
        } else {
            secondButton = (GtkButton *) widget;
            secondPoint.x = point->x;
            secondPoint.y = point->y;

            if (player_moves > 0) {
                check_swap(firstPoint, secondPoint, true);
                firstButton = NULL;
                secondButton = NULL;
            }
            if (player_moves == 0) {
//                end_game();
                puts("Game ended");
            }
        }
    }
    gint64 timer = g_timeout_add(500, (GSourceFunc) redraw, NULL);
//    gtk_button_set_label((GtkButton)widget, "C");
//    gtk_button_set_label(widget, "C");
//    GdkRGBA col = {1, 0, 0, 0};
//    gtk_widget_override_background_color(widget, GTK_STATE_PRELIGHT, &col);

}

int init_gui(void) {

    init_colors();

    main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_position(GTK_WINDOW(main_window), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(main_window), "Candy Crush");
    gtk_container_set_border_width(GTK_CONTAINER(main_window), 5);

    main_hbox = gtk_hbox_new(FALSE, 1);
    gtk_container_add(GTK_CONTAINER(main_window), main_hbox);

    /** BOARD
    */
    board = gtk_table_new(HEIGHT, WIDTH, true);
    gtk_table_set_row_spacings(GTK_TABLE(board), 0);
    gtk_table_set_col_spacings(GTK_TABLE(board), 0);

    gtk_container_add(GTK_CONTAINER(main_hbox), board);

    gint button_size = 50;

    Point points[HEIGHT][WIDTH];

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {

            points[i][j].x = i;
            points[i][j].y = j;

//            char str[7];
//            sprintf(str, "%d", candies[i][j]);
//            board_buttons[i][j] = gtk_color_button_new();

            board_buttons[i][j] = gtk_color_button_new();

            GdkRGBA color = get_color(candies[i][j].color);
            gtk_color_chooser_set_rgba(GTK_COLOR_CHOOSER(board_buttons[i][j]), &color);

            g_signal_connect(G_OBJECT(board_buttons[i][j]), "button_press_event",
                             G_CALLBACK(button_clicked), (gpointer) &points[i][j]);

            gtk_table_attach_defaults(GTK_TABLE(board), board_buttons[i][j], j, j + 1, i, i + 1);

            gtk_widget_set_size_request(board_buttons[i][j], button_size, button_size);
        }
    }




    /** MENU
    */

    menu = gtk_vbox_new(FALSE, 1);
    gtk_container_add(GTK_CONTAINER(main_hbox), menu);

    time_lbl = gtk_label_new("TIME");
    lives_lbl = gtk_label_new("LIVES");
    score_lbl = gtk_label_new("SCORE");

    time_count = gtk_label_new("TIME");
    lives = gtk_label_new("LIVES");
    score_show = gtk_label_new("SCORE");

    gtk_box_pack_start(GTK_BOX(menu), time_lbl, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(menu), time_count, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(menu), lives_lbl, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(menu), lives, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(menu), score_lbl, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(menu), score_show, TRUE, TRUE, 0);


    g_signal_connect(main_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    redraw();
    gtk_widget_show_all(main_window);
    gtk_main();

    return 0;
}


void show_play_again_dialog(GtkWidget *widget, gpointer window) {

    GtkWidget *dialog;
    dialog = gtk_message_dialog_new(GTK_WINDOW(window),
                                    GTK_DIALOG_DESTROY_WITH_PARENT,
                                    GTK_MESSAGE_QUESTION,
                                    GTK_BUTTONS_YES_NO,
                                    "Play again?");
    gtk_window_set_title(GTK_WINDOW(dialog), "You scored some points.");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

void play_again_fun() {
    play_again = true;
}

void end_game() {
    GtkWidget *dialog;
    dialog = gtk_message_dialog_new(GTK_WINDOW(main_window),
                                    GTK_DIALOG_DESTROY_WITH_PARENT,
                                    GTK_MESSAGE_QUESTION,
                                    GTK_BUTTONS_YES_NO,
                                    "Play again?");
    gtk_window_set_title(GTK_WINDOW(dialog), "You scored some points.");
    gtk_dialog_run(GTK_DIALOG(dialog));

//    gtk_widget_destroy(dialog);

    g_signal_connect(dialog, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_dialog_response(GTK_DIALOG(play_again_fun), GTK_RESPONSE_OK);
}