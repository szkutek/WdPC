
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

int neighbor_candy(Point source, Point dest) {
    return ((abs(source.x - dest.x) + abs(source.y - dest.y) == 1) && in_board(source.x, source.y) &&
            in_board(dest.x, dest.y));
}

int swap_candy(Point source, Point dest) { //zmienia cukierki miejscami, jesli sa obok siebie
    int pom_color;
    int pom_special;
    if (neighbor_candy(source, dest)) {
        pom_color = candies[source.x][source.y].color;
        candies[source.x][source.y].color = candies[dest.x][dest.y].color;
        candies[dest.x][dest.y].color = pom_color;

        pom_special = candies[source.x][source.y].special;
        candies[source.x][source.y].special = candies[dest.x][dest.y].special;
        candies[dest.x][dest.y].special = pom_special;
        return 1;
    } else return 0;
}

void clear_counted() {
    for (int i = 0; i < WIDTH; i++) {
        horizontal[i].x = -1;
        horizontal[i].y = -1;
    }
    for (int i = 0; i < HEIGHT; i++) {
        vertical[i].x = -1;
        vertical[i].y = -1;
    }
}

CandyCount count_candies(Point p) {
    clear_counted();
    int c = candies[p.x][p.y].color;

    CandyCount count = {0, 0};
    if (c == 0) return count;

    int i = p.x, j = p.y;

    while (c == candies[i][p.y].color && i >= 0) {
        vertical[count.x].x = i;
        vertical[count.x].y = p.y;
        count.x++;
        i--;
    }
    i = p.x + 1;
    while (c == candies[i][p.y].color && i < HEIGHT) {
        vertical[count.x].x = i;
        vertical[count.x].y = p.y;
        count.x++;
        i++;
    }

    while (c == candies[p.x][j].color && j >= 0) {
        horizontal[count.y].x = p.x;
        horizontal[count.y].y = j;
        count.y++;
        j--;
    }
    j = p.y + 1;
    while (c == candies[p.x][j].color && j < WIDTH) {
        horizontal[count.y].x = p.x;
        horizontal[count.y].y = j;
        count.y++;
        j++;
    }

    return count;
}

int check_swap(Point source, Point dest, bool do_swap) {
    bool swapable = false;
    CandyCount count;

    swap_candy(source, dest);

    count = count_candies(source);
    if (count.x >= 3 || count.y >= 3)
        swapable = true;
    count = count_candies(dest);
    if (count.x >= 3 || count.y >= 3)
        swapable = true;

    if (swapable && do_swap) {
        update_board(source, dest);
        return true;
    } else if (swapable && !do_swap) {
        swap_candy(source, dest);
        return true;
    } else {
        swap_candy(source, dest);
        return false;
    }
}

int model_main() {

    //init board
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            candies[i][j].color = random_candy();
            candies[i][j].special = 0;
        }
    }

//    while (!koniec_gry) {
//        draw_board();
//        make_move();
//    }
    return 0;
}

void destroy_candy(Point p) {
    if (candies[p.x][p.y].color != 0) {
        score++;
        candies[p.x][p.y].color = 0;
        candies[p.x][p.y].special = 0;

    }
}

void check_one_candy(Point p) {

    CandyCount size;
    int res_color;
    int res_special;


    size = count_candies(p);
    //    VERTICAL
    if (size.x >= 3 && size.y < 3) {
        res_special = 0;
        res_color = candies[p.x][p.y].color;
//        destroy candies
        for (int i = 0; i < size.x; i++)
            destroy_candy(vertical[i]);
    }
        //    HORIZONTAL
    else if (size.x < 3 && size.y >= 3) {
        res_special = 0;
        res_color = candies[p.x][p.y].color;
//        destroy candies
        for (int i = 0; i < size.y; i++)
            destroy_candy(horizontal[i]);
    }


    for (int i = 0; i < size.x; i++)
        printf("[%d, %d], ", vertical[i].x, vertical[i].y);
    puts("");
    for (int i = 0; i < size.y; i++)
        printf("[%d, %d], ", horizontal[i].x, horizontal[i].y);
    puts("");
    puts("");

}

int update_board(Point source, Point dest) {


    check_one_candy(source);
    check_one_candy(dest);
    fill_voids();

}

void fill_voids() {


    for (int j = 0; j < WIDTH; j++) {

        for (int i = 0; i < HEIGHT; i++) {
            if (candies[i][j].color == 0) {

                for (int k = i; k > 0; k++) {
                    candies[k][j].color = candies[k - 1][j].color;
                }
                candies[0][j].color = random_candy();
                candies[0][j].special = 0;
            }
        }
    }


}

