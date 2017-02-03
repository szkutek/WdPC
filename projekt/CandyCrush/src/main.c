#include "gui/gui.h"
#include "model/model.h"


int main(int argc, char *argv[]) {

    srand(time(NULL));

    score = 0;
    player_moves = MOVES_ALLOWED;

    init_board();
    gtk_init(&argc, &argv);
    init_gui();


    return 0;
}