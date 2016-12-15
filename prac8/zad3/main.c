#include <stdio.h>
#include <stdlib.h>

#define MAXN 1024
#define MAXLOGN 10

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


        tmp->wartosc = -1;

        return tmp;
    }

    wezel->wartosc = tab_wartosci[i_pocz][j_pocz];
    wezel->A = NULL;
    wezel->B = NULL;
    wezel->C = NULL;
    wezel->D = NULL;


    return wezel;
}


void usun(KWADRAT *wezel){
    if (wezel->A!=NULL){
        usun(wezel->A);
        usun(wezel->B);
        usun(wezel->C);
        usun(wezel->D);
    }
    free(wezel);
}

void wypisz_tab(int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++) printf("%d", tab_wartosci[i][j]);
        printf("\n");
    }
}

void rotacja(KWADRAT *wezel, char slowo[], int i){ // *ABC
    if (slowo[i+1]==0){
        KWADRAT *tmp;
        tmp = wezel->A;

        wezel->A = wezel->D;
        wezel->D = wezel->C;
        wezel->C = wezel->B;
        wezel->B = tmp;

    }
    else
        switch (slowo[i]){
            case 'A':
                rotacja(wezel->A, slowo, i+1);
                break;
            case 'B':
                rotacja(wezel->B, slowo, i+1);
                break;
            case 'C':
                rotacja(wezel->C, slowo, i+1);
                break;
            case 'D':
                rotacja(wezel->D, slowo, i+1);
                break;
    }
}

void negacja(KWADRAT *wezel, char slowo[], int i){ // -ABC
    if (wezel->A == NULL){
        if      (wezel->wartosc == 0) wezel->wartosc = 1;
        else if (wezel->wartosc == 1) wezel->wartosc = 0;
    }
    else {
        switch (slowo[i]){
            case 'A':
                negacja(wezel->A, slowo, i+1);
                break;
            case 'B':
                negacja(wezel->B, slowo, i+1);
                break;
            case 'C':
                negacja(wezel->C, slowo, i+1);
                break;
            case 'D':
                negacja(wezel->D, slowo, i+1);
                break;
        }
    }
}

void zero(KWADRAT *wezel, char slowo[], int i){ // 0ABC
    if (wezel->A == NULL) wezel->wartosc = 0;
    else {
        switch (slowo[i]){
        case 'A':
            zero(wezel->A, slowo, i+1);
            break;
        case 'B':
            zero(wezel->B, slowo, i+1);
            break;
        case 'C':
            zero(wezel->C, slowo, i+1);
            break;
        case 'D':
            zero(wezel->D, slowo, i+1);
            break;
        }
    }
}

void jeden(KWADRAT *wezel, char slowo[], int i){ // 1ABC
    if (wezel->A == NULL) wezel->wartosc = 1;
    else {
        switch (slowo[i]){
        case 'A':
            jeden(wezel->A, slowo, i+1);
            break;
        case 'B':
            jeden(wezel->B, slowo, i+1);
            break;
        case 'C':
            jeden(wezel->C, slowo, i+1);
            break;
        case 'D':
            jeden(wezel->D, slowo, i+1);
            break;
        }
    }
}








void wykonaj_instr(KWADRAT *wezel, char slowo[]){
    switch (slowo[0]){
    case '*':
        rotacja(wezel, slowo, 1);
        break;
    case '-':
        negacja(wezel, slowo, 1);
        break;
    case '0':
        zero(wezel, slowo, 1);
        break;
    case '1':
        jeden(wezel, slowo, 1);
        break;
//    case '=':
//        roznorodnosc(wezel, slowo, 1);
//        break;
//    case '#':
//        szachownice(wezel, slowo, 1);
//        break;
//    }

}



int czy_mala(char c){
    return c>='a' && c<='z';
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

    // STWORZ DRZEWO
    obrazek = wstaw(obrazek, 0, n-1, 0, n-1);


    char slowo[MAXLOGN+2]={0};
    int s=0;
    while ( c != '.'){
        // CZYTAJ INSTRUKCJE
        while ((c=getchar()) != '\n'){
            slowo[s] = (czy_mala(c)) ? c+'A'-'a': c;
            s++;
        }
        // WYKONAJ OPERACJE
        wykonaj_instr(obrazek, slowo);

        // WYCZYSC slowo i s
        for (int i=0; i<=MAXLOGN; i++) slowo[i]=0;
        s=0;
    }



    return 0;
}
