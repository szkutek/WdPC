//290207
//lista 2
//zadanie 2

#include <stdio.h>
#include <stdlib.h>

int czy_litera(char c);
int czy_cyfra(char c);
int czy_duza(char c);
int czy_mala(char c);
int czy_biala(char c);
int czy_samogl(char c);
int czy_przestank(char c);

int main(void){

    int c, z;

    char tab[10][25] = {{"znakow"},{"liter"},{"cyfr"},
                        {"wyrazow"},{"bialych znakow"},
                        {"samoglosek"},{"spolglosek"},
                        {"duzych liter"},{"malych liter"},
                        {"znakow przestankowych"}};
    int stats[10] = {0};

    if ((c=getchar()) != EOF){
        ;
    }

    while ( (z=getchar()) != EOF || c!=EOF ){
        stats[0]++;

        if (czy_litera(c) && !czy_litera(z)){
            stats[3]++;
        }

        if (czy_duza(c)){
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
        else if (czy_cyfra(c))
            stats[2]++;
        else if (czy_biala(c))
            stats[4]++;
        else if (czy_przestank(c))
            stats[9]++;

        c=z;
    }

    for (int i=0; i<10; i++){
        printf("ilosc %s wynosi %d\n", tab[i], stats[i]);
    }
    return 0;
}


int czy_litera(char c){
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
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
    return c=='e' || c=='y' || c=='u' || c=='i' || c=='o' || c=='a';
}

int czy_przestank(char c){
    return c==',' || c=='.' || c==':' || c=='!' || c=='?';
}
