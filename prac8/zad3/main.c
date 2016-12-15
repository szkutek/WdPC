#include <stdio.h>
#include <stdlib.h>

#define MAXN 1024

int tab_wartosci[MAXN][MAXN]={{0}};

typedef struct kwadrat{
    struct kwadrat *A;
    struct kwadrat *B;
    struct kwadrat *C;
    struct kwadrat *D;
    int wartosc;

} KWADRAT;

KWADRAT *wstaw(KWADRAT *wezel, int i_pocz, int i_kon, int j_pocz, int j_kon){

    if (i_kon-i_pocz>1){

        KWADRAT *tmp;
        tmp = (KWADRAT *)malloc(sizeof(KWADRAT));

        tmp->A = wstaw(tmp,               i_pocz, (i_pocz+i_kon)/2,               j_pocz, (j_pocz+j_kon)/2);
        tmp->B = wstaw(tmp,               i_pocz, (i_pocz+i_kon)/2, (j_pocz+j_kon)/2 + 1,            j_kon);
        tmp->C = wstaw(tmp, (i_pocz+i_kon)/2 + 1,            i_kon,               j_pocz, (j_pocz+j_kon)/2);
        tmp->D = wstaw(tmp, (i_pocz+i_kon)/2 + 1,            i_kon, (j_pocz+j_kon)/2 + 1,            j_kon);

        return tmp;
    }

    wezel->wartosc = tab_wartosci[i_pocz][j_pocz];

    return wezel;
}

void wypisz_tab(KWADRAT *obrazek){



}

int main(void){

    int n;
    KWADRAT *obrazek=NULL;

    // WCZYTAJ P1
    int c;
    for (int i=0; i<3; i++) c=getchar();

    // WCZYTAJ N
    scanf("%d ", &n);
    scanf("%d ", &n);

    // WCZYTAJ OBRAZEK
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            c = getchar();
            tab_wartosci[i][j] = c - '0';
        }
        c=getchar();
    }


    // STWORZ DRZEWO (?)
    obrazek = wstaw(obrazek, 0, n-1, 0, n-1);

    // WYPISZ





    // CZYTAJ INSTRUKCJE
//    while ( (c=getchar()) != '.'){
//
//    }



    return 0;
}
