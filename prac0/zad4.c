#include <stdio.h>

int potega(int x, int n){
    int pot = 1;
    for (int i=0; i<n; i++){
        pot = pot * x;
    }
    return pot;
}

int main(void){
    int dana=0, n=0;
    scanf("%d", &dana);

    int dana2=dana;
    while (dana2>0){
        dana2=dana2/10;
        n++;
    }

    int dana3=dana, suma=0;
    while (dana3>0){
        suma = suma + potega(dana3%10,n);
        dana3=dana3/10;
    }

    if (dana==suma) printf("TAK\n");
    else printf("NIE\n");

    return 0;
}
