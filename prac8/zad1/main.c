// 290207
// lista 8
// zad 1


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N_MAX_LEN 100

int strlenMY(char *txt){ //} – iloœæ znaków
    char *tmp=txt;
    int n=0;
    while (*tmp){
        tmp++;
        n++;
    }
    return n;
}

bool palindrom(int n, char *txt){ // – czy tekst jest palindromem
    char *pocz;
    char *koniec;
    for (pocz=txt, koniec=txt+n-1; pocz<txt+n/2; pocz++, koniec--){
        if (*pocz != *koniec) return false;
    }
    return true;
}

char *scanMY(int nMaxLen, char *tekst){ // – wczytuje ci¹g znaków z konsoli do tablicy (nie wiêcej ni¿ nMaxLen)
    int c;
    int i=0;
    char *tmp = tekst;
    while ( (c=getchar())!='\n' && i<nMaxLen){
        *tmp = c;
        tmp++;
        i++;
    }
    *tmp='\0';
    return tekst;
}

char *strncpyMY(char *s, char *t, int n){ // - kopiowanie co najwy¿ej n znaków tekstu t do s.
    char *stmp, *tmp;
    for (stmp=s, tmp=t; tmp<t+n; stmp++, tmp++){
        *stmp = *tmp;
    }
    *stmp='\0';
    return s;
}

char *strncatMY(char *s, char *t,int n){ // - dopisywanie co najwy¿ej n znaków tekstu t na koñcu tekstu s.
    int len_s = strlenMY(s);
    return strncpyMY(s + len_s, t, n) - len_s;
}

int strncmpMY(char *s,char *t,int n){ // - porównywanie tekstu t z tekstem s przy uwzglêdnieniu co najwy¿ej n znaków.
    int len_s = strlenMY(s);
    int len_t = strlenMY(t);

    if ( (len_s != len_t) &&  (n>len_s || n>len_t) ) return 0;

    if (n > len_s) n = len_s;

    char *stmp, *tmp;
    for (stmp=s, tmp=t; stmp<s+n; stmp++, tmp++){
        if (*stmp != *tmp)
            return 0;
    }

    return 1;
}

char *strchrMY(char *string, char c){ //- zwraca wskaźnik na ostatnie wystąpienie litery c
 // w tekście wskazywanym przez string. Jeśli litera nie występuje zwracany jest NULL
    char *p = NULL;
    while(*string){
        if (*string==c) p=string;
        string++;
    }
    return p;
}

void wypisz(char *string, int n){ //
    char *tmp=string;
    for (int i=0; (int)i<n; tmp++, i++){
        printf("%c", *tmp);
    }
    puts("");
}

int main(void){

    int nMaxLen=N_MAX_LEN;
//    puts("Podaj maksymalna dlugosc tekstu");
//    scanf("%d", &nMaxLen);

    char *wczytany_tekst, *tekst;
    wczytany_tekst = (char *)malloc((nMaxLen+1) * sizeof(char));
    wczytany_tekst = scanMY(nMaxLen, wczytany_tekst);

    // alokuj tylko tyle pamieci ile potrzeba
    int n = strlenMY(wczytany_tekst);
    tekst = (char *)malloc((n+1) * sizeof(char));
    tekst = strncpyMY(tekst, wczytany_tekst, n);
    free(wczytany_tekst);
    //
    printf("\nIlosc wczytanych znakow: %d\n", n);
    //
    printf("Wypisz tekst:\n");
    wypisz(tekst, n);


// OSTATNIE WYSTAPIENIE ZNAKU W TEKSCIE
    char c='2';
    char *ost_wyst = strchrMY(tekst,c);
    printf("Wskaznik na ostatnie wystapienie '%c': %p\n", c, ost_wyst);


// PALINDROM
    printf("Czy palindrom: %d\n", palindrom(n,tekst));


// KOPIUJ TEKST
    char *kopia;
    int ile_kopiuj=5;

    ile_kopiuj = (ile_kopiuj>n) ? n : ile_kopiuj;
    printf("\nWypisz skopiowane %d znakow:\n", ile_kopiuj);

    kopia = (char *)malloc((ile_kopiuj+1) * sizeof(char));
    kopia = strncpyMY(kopia, tekst, ile_kopiuj);
    wypisz(kopia, ile_kopiuj);


// DOPISZ TEKST

    char *co_dopisac = "ABC";
    int ile_dopisac = strlenMY(co_dopisac);

    // dopisz do tekstu
    char *dopisane;
    dopisane = (char *)malloc((n + ile_dopisac +1) * sizeof(char));
    dopisane = strncpyMY(dopisane, tekst, strlenMY(tekst));
    dopisane = strncatMY(dopisane, co_dopisac, ile_dopisac);
    int d = strlenMY(dopisane);

    tekst = (char *)malloc((d+1) * sizeof(char));
    tekst = strncpyMY(tekst, dopisane, d);
    free(dopisane);

    printf("\nWypisz tekst z dopisanymi znakami (%d):\n", d);
    wypisz(tekst, d);


// POROWNAJ
    int por = 5;
    printf("\nPorownaj kopie z tekstem z dopisanymi znakami do dlugosci %d:\n", por);
    printf("Czy sa takie same: %d\n", strncmpMY(kopia, tekst, por));




    free(tekst);
    free(kopia);
    free(co_dopisac);

    return 0;
}
