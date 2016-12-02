#include "saper.h"

int rysuj_plansze(void){
    // first line
    printf(" ");
    for (int i=1; i<ROZMIAR_PLANSZY; i++){
        printf(" %d", i);
    }
//    // next
    int noX=0;
//    int maxX=0, maxO=0;
    puts("");
    for (int i=1; i<=ROZMIAR_PLANSZY; i++){
        printf("%d", i);
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
    int bx[ILOSC_BOMB]={3,2,1,5,3,1,8,5};
    int by[ILOSC_BOMB]={5,7,8,2,4,3,4,1};

    for (int i=0; i<ILOSC_BOMB; i++){
        bomby[ bx[i] ][ by[i] ] = -2;
    }

    for (int j=1; j<=ROZMIAR_PLANSZY; j++){
        for (int k=1; k<=ROZMIAR_PLANSZY; k++){
            if (bomby[j][k] == -2){
                if (bomby[j][k-1]++ != -2){;}
                if (bomby[j][k+1]++ != -2){;}
                if (bomby[j-1][k]++ != -2){;}
                if (bomby[j+1][k]++ != -2){;}
                if (bomby[j+1][k+1]++ != -2){;}
                if (bomby[j-1][k-1]++ != -2){;}
                if (bomby[j-1][k+1]++ != -2){;}
                if (bomby[j+1][k-1]++ != -2){;}
            }
        }

    }
}


int wczytaj_ruch(int *ptrx, int *ptry){
    puts("Podaj wspolrzedne x i y, aby odkryc pole");
    scanf("%d %d", ptrx, ptry);

    while ( *ptrx<=0 || *ptrx>ROZMIAR_PLANSZY || *ptry<=0 || *ptry>ROZMIAR_PLANSZY || bomby[*ptrx][*ptry]==-1 ){
        if (*ptrx==0 && *ptry==0){
            koniec_gry=1;
            return 0;
        }
        puts("Podaj poprawne wspolrzedne lub wpisz '0 0' aby zakonczyc gre");
        scanf("%d %d", ptrx, ptry);
    }
    printf("Twoj ruch to %d %d\n", *ptrx, *ptry);
    return 1;
}

void odkrywajRek(int x, int y){
    // widok_gry[x][y]==0 nieodkryte
    // bomby[x][y]>=0 nie ma bomby

    if ( x>0 && x<=ROZMIAR_PLANSZY && y>0 && y<=ROZMIAR_PLANSZY && widok_gry[x][y]==-1 && bomby[x][y]>=0 ){
        if (bomby[x][y]==-1) {
            odkrywajRek(x+1,y);
            odkrywajRek(x,y+1);
            odkrywajRek(x-1,y);
            odkrywajRek(x,y-1);
        }
        else {
            widok_gry[x][y] = bomby[x][y];
        }
    }
    return ;
}

int wykonaj_ruch(){
    int x=0, y=0;
    if (!wczytaj_ruch(&x,&y)) return 0;

    if (bomby[x][y]==-2){
        koniec_gry=1;
        return 0;
    }

    widok_gry[x][y] = bomby[x][y];

    odkrywajRek(x+1,y);
    odkrywajRek(x,y+1);
    odkrywajRek(x-1,y);
    odkrywajRek(x,y-1);

    return 0;
}

//void zakoncz_gre(void){
//
//}
