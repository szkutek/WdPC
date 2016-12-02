//290207
//lista 6
//zadanie 2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROZMIAR_PLANSZY 8
#define ILOSC_BOMB 6

// TODO pokazac rozmieszczenie wszystkich bomb na koniec

int koniec_gry=0;
int bomba=0;

int bomby[ROZMIAR_PLANSZY+2][ROZMIAR_PLANSZY+2]={{0}};
int widok_gry[ROZMIAR_PLANSZY+2][ROZMIAR_PLANSZY+2]={{0}};

int rysuj_plansze(void);
void losuj_bomby(void);
int wczytaj_ruch(int *ptrx, int *ptry);
void odkrywajRek(int x, int y);
int wykonaj_ruch(void);
void rysuj_bomby(void);


int main(void){
    srand(time(NULL));
    int pozostale = ROZMIAR_PLANSZY*ROZMIAR_PLANSZY - ILOSC_BOMB;
    losuj_bomby();
    //puts("WIDOK BOMB");
    //rysuj_bomby();

    puts("SAPER");
    while (!koniec_gry){
        pozostale = rysuj_plansze();
        if (pozostale){
            printf("Pozostalo %d niezaminowanych pol.\n", pozostale);
            wykonaj_ruch();
        }
        else{
            koniec_gry=1;
            puts(" *** WYGRALES *** ");
        }
    }
    if (bomba){
        // TODO odkryj wszystkie bomby
        pozostale = rysuj_plansze();
        puts(" :( PRZEGRALES :( ");
    }

    return 0;
}


int rysuj_plansze(void){
    // first line
    printf("  |");
    for (int i=1; i<=ROZMIAR_PLANSZY; i++){
        printf(" %d", i);
    }
    puts("");
    for (int i=0; i<=2*ROZMIAR_PLANSZY+2; i++){
        printf("-");
    }
    puts("");
    int noX=0;
    for (int i=1; i<=ROZMIAR_PLANSZY; i++){
        printf("%d |", i);
        for (int k=1; k<=ROZMIAR_PLANSZY; k++){
            switch (widok_gry[i][k]){
            case 0:
                printf(" %c", '.');
                break;
            case -1:
                printf(" %c", 'X');
                noX++;
                break;
            case -2:
                printf(" %c", '*');
                break;
            default:
                printf(" %d", widok_gry[i][k]);
                break;
            }
        }
        puts("");
    }
    puts("");

    return noX-ILOSC_BOMB;
}

void losuj_bomby(void){
    int bx=0, by=0;
    int i=0;
    while (i<ILOSC_BOMB){
        bx = 1+rand()%ROZMIAR_PLANSZY;
        by = 1+rand()%ROZMIAR_PLANSZY;
        if (bomby[bx][by] != -2){
            bomby[bx][by] = -2;
            i++;
        }
    }

    for (int j=1; j<=ROZMIAR_PLANSZY; j++){
        for (int k=1; k<=ROZMIAR_PLANSZY; k++){
            if (bomby[j][k] == -2){
                if (bomby[j][k-1] != -2){bomby[j][k-1]++;}
                if (bomby[j][k+1] != -2){bomby[j][k+1]++;}
                if (bomby[j-1][k] != -2){bomby[j-1][k]++;}
                if (bomby[j+1][k] != -2){bomby[j+1][k]++;}
                if (bomby[j+1][k+1] != -2){bomby[j+1][k+1]++;}
                if (bomby[j-1][k-1] != -2){bomby[j-1][k-1]++;}
                if (bomby[j-1][k+1] != -2){bomby[j-1][k+1]++;}
                if (bomby[j+1][k-1] != -2){bomby[j+1][k-1]++;}
            }
            widok_gry[j][k]=-1;
        }

    }
}

int wczytaj_ruch(int *ptrx, int *ptry){
    puts("Podaj wspolrzedne x i y, aby odkryc pole");
    scanf("%d %d", ptrx, ptry);

    while ( *ptrx<=0 || *ptrx>ROZMIAR_PLANSZY || *ptry<=0 || *ptry>ROZMIAR_PLANSZY || widok_gry[*ptrx][*ptry]!=-1 ){
        if (*ptrx==0 && *ptry==0){
            koniec_gry=1;
            return 0;
        }
        puts("Podaj poprawne wspolrzedne lub wpisz '0 0' aby zakonczyc gre");
        scanf("%d %d", ptrx, ptry);
    }
    return 1;
}

void odkrywajRek(int x, int y){
    // widok_gry[x][y]==-1 - nieodkryte
    // widok_gry[x][y]==0 - puste

    if ( x>0 && x<=ROZMIAR_PLANSZY && y>0 && y<=ROZMIAR_PLANSZY && widok_gry[x][y]==-1 ){
        widok_gry[x][y] = bomby[x][y];

        if (widok_gry[x][y]==0) {
            odkrywajRek(x+1,y);
            odkrywajRek(x,y+1);
            odkrywajRek(x-1,y);
            odkrywajRek(x,y-1);
            odkrywajRek(x-1,y+1);
            odkrywajRek(x-1,y-1);
            odkrywajRek(x+1,y-1);
            odkrywajRek(x+1,y+1);
        }
    }
    return ;
}

int wykonaj_ruch(void){
    int x=0, y=0;
    if (!wczytaj_ruch(&x,&y)) return 0;

    if (bomby[x][y]==-2){
        widok_gry[x][y] = bomby[x][y];
        koniec_gry=1;
        bomba=1;
        return 0;
    }

    if (bomby[x][y]==0){
        odkrywajRek(x,y);
    }
    else
        widok_gry[x][y] = bomby[x][y];

    return 0;
}


void rysuj_bomby(void){
    // first line
    printf("  |");
    for (int i=1; i<=ROZMIAR_PLANSZY; i++){
        printf(" %d", i);
    }
    puts("");
    for (int i=0; i<=2*ROZMIAR_PLANSZY+2; i++){
        printf("-");
    }
    puts("");
    for (int i=1; i<=ROZMIAR_PLANSZY; i++){
        printf("%d |", i);
        for (int k=1; k<=ROZMIAR_PLANSZY; k++){
            switch (bomby[i][k]){
            case 0:
                printf(" %c", '.');
                break;
            case -2:
                printf(" %c", '*');
                break;
            default:
                printf(" %d", bomby[i][k]);
                break;
            }
        }
        puts("");
    }
    puts("");
}
