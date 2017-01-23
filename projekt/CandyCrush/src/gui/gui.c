#include "gui.h"
#include "../types.h"


//void create_board(GtkWidget *widget){
//}
GtkButton *firstButton = NULL;
Point firstPoint;
GtkButton *secondButton = NULL;
Point secondPoint;


void redraw() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {

            char str[7];
            sprintf(str, "%d", candies[i][j].color);
            gtk_button_set_label(board_buttons[i][j], str);
        }
    }
}


void button_clicked(GtkWidget *widget, gpointer data) {
    Point *point = (Point *) data;
    printf("[%d, %d]\n", point->x, point->y);

    if (firstButton == NULL) {
        firstButton = widget;
        firstPoint.x = point->x;
        firstPoint.y = point->y;
    } else if (firstButton != NULL && secondButton == NULL && widget != firstButton) {
        secondButton = widget;
        secondPoint.x = point->x;
        secondPoint.y = point->y;

        make_move(firstPoint.x, firstPoint.y, secondPoint.x, secondPoint.y);
        firstButton = NULL;
        secondButton = NULL;
    }
    redraw();
//    gtk_button_set_label((GtkButton)widget, "C");
//    gtk_button_set_label(widget, "C");
//    GdkRGBA col = {1, 0, 0, 0};
//    gtk_widget_override_background_color(widget, GTK_STATE_PRELIGHT, &col);

}

//int random_candy() {
//    return 1 + rand() % (6);
//}


int gui_main(void) {

    main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_position(GTK_WINDOW(main_window), GTK_WIN_POS_CENTER);
//    gtk_window_set_default_size(GTK_WINDOW(main_window), 230, 250);
    gtk_window_set_title(GTK_WINDOW(main_window), "Candy Crush");
    gtk_container_set_border_width(GTK_CONTAINER(main_window), 5);

    main_hbox = gtk_hbox_new(FALSE, 1);
    gtk_container_add(GTK_CONTAINER(main_window), main_hbox);



    /** BOARD
    */

    board = gtk_table_new(HEIGHT, WIDTH, TRUE);
    gtk_table_set_row_spacings(GTK_TABLE(board), 0);
    gtk_table_set_col_spacings(GTK_TABLE(board), 0);

    gtk_container_add(GTK_CONTAINER(main_hbox), board);

    gint size = 50;
//
//    int candy[HEIGHT][WIDTH] = {{0}};
//    for (int i = 0; i < HEIGHT; i++) {
//        for (int j = 0; j < WIDTH; j++) {
//            candy[i][j] = random_candy();
//
//        }
//    }

//    GdkRGBA color;
//    color.red=127;
//    color.green=22;
//    color.blue=230;
//    color.alpha=1.0;

    Point points[WIDTH][HEIGHT];

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {

            points[i][j].x = i;
            points[i][j].y = j;

            char str[7];
            sprintf(str, "%d", candies[i][j]);

//            board_buttons[i][j] = gtk_color_button_new();
//            gtk_color_chooser_set_rgba(GTK_COLOR_CHOOSER(board_buttons[i][j]), &color);

            board_buttons[i][j] = gtk_button_new_with_label(str);
            gtk_table_attach_defaults(GTK_TABLE(board), board_buttons[i][j], j, j + 1, i, i + 1);

            g_signal_connect(G_OBJECT(board_buttons[i][j]), "clicked",
                             G_CALLBACK(button_clicked), (gpointer) &points[i][j]);

            gtk_widget_set_size_request(board_buttons[i][j], size, size);
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
    score = gtk_label_new("SCORE");

    gtk_box_pack_start(GTK_BOX(menu), time_lbl, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(menu), time_count, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(menu), lives_lbl, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(menu), lives, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(menu), score_lbl, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(menu), score, TRUE, TRUE, 0);


    g_signal_connect(main_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    redraw();
    gtk_widget_show_all(main_window);
    gtk_main();

    return 0;
}
