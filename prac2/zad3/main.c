#include <stdio.h>
#include <math.h>

void rozklad(int n){
    int i = 2; //podstawa
    int k = 0; // wykladnik
    int warunek = (int)sqrt((double)n);

    while (i <= warunek && n!=1){
        while (n%i == 0){
            n = n/i;
            k++;
        }

        if (k!=0){
            printf("%d^%d", i,k);
            if (i<=warunek && n!=1)
                printf("*");
        }

        if (i==warunek && n!=1){
            printf("%d^1", n);
        }
        i++;
        k = 0;
    }

}


int main(void)
{
    int n=0;
    scanf("%d", &n);

    if (n==0) printf("0^1");
    else if (n==1) printf("1^1");
    else if (n>1) rozklad(n);
    printf("\n");

    return 0;
}
