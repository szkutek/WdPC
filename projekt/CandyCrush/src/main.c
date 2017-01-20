#include "gui/gui.h"
#include "model/model.h"


int main(int argc, char *argv[]) {

    srand(time(NULL));
//    gtk_init(&argc, &argv);
//    gui_main();
    model_main();

    return 0;
}