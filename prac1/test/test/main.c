#include <stdio.h>
#include <limits.h>
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

int suma_dzielnikow(int n){
    int m = n;
    long long int sum = 1;
    int part_sum = 1;
    int i = 2;
    int k = 0;
    int warunek = sqrt(n);
    int potega_k = 1;
    int iloczyn = 1;
    //printf("i\t\t n\t\t part_sum\t\t sum\n" ); //

    while (i <= warunek && n!=1 && sum>0 && sum <= INT_MAX){
        while (n%i == 0){
            n = n/i;
            //printf("%d\t\t", i); //
            //printf("%d\t\t", n); //
            k++;
            potega_k = potega(i,k);
            part_sum = part_sum + potega_k;
            //printf("x%d\n", part_sum); //
        }

        if (k!=0){
            iloczyn = iloczyn * potega_k;
            sum = sum * part_sum;
            part_sum = 1;
            //printf("BIG SUM = %lld\t\n", sum); //
        }

        if (i == warunek && n!=1 && k == 0 && m%iloczyn ==0){
            part_sum = part_sum + m/iloczyn;
            sum = sum * part_sum;
            part_sum = 1;
        }

        i++;
        k = 0;
    }
/*
    printf("FOR N = %d\t", m); //
    printf("SUM = %d\t", sum); //
    printf("SUM-N = %d\n\n", sum-m); //
    */
    return (sum - m);
}

/*
int suma_dzielnikow(int n){
    long int sum = 1;
    int i = 2;
    int sqrt_n = sqrt(n);
    while (i <= sqrt_n && sum>0 && sum+i <= INT_MAX){
        if (n%i == 0){
            if (i != m/i) sum += i + m/i;
            else sum += i;
        }
        i++;
    }
    return sum;
}
*/
int obfita(int n){
    if (suma_dzielnikow(n) > n) return 1;
    else return 0;
}

int main(void){

    printf("%I64u\n", suma_dzielnikow(12));
    printf("%I64u\n", suma_dzielnikow(18));
    printf("%I64u\n", suma_dzielnikow(49));
    printf("%I64u\n", suma_dzielnikow(153));
    printf("%I64u\n", suma_dzielnikow(1002));
    printf("%I64u\n", suma_dzielnikow(2147483000));
    printf("%I64u\n", suma_dzielnikow(2147483022));
    printf("%I64u\n", suma_dzielnikow(2147483647));
/*
    int n=0;
    scanf("%d", &n);
    printf("%d", suma_dzielnikow(n));
    //printf("%d", sizeof(long long int));
*/
    return 0;
}
