#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int potega(int x, int n){
    if (n == 0) return 1;
    else if (n == 1) return x;
    else {
        int pot = x;
        for (int i=0; i<n-1; i++){
            pot = pot * x;
        }
        return pot;
    }
}

void rozklad(int n){
    int m = n;
    int i = 2; //podstawa
    int k = 0; // wykladnik
    int warunek = (int)sqrt((double)n);
    int iloczyn = 1;

    while (i <= warunek && n!=1){
        while (n%i == 0){
            n = n/i;
            k++;
            iloczyn *= i;
        }

        if (k!=0){
            printf("%d^%d", i,k);
            if (i<=warunek && n!=1)
                printf("*");
        }

        if (i==warunek && n!=1 && m%iloczyn==0){
            printf("%d^1", m/iloczyn);
        }
        i++;
        k = 0;
    }

}


int main(void)
{
    int n=0;
    scanf("%d", &n);


    if (n==0) printf("0^1\n");
    else if (n==1) printf("1^1\n");
    else {
        rozklad(n);
        printf("\n");
    }

    return 0;
}
