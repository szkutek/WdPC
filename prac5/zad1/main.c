//290207
//lista 5
//zadanie 1

#include <stdio.h>
#include <stdlib.h>

int czy_trojkat(float t[]){
    return t[0]+t[1]>t[2] && t[0]+t[2]>t[1] && t[1]+t[2]>t[0];
}

int czy_prostokatny(float t[]){
    return t[0]*t[0]+t[1]*t[1]==t[2]*t[2] || t[0]*t[0]+t[2]*t[2]==t[1]*t[1] || t[1]*t[1]+t[2]*t[2]==t[0]*t[0];
}

int czy_rownoboczny(float t[]){
    return t[0]==t[1] && t[1]==t[2];
}

int czy_rownoramienny(float t[]){
    return t[0]==t[1] || t[0]==t[2] || t[1]==t[2];
}


int main(void){

    float t[3]={0};
    char a='N', b='N', c='N', d='N';
    scanf("%f %f %f", &t[0], &t[1], &t[2]);

    if (czy_trojkat(t)){
        a='T';
        if (czy_prostokatny(t)) b='T';
        if (czy_rownoboczny(t)) c='T';
        if (czy_rownoramienny(t)) d='T';
    }

    printf("Czy mozna z tych bokow zbudowac trojkat:\n");
    printf("a) jakikolwiek: %c\n", a);
    printf("b) prostokatny: %c\n", b);
    printf("c) rownoboczny: %c\n", c);
    printf("d) rownoramienny: %c\n", d);

    return 0;
}
