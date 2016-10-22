//290207
//lista 2
//zadanie 2

#include <stdio.h>
#include <stdlib.h>


int czy_cyfra(char c);
int czy_duza(char c);
int czy_mala(char c);
int czy_biala(char c);
int czy_samogl(char c);
int czy_przestank(char c);
int pozostale(int c);


int main(void){
    int c;
    //int c, z;
    //int i = 0;

    //char tab[10][25] = {{"znakow"},{"liter"},{"cyfr"},{"wyrazow"},{"bialych znakow"},
    //                    {"samoglosek"},{"spolglosek"},{"duzych liter"},{"malych liter"},
    //                    {"znakow przestankowych"}};
    int stats[10] = {0};
/*
    if ((c=getchar()) != EOF){
        ;
    }

    while ( (z=getchar()) != EOF || c!=EOF ) {
        */
    while ( (c=getchar()) != EOF ) {
        if (czy_cyfra(c))
            stats[2]++;
        else if (czy_duza(c)){
            stats[7]++;
            stats[1]++;
            if (czy_samogl(c-'A'+'a')) stats[5]++;
            else stats[6]++;
        }
        else if (czy_mala(c)){
            stats[8]++;
            stats[1]++;
            if (czy_samogl(c)) stats[5]++;
            else stats[6]++;
        }
        else if (czy_biala(c))
            stats[4]++;
        else if (czy_przestank(c))
            stats[9]++;

/*
        if (c!=z){
            if (i==0){
                c = pozostale(c);
                putchar(c);
            }
            else {
                putchar('\n');
                i=0;
            }
        }
        else i++;
*/
        stats[0]++;
        //c=z;

    }

    printf("Koniec\n");

    //for (i=0; i<10; i++){
      //  printf("ilosc %s wynosi %d\n", tab[i], stats[i]);
    //}

    return 0;
}

int czy_cyfra(char c){
    return (c >= '0' && c <= '9');
}

int czy_duza(char c){
    return (c >= 'A' && c <= 'Z');
}

int czy_mala(char c){
    return (c >= 'a' && c <= 'z');
}

int czy_biala(char c){
    return c==' ' || c=='\n' || c=='\t';
}

int czy_samogl(char c){
    return c=='e' || c=='y' || c=='u' || c=='i' || c=='o' || c=='a'; //6
}

int czy_przestank(char c){
    return c==',' || c=='.' || c==':' || c=='!' || c=='?';
}

int pozostale(int c){
    if (c >= 'A' && c <= 'Z')
            c=c-'A'+'a';
        else if (c >= 'a' && c <= 'z')
            c=c-'a'+'A';
        else if (c == ' ')
            c='!';
    return c;
}
