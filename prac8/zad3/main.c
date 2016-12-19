#include <stdio.h>
#include <stdlib.h>

#define MAXN 1024
#define MAXLOGN 10
#define MAXQUEST 1000

int tab_wartosci[MAXN][MAXN]={{0}};

typedef struct kwadrat{
    struct kwadrat *A;
    struct kwadrat *B;
    struct kwadrat *C;
    struct kwadrat *D;
    int wartosc;

} KWADRAT;

KWADRAT *wstaw(int i_pocz, int i_kon, int j_pocz, int j_kon){

    KWADRAT *tmp;
    tmp = (KWADRAT *)malloc(sizeof(KWADRAT));

    if (i_kon==i_pocz){
        tmp->wartosc = tab_wartosci[i_pocz][j_pocz];
        tmp->A = NULL;
        tmp->B = NULL;
        tmp->C = NULL;
        tmp->D = NULL;
        return tmp;
    }
    else { //if (i_kon-i_pocz>1){
    tmp->wartosc = -1;

    tmp->A = wstaw(               i_pocz, (i_pocz+i_kon)/2,               j_pocz, (j_pocz+j_kon)/2);
    tmp->B = wstaw(               i_pocz, (i_pocz+i_kon)/2, (j_pocz+j_kon)/2 + 1,            j_kon);
    tmp->C = wstaw( (i_pocz+i_kon)/2 + 1,            i_kon, (j_pocz+j_kon)/2 + 1,            j_kon);
    tmp->D = wstaw( (i_pocz+i_kon)/2 + 1,            i_kon,               j_pocz, (j_pocz+j_kon)/2);


    return tmp;

    }
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
    if (slowo[i]==0){
        if (wezel->A == NULL){
            if      (wezel->wartosc == 0) wezel->wartosc = 1;
            else if (wezel->wartosc == 1) wezel->wartosc = 0;
        }
        else {
            negacja(wezel->A, slowo, i);
            negacja(wezel->B, slowo, i);
            negacja(wezel->C, slowo, i);
            negacja(wezel->D, slowo, i);
        }
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
    if (slowo[i]==0){
        if (wezel->A == NULL) wezel->wartosc = 0;
        else {
            zero(wezel->A, slowo, i);
            zero(wezel->B, slowo, i);
            zero(wezel->C, slowo, i);
            zero(wezel->D, slowo, i);
        }
    }
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
    if (slowo[i]==0){
        if (wezel->A == NULL) wezel->wartosc = 1;
        else {
            jeden(wezel->A, slowo, i);
            jeden(wezel->B, slowo, i);
            jeden(wezel->C, slowo, i);
            jeden(wezel->D, slowo, i);
        }
    }
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

int roznorodnosc(KWADRAT *wezel, char slowo[], int i){ // =ABC
    // 0 gdy same 0 (roznorodnosc = 1)
    // 1 gdy same 1 (roznorodnosc = 1)
    // k gdy rozne (roznorodnosc = k)

    int res=0;

    if (slowo[i]==0){
        if (wezel->A==NULL) return wezel->wartosc;

        else {
            int resA=0, resB=0, resC=0, resD=0;
            resA = roznorodnosc(wezel->A, slowo, i);
            resB = roznorodnosc(wezel->B, slowo, i);
            resC = roznorodnosc(wezel->C, slowo, i);
            resD = roznorodnosc(wezel->D, slowo, i);

            if      ( resA==0 && resB==0 && resC==0 && resD==0 ) return 0;
            else if ( resA==1 && resB==1 && resC==1 && resD==1 ) return 1;
            else {
                resA = (resA==0) ? 1 : resA;
                resB = (resB==0) ? 1 : resB;
                resC = (resC==0) ? 1 : resC;
                resD = (resD==0) ? 1 : resD;

                return resA+resB+resC+resD;
            }

        }
    }
    else
        switch (slowo[i]){
        case 'A':
            res = roznorodnosc(wezel->A, slowo, i+1);
            break;
        case 'B':
            res = roznorodnosc(wezel->B, slowo, i+1);
            break;
        case 'C':
            res = roznorodnosc(wezel->C, slowo, i+1);
            break;
        case 'D':
            res = roznorodnosc(wezel->D, slowo, i+1);
            break;
    }
    return res;
}



int szachownice(KWADRAT *wezel, char slowo[], int i){ // =ABC
    // -2 gdy 0, -1 gdy 1, 1 gdy szachownica, 0, gdy brak szach.

    int res=0;

    if (slowo[i]==0){
        if (wezel->A==NULL) return (wezel->wartosc==1) ? -1 : -2;

        else {
            int resA=0, resB=0, resC=0, resD=0;
            resA = szachownice(wezel->A, slowo, i);
            resB = szachownice(wezel->B, slowo, i);
            resC = szachownice(wezel->C, slowo, i);
            resD = szachownice(wezel->D, slowo, i);

            if      ( resA==1 && resB==1 && resC==1 && resD==1 ) return -1;
            else if ( resA==0 && resB==0 && resC==0 && resD==0 ) return -2;

            else if ( (resA==-2 && resB==-1 && resA==resC && resB==resD)
                    ||(resA==-1 && resB==-2 && resA==resC && resB==resD)) return 1;

            else {
                resA = (resA<0) ? 0 : resA;
                resB = (resB<0) ? 0 : resB;
                resC = (resC<0) ? 0 : resC;
                resD = (resD<0) ? 0 : resD;

                return resA+resB+resC+resD;
            }

        }
    }
    else
        switch (slowo[i]){
        case 'A':
            res = szachownice(wezel->A, slowo, i+1);
            break;
        case 'B':
            res = szachownice(wezel->B, slowo, i+1);
            break;
        case 'C':
            res = szachownice(wezel->C, slowo, i+1);
            break;
        case 'D':
            res = szachownice(wezel->D, slowo, i+1);
            break;
    }
    return res;
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
    case '=':
        printf("%d\n", roznorodnosc(wezel, slowo, 1));
        break;
    case '#':
        printf("%d\n", szachownice(wezel, slowo, 1));
        break;
    }

}


void wypisz_fragm(KWADRAT *wezel, char slowo[], int i){
    if (wezel->A == NULL){
        printf("%d ", wezel->wartosc);
    }
    else {
        switch (slowo[i]){
            case 'A':
                wypisz_fragm(wezel->A, slowo, i+1);
                break;
            case 'B':
                wypisz_fragm(wezel->B, slowo, i+1);
                break;
            case 'C':
                wypisz_fragm(wezel->C, slowo, i+1);
                break;
            case 'D':
                wypisz_fragm(wezel->D, slowo, i+1);
                break;
            case '\0':
                wypisz_fragm(wezel->A, slowo, i+1);
                wypisz_fragm(wezel->B, slowo, i+1);
                wypisz_fragm(wezel->C, slowo, i+1);
                wypisz_fragm(wezel->D, slowo, i+1);
                break;
        }
    }

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
    obrazek = wstaw(0, n-1, 0, n-1);
    //wypisz_fragm(obrazek, "2A", 1); puts("");


    char slowo[MAXLOGN+2]={0};
    int s=0;
    while ( c != '.'){
        // CZYTAJ INSTRUKCJE
        while ((c=getchar()) != '\n'){
            if (c=='.') break;
            slowo[s] = (czy_mala(c)) ? c+'A'-'a': c;
            s++;
        }

        // WYKONAJ OPERACJE
        wykonaj_instr(obrazek, slowo);
        wypisz_fragm(obrazek, "2A", 1); puts("");

        // WYCZYSC slowo i s
        for (int i=0; i<=MAXLOGN; i++) slowo[i]=0;
        s=0;
    }


    usun(obrazek);
    return 0;
}
