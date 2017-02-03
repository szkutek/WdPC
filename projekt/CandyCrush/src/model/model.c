
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
    return (x >= 0 && x < HEIGHT && y >= 0 && y < WIDTH);
}

int neighbor_candy(Point source, Point dest) {
    return ((abs(source.x - dest.x) + abs(source.y - dest.y) == 1) && in_board(source.x, source.y) &&
            in_board(dest.x, dest.y));
}

bool swap_candy(Point source, Point dest) { //swaps candy if next to each other
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
    } else
        return 0;
}

CandyCount count_candies(Point p) {

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
        player_moves--;
        return true;
    } else if (swapable && !do_swap) {
        swap_candy(source, dest); // undo swap
        return true;
    } else {
        swap_candy(source, dest); // undo swap
        return false;
    }
}

int init_board() {

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            candies[i][j].color = random_candy();
            candies[i][j].special = 0;
        }
    }

    flag = true;
    while (flag) {
        flag = false;
        check_board();
        fill_voids();
    }

    return 0;
}

void destroy_candy(Point p) {
    Point pom;

    if (candies[p.x][p.y].special == 5) {
        int pom_color = random_candy();
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (candies[i][j].color == pom_color) {
                    pom.x = i;
                    pom.y = j;
                    destroy_candy(pom);
                }
            }
        }
    } else if (candies[p.x][p.y].special == 3) {
        candies[p.x][p.y].special = 0;
        for (int k = -1; k <= 1; k++)
            for (int l = -1; l <= 1; l++) {
                pom.x = p.x + k;
                pom.y = p.y + l;
                if (in_board(pom.x, pom.y))
                    destroy_candy(pom);
            }
    } else if (candies[p.x][p.y].color != 0) {
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

        if (size.x == 4) {
            res_special = 3;
            score += 2;
        } else if (size.x >= 5) {
            res_special = 3;
            score += 5;
        }

//        destroy candies
        for (int i = 0; i < size.x; i++)
            destroy_candy(vertical[i]);

        if (size.x >= 4) {
            candies[p.x][p.y].color = res_color;
            candies[p.x][p.y].special = res_special;
        }
    }
//    HORIZONTAL
    else if (size.x < 3 && size.y >= 3) {
        res_special = 0;
        res_color = candies[p.x][p.y].color;

        if (size.y == 4) {
            res_special = 3;
            score += 2;
        } else if (size.y >= 5) {
            res_special = 3;
            score += 5;
        }

//        destroy candies
        for (int i = 0; i < size.y; i++)
            destroy_candy(horizontal[i]);

        if (size.y >= 4) {
            candies[p.x][p.y].color = res_color;
            candies[p.x][p.y].special = res_special;
        }
    }
//    BOMB
    else if (size.x >= 3 && size.y >= 3) {
        res_special = 3;
        res_color = candies[p.x][p.y].color;
        score += 3;

//        destroy candies
        for (int i = 0; i < size.x; i++)
            destroy_candy(vertical[i]);
        for (int i = 0; i < size.y; i++)
            destroy_candy(horizontal[i]);

        candies[p.x][p.y].color = res_color;
        candies[p.x][p.y].special = res_special;

    }
}

int update_board(Point source, Point dest) {

    check_one_candy(source);
    fill_voids();
    check_one_candy(dest);
    fill_voids();

    flag = true;
    while (flag) {
        flag = false;
        check_board();
        fill_voids();
    }
}

void fill_voids() {
    for (int j = 0; j < WIDTH; j++) {

        for (int i = 0; i < HEIGHT; i++) {
            if (candies[i][j].color == 0) {

                for (int k = i; k > 0; k--) {
                    candies[k][j].color = candies[k - 1][j].color;
                }
                candies[0][j].color = random_candy();
                candies[0][j].special = 0;

                flag = true;
            }
        }
    }


}

void check_board() {
    Point p;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            p.x = i;
            p.y = j;
            check_one_candy(p);
        }
    }
}

