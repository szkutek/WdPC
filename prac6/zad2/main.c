#include <stdio.h>
#include <stdlib.h>

#define ROZMIAR_PLANSZY 2
#define ILOSC_BOMB 2

int koniec_gry=0;
int bomba=0;

int bomby[ROZMIAR_PLANSZY+2][ROZMIAR_PLANSZY+2]={{0}};
int widok_gry[ROZMIAR_PLANSZY+2][ROZMIAR_PLANSZY+2]={{0}};

int rysuj_plansze(void);
void losuj_bomby(void);
int wczytaj_ruch(int *ptrx, int *ptry);
void odkrywajRek(int x, int y);
int wykonaj_ruch(void);


int main(void){
    int pozostale = ROZMIAR_PLANSZY*ROZMIAR_PLANSZY - ILOSC_BOMB;
    losuj_bomby();

    while (!koniec_gry){
        pozostale = rysuj_plansze();
        if (pozostale){
            printf("Pozostalo %d niezaminowanych pol.\n", pozostale);
            wykonaj_ruch();
        }
        else{
            koniec_gry=1;
            puts("WYGRALES");
        }
    }
    if (bomba){
        pozostale = rysuj_plansze();
        puts("PRZEGRALES");
    }

    return 0;
}


int rysuj_plansze(void){
    // first line
    printf(" ");
    for (int i=1; i<=ROZMIAR_PLANSZY; i++){
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
    int bx[ILOSC_BOMB]={2,1};
    int by[ILOSC_BOMB]={2,1};

    for (int i=0; i<ILOSC_BOMB; i++){
        bomby[ bx[i] ][ by[i] ] = -2;
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
    // widok_gry[x][y]==-1 nieodkryte
    // bomby[x][y]!=0 nie ma bomby

    if ( x>0 && x<=ROZMIAR_PLANSZY && y>0 && y<=ROZMIAR_PLANSZY && widok_gry[x][y]==-1 && bomby[x][y]!=-2){
        widok_gry[x][y] = bomby[x][y];

        if (widok_gry[x][y]==-1) {
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

    widok_gry[x][y] = bomby[x][y];

    if (widok_gry[x][y]==-2){
        koniec_gry=1;
        bomba=1;
        return 0;
    }

    if (widok_gry[x][y]==0){
        odkrywajRek(x+1,y);
        odkrywajRek(x,y+1);
        odkrywajRek(x-1,y);
        odkrywajRek(x,y-1);
        odkrywajRek(x-1,y+1);
        odkrywajRek(x-1,y-1);
        odkrywajRek(x+1,y-1);
        odkrywajRek(x+1,y+1);
    }

    return 0;
}
