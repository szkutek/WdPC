#include "gui/gui.h"

int main(int argc, char *argv[]) {

    srand(time(NULL));

    init_board();
    gtk_init(&argc, &argv);
    init_gui();


    return 0;
}