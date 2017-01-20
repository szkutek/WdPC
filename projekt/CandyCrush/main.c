#include "gui.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[]){

    srand(time(NULL));
    gtk_init(&argc, &argv);
    gui_main();

    return 0;
}
