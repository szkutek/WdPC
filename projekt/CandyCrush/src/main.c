#include "gui/gui.h"
#include "model/model.h"


int main(int argc, char *argv[]) {

    score = 0;
    srand(time(NULL));
    model_main();
    gtk_init(&argc, &argv);
    gui_main();


    return 0;
}