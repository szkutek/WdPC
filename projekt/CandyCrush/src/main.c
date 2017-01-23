#include "gui/gui.h"
#include "model/model.h"


int main(int argc, char *argv[]) {

    srand(time(NULL));
    model_main();
//    gtk_init(&argc, &argv);
//    gui_main();

    CandyCount count = {0, 0};
    count = count_candies(0,0);
    printf("%d %d\n", count.x, count.y);

    return 0;
}