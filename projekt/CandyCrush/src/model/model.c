#include "model.h"

int koniec_gry=0;
int candy[HEIGHT][WIDTH] = {{0}};


int random_candy(){
    return 1 + rand() % (6);
}

void draw_board(){
    printf("  |");
    for (int i=0; i<HEIGHT; i++){
        printf(" %d", i);
    }
    puts("");
    for (int i=0; i<2*HEIGHT+2; i++){
        printf("-");
    }
    puts("");
    for (int i=0; i<HEIGHT; i++){
        printf("%d |", i);
        for (int j=0; j<WIDTH; j++){
            printf(" %d", candy[i][j]);
        }
        puts("");
    }
    puts("");
}


int read_move(int *ptrx, int *ptry, int *dir){
    puts("Podaj wspolrzedne x i y oraz kierunek (2 4 6 8), aby zamienic cukierki");
    scanf("%d %d %d", ptrx, ptry, dir);

    while ( *ptrx<0 || *ptrx>=WIDTH || *ptry<0 || *ptry>=HEIGHT){
        if (*ptrx==-1 && *ptry==-1){
            koniec_gry=1;
            return 0;
        }
        puts("Podaj poprawne wspolrzedne lub wpisz '0 0' aby zakonczyc gre");
        scanf("%d %d %d", ptrx, ptry, dir);
    }
    return 1;
}

int switch_candy(int x, int y, int dir) {
    int pom;
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        switch (dir) {
            case 2:
                if (x == HEIGHT - 1) return 0;
                pom = candy[x][y];
                candy[x][y] = candy[x + 1][y];
                candy[x + 1][y] = pom;
                break;
            case 8:
                if (x == 0) return 0;
                pom = candy[x][y];
                candy[x][y] = candy[x - 1][y];
                candy[x + 1][y] = pom;
                break;
            case 4:
                if (y == 0) return 0;
                pom = candy[x][y];
                candy[x][y] = candy[x][y - 1];
                candy[x + 1][y] = pom;
                break;
            case 6:
                if (y == WIDTH - 1) return 0;
                pom = candy[x][y];
                candy[x][y] = candy[x][y + 1];
                candy[x + 1][y] = pom;
                break;
        }
    }
    return 1;
}

int check_rec(int x, int y, int dir){



}

int check_move(int x, int y, int dir){
    int pom;

    check_rec(x+1,y,dir);

    return 1;
}

int make_move(void){
    int x=0, y=0, dir=0;
    if (!read_move(&x,&y,&dir)) return 0;

    if (switch_candy(x,y,dir)) {
        if (!check_move(x,y,dir))
            undo_switch(x, y, dir);
    }

    return 0;
}

int model_main() {


    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            candy[i][j] = random_candy();
        }
    }
    draw_board();
    make_move();

//    puts("Candy Crush");
//    while (!koniec_gry) {
//        draw_board();
//    }

    return 0;
}
