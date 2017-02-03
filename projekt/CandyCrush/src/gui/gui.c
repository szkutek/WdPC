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

    yellow_bomb.alpha = 1.0;
    yellow_bomb.red = 1.0;
    yellow_bomb.green = 1.0;
    yellow_bomb.blue = 0.0;

    red_bomb.alpha = 1.0;
    red_bomb.red = 1.0;
    red_bomb.green = 0.0;
    red_bomb.blue = 0.0;

    blue_bomb.alpha = 1.0;
    blue_bomb.red = 0.0;
    blue_bomb.green = 0.0;
    blue_bomb.blue = 1.0;

    green_bomb.alpha = 1.0;
    green_bomb.red = 0.0;
    green_bomb.green = 204.0 / 255.0;
    green_bomb.blue = 0.0;

    purple_bomb.alpha = 1.0;
    purple_bomb.red = 204.0 / 255.0;
    purple_bomb.green = 0.0;
    purple_bomb.blue = 102.0 / 255.0;

    orange_bomb.alpha = 1.0;
    orange_bomb.red = 1.0;
    orange_bomb.green = 128.0 / 255.0;
    orange_bomb.blue = 0.0;

    color_bomb.alpha = 1.0;
    color_bomb.red = 0.0;
    color_bomb.green = 0.0;
    color_bomb.blue = 0.0;

    yellow.alpha = 0.5;
    yellow.red = 255.0 / 255.0;
    yellow.green = 255.0 / 255.0;
    yellow.blue = 153.0 / 255.0;

    red.alpha = 0.5;
    red.red = 255.0 / 255.0;
    red.green = 102.0 / 255.0;
    red.blue = 102.0 / 255.0;

    blue.alpha = 0.5;
    blue.red = 102.0 / 255.0;
    blue.green = 102.0 / 255.0;
    blue.blue = 153.0 / 255.0;

    green.alpha = 0.5;
    green.red = 102.0 / 255.0;
    green.green = 255.0 / 255.0;
    green.blue = 102.0 / 255.0;

    purple.alpha = 0.1;
    purple.red = 255.0 / 255.0;
    purple.green = 102.0 / 255.0;
    purple.blue = 178.0 / 255.0;

    orange.alpha = 0.5;
    orange.red = 255.0 / 255.0;
    orange.green = 178.0 / 255.0;
    orange.blue = 102.0 / 255.0;

}

GdkRGBA normal_bomb(Candy candy) {
    switch (candy.color) {
        case 0:
            return blank;
        case 1:
            return yellow_bomb;
        case 2:
            return red_bomb;
        case 3:
            return green_bomb;
        case 4:
            return blue_bomb;
        case 5:
            return purple_bomb;
        case 6:
            return orange_bomb;
    }
}

GdkRGBA get_color(Candy candy) {
    if (candy.special == 5)
        return color_bomb;
    if (candy.special == 3)
        return normal_bomb(candy);

    switch (candy.color) {
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
            color = get_color(candies[i][j]);
            gtk_color_chooser_set_rgba(GTK_COLOR_CHOOSER(board_buttons[i][j]), &color);
        }
    }
}

void change_labels() {
    char str[7];

    sprintf(str, "%d", player_moves);
    gtk_entry_set_text(GTK_ENTRY(time_count), str);

    sprintf(str, "%d", score);
    gtk_entry_set_text(GTK_ENTRY(score_show), str);
}

void button_clicked(GtkWidget *widget, GdkEvent *event, gpointer data) {
    Point *point = (Point *) data;

    if (firstButton == NULL) {
        firstButton = (GtkButton *) widget;
        firstPoint.x = point->x;
        firstPoint.y = point->y;
    } else if (firstButton != NULL && secondButton == NULL && (GtkButton *) widget != firstButton) {
        secondButton = (GtkButton *) widget;
        secondPoint.x = point->x;
        secondPoint.y = point->y;

        if (player_moves > 0) {
            check_swap(firstPoint, secondPoint, true);
            firstButton = NULL;
            secondButton = NULL;
        }
        if (player_moves == 0) {
            change_labels();
            end_game();
        }
    }
    change_labels();
    gint64 timer = g_timeout_add(500, (GSourceFunc) redraw, NULL);
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

            board_buttons[i][j] = gtk_color_button_new();

            GdkRGBA color = get_color(candies[i][j]);
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

    time_lbl = gtk_label_new("MOVES LEFT");
    score_lbl = gtk_label_new("SCORE");

    char str[7];
    sprintf(str, "%d", MOVES_ALLOWED);

    time_count = gtk_entry_new();
    gtk_editable_set_editable(GTK_EDITABLE(time_count), FALSE);
    gtk_entry_set_text(GTK_ENTRY(time_count), str);
    score_show = gtk_entry_new();
    gtk_editable_set_editable(GTK_EDITABLE(score_show), FALSE);
    gtk_entry_set_text(GTK_ENTRY(score_show), "0");

    gtk_box_pack_start(GTK_BOX(menu), time_lbl, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(menu), time_count, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(menu), score_lbl, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(menu), score_show, TRUE, TRUE, 0);

    g_signal_connect(main_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    redraw();
    gtk_widget_show_all(main_window);
    gtk_main();

    return 0;
}

void end_game() {
    dialog = gtk_dialog_new_with_buttons("Game over",
                                         GTK_WINDOW(main_window),
                                         GTK_DIALOG_DESTROY_WITH_PARENT,
                                         "Play again",
                                         GTK_RESPONSE_NONE, NULL);


    gtk_widget_set_size_request(dialog, 200, 100);
    g_signal_connect_swapped(dialog, "response", G_CALLBACK(gtk_widget_destroy), dialog);
    gtk_widget_show_all(dialog);
    gtk_dialog_run(GTK_DIALOG(dialog));
    restart();
    redraw();
    change_labels();
}