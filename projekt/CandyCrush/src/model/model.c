
#include "model.h"
#include "../types.h"


int random_candy() {
    return 1 + rand() % (6);
}

void draw_board() {
    printf("  |");
    for (int i = 0; i < HEIGHT; i++) {
        printf(" %d", i);
    }
    puts("");
    for (int i = 0; i < 2 * HEIGHT + 2; i++) {
        printf("-");
    }
    puts("");
    for (int i = 0; i < HEIGHT; i++) {
        printf("%d |", i);
        for (int j = 0; j < WIDTH; j++) {
            printf(" %d", candies[i][j].color);
        }
        puts("");
    }
    puts("");
}

bool in_board(int x, int y) {
    return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT);
}


int read_move(int *ptrx1, int *ptry1, int *ptrx2, int *ptry2) {
    puts("Podaj wspolrzedne (x1,y1) oraz (x2,y2), aby zamienic te cukierki:");
    scanf("%d %d %d %d", ptrx1, ptry1, ptrx2, ptry2);

    while (!in_board(*ptrx1, *ptry1) || !in_board(*ptrx2, *ptry2)) {
        if (*ptrx1 == -1 && *ptry1 == -1) {
//            koniec_gry=1;
            return 0;
        }
        puts("Podaj poprawne wspolrzedne lub wpisz '-1 -1 0 0' aby zakonczyc gre");
        scanf("%d %d %d %d", ptrx1, ptry1, ptrx2, ptry2);
    }
    return 1;
}

int neighbor_candy(int x1, int y1, int x2, int y2) {
    return ((abs(x1 - x2) + abs(y1 - y2) == 1) && in_board(x1, y1) && in_board(x2, y2));
}

char swap_dir(int x1, int y1, int x2, int y2) {
    char dir = 0;
    if (x1 == x2) dir = (y1 < y2) ? ('r') : ('l');
    else if (y1 == y2) dir = (x1 < x2) ? ('d') : ('u');
    return dir;
}

int swap_candy(int x1, int y1, int x2, int y2) { //zmienia cukierki miejscami, jesli sa obok siebie
    int pom_color;
    int pom_special;
    if (neighbor_candy(x1, y1, x2, y2)) {
        pom_color = candies[x1][y1].color;
        candies[x1][y1].color = candies[x2][y2].color;
        candies[x2][y2].color = pom_color;

        pom_special = candies[x1][y1].special;
        candies[x1][y1].special = candies[x2][y2].special;
        candies[x2][y2].special = pom_special;
        return 1;
    } else return 0;
}

void undo_swap(int x1, int y1, int x2, int y2) {
    swap_candy(x2, y2, x1, y1);
}

void clear_counted() {
    for (int i = 0; i < WIDTH; i++) {
        horizontal[i][1] = -1;
        horizontal[i][2] = -1;
    }
    for (int i = 0; i < HEIGHT; i++) {
        vertical[i][1] = -1;
        vertical[i][2] = -1;
    }
}

CandyCount count_candies(int x, int y) {
    clear_counted();
    int c = candies[x][y].color;

    CandyCount count = {0, 0};
    if (c==0) return count;

    int i = x, j = y;

    while (c == candies[i][j].color && i >= 0) {
        vertical[count.x][1] = i;
        vertical[count.x][2] = j;
        count.x++;
        i--;
    }
    i = x + 1;
    while (c == candies[i][j].color && i < HEIGHT) {
        vertical[count.x][1] = i;
        vertical[count.x][2] = j;
        count.x++;
        i++;
    }
    i = x;
    while (c == candies[i][j].color && j >= 0) {
        horizontal[count.y][1] = i;
        horizontal[count.y][2] = j;
        count.y++;
        j--;
    }
    j = y + 1;
    while (c == candies[i][j].color && j < WIDTH) {
        horizontal[count.y][1] = i;
        horizontal[count.y][2] = j;
        count.y++;
        j++;
    }
    return count;
}


int check_one_candy(int x, int y) {

//    CandyCount count = count_candies(x,y);
//    if





    return 0;
}

int check_swap(int x1, int y1, int x2, int y2, bool do_swap) {


    return 1;
}

int make_move(int x1, int y1, int x2, int y2) {
//    int x1=0, y1=0, x2=0, y2=0;
//    if (!read_move(&x1,&y1,&x2,&y2)){
////        koniec_gry=1;
//        return 0;
//    }

//    if (!neighbor_candy(x1,y1,x2,y2)) return 0;
//    int dir = swap_dir(x1,y1,x2,y2);

    if (swap_candy(x1, y1, x2, y2)) {
        if (!check_swap(x1, y1, x2, y2,false)) {
            undo_swap(x1, y1, x2, y2);
            return 0;
        }
    }

    return 0;
}

int model_main() {

    //init board
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            candies[i][j].color = random_candy();
            candies[i][j].special = 0;
        }
    }


//    puts("Candy Crush");
//    while (!koniec_gry) {
//        draw_board();
//        make_move();
//    }
    draw_board();
//    make_move();
//    draw_board();
//    make_move();
//    draw_board();


    return 0;
}
