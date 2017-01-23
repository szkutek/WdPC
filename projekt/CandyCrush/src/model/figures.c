#include "model.h"


int is_fig_T(int x, int y){
    int c = candies[x][y].color;
//    HORIZONTAL 5 + 1
    // SPR CZY IN_BOARD !!!
    if (( c==candies[x][y-2].color && c==candies[x][y-1].color
          && c==candies[x][y+1].color && c==candies[x][y+2].color )
        && ( c==candies[x+1][y].color || c==candies[x-1][y].color ) ) {

        if (c == candies[x + 1][y].color)
            candies[x - 1][y].color = 0;
        else
            candies[x + 1][y].color = 0;

        candies[x][y].special = 'T';

        candies[x][y-2] = {0,0};
        candies[x][y-1] = {0,0};
        candies[x][y+1] = {0,0};
        candies[x][y+2] = {0,0};
        return 1;
    }
//    VERTICAL 5 + 1
    if (( c==candies[x-2][y].color && c==candies[x-1][y].color
          && c==candies[x+1][y].color && c==candies[x+2][y].color )
        && ( c==candies[x][y-1].color || c==candies[x][y+1].color ) ){

        if (c == candies[x][y-1].color) {
            candies[x][y + 1].color = 0;
        }
        else {
            candies[x][y - 1].color = 0;
        }

        candies[x][y].special = 'T';

        candies[x-2][y] = {0,0};
        candies[x-1][y] = {0,0};
        candies[x+1][y] = {0,0};
        candies[x+2][y] = {0,0};

        return 1;
    }
    return 0;
}


int is_fig_I(int x, int y){
    int c = candies[x][y].color;
//    HORIZONTAL 5
    if ( c==candies[x][y-2].color && c==candies[x][y-1].color
          && c==candies[x][y+1].color && c==candies[x][y+2].color ){

        candies[x][y].special = 'I';

        candies[x][y-2] = {0,0};
        candies[x][y-1] = {0,0};
        candies[x][y+1] = {0,0};
        candies[x][y+2] = {0,0};

        return 1;
    }
//    VERTICAL 5
    if ( c==candies[x-2][y].color && c==candies[x-1][y].color
          && c==candies[x+1][y].color && c==candies[x+2][y].color ){

        candies[x][y].special = 'I';

        candies[x-2][y] = {0,0};
        candies[x-1][y] = {0,0};
        candies[x+1][y] = {0,0};
        candies[x+2][y] = {0,0};

        return 1;
    }
    return 0;
}

int is_fig_L(int x, int y){
    int c = candies[x][y].color;
////    vertical DOWN
    if ( c==candies[x+1][y].color && c==candies[x+2][y].color ){
        // LEFT
        if (c==candies[x][y-1].color && c==candies[x][y-2].color){
            candies[x][y].special = 'L';
            candies[x+1][y  ] = {0,0};
            candies[x+2][y  ] = {0,0};
            candies[x  ][y-1] = {0,0};
            candies[x  ][y-2] = {0,0};
            return 1;
        }
        else // RIGHT
        if (c==candies[x][y+1].color && c==candies[x][y+2].color){
            candies[x][y].special = 'L';
            candies[x+1][y  ] = {0,0};
            candies[x+2][y  ] = {0,0};
            candies[x  ][y+1] = {0,0};
            candies[x  ][y+2] = {0,0};
            return 1;
        }
        else // PIN UP (T)
        if (c==candies[x][y-1].color && c==candies[x][y+1].color){
            candies[x][y].special = 'L';
            candies[x+1][y  ] = {0,0};
            candies[x+2][y  ] = {0,0};
            candies[x  ][y-1] = {0,0};
            candies[x  ][y+1] = {0,0};
            return 1;
        }
    }
////    vertical UP
    if ( c==candies[x-2][y].color && c==candies[x-1][y].color ){
        // LEFT
        if (c==candies[x][y-1].color && c==candies[x][y-2].color){
            candies[x][y].special = 'L';
            candies[x-1][y  ] = {0,0};
            candies[x-2][y  ] = {0,0};
            candies[x  ][y-1] = {0,0};
            candies[x  ][y-2] = {0,0};
            return 1;
        }
        // RIGHT
        else
        if (c==candies[x][y+1].color && c==candies[x][y+2].color){
            candies[x][y].special = 'L';
            candies[x-1][y  ] = {0,0};
            candies[x-2][y  ] = {0,0};
            candies[x  ][y+1] = {0,0};
            candies[x  ][y+2] = {0,0};
            return 1;
        }
        // PIN
        else
        if (c==candies[x][y-1].color && c==candies[x][y+1].color){
            candies[x][y].special = 'L';
            candies[x-1][y  ] = {0,0};
            candies[x-2][y  ] = {0,0};
            candies[x  ][y-1] = {0,0};
            candies[x  ][y+1] = {0,0};
            return 1;
        }
    }
////    PIN ON SIDE
    if ( c==candies[x-1][y].color && c==candies[x+1][y].color ){
        // LEFT
        if (c==candies[x][y-1].color && c==candies[x][y-2].color){
            candies[x][y].special = 'L';
            candies[x-1][y  ] = {0,0};
            candies[x+1][y  ] = {0,0};
            candies[x  ][y-1] = {0,0};
            candies[x  ][y-2] = {0,0};
            return 1;
        }
        // RIGHT
        else
        if (c==candies[x][y+1].color && c==candies[x][y+2].color){
            candies[x][y].special = 'L';
            candies[x-1][y  ] = {0,0};
            candies[x+1][y  ] = {0,0};
            candies[x  ][y+1] = {0,0};
            candies[x  ][y+2] = {0,0};
            return 1;
        }
    }
    return 0;
}


