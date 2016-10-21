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

long long int suma_dzielnikow(int n){
    int n2 = n;
    long long int sum = 1;
    int part_sum = 1;
    int i = 2;
    int k = 0;
    int warunek = sqrt(n);
    int potega_k = 1;
    int iloczyn = 1;

    while (i <= warunek && n!=1 && sum>0 && sum <= INT_MAX){
        while (n%i == 0){
            n = n/i;
            k++;
            potega_k = potega(i,k);
            part_sum = part_sum + potega_k;
        }

        if (k!=0){
            iloczyn = iloczyn * potega_k;
            sum = sum * part_sum;
            part_sum = 1;
        }

        if (i == warunek && n!=1 && k == 0 && n2%iloczyn ==0){
            part_sum = part_sum + n2/iloczyn;
            sum = sum * part_sum;
            part_sum = 1;
        }

        i++;
        k = 0;
    }
    return (sum - n2);
}
/*
long long int suma_dzielnikow(int n){
    long long int sum = 1;
    int i = 2;
    int warunek = sqrt(n);

    while (i <= warunek && n>1 && sum>0 && sum <= INT_MAX){
        if (n%i == 0){
            if (i != n/i) sum += i + n/i;
            else sum += i;
        }
        i++;
    }
    return (sum);
}
*/

int obfita(int n){
    if (suma_dzielnikow(n) > n) return 1;
    else return 0;
}

void wynik(int found, int p, int q){
    if (found == 2){
        printf("%d %d\n", p, q);
    }
    else if (found == 0){
        printf("BRAK BRAK\n");
    }
    else {
        if (p == 0) printf("BRAK %d\n", q);
        else printf("%d BRAK\n", p);
    }
}

int main(void){

    int m = 0;
    scanf("%d", &m);

    int found = 0;
    int p = 0, q = 0;

    m++;
    while (found<2 && m<=INT_MAX && m>=0){
        if (m%2 == 0){
            if (p == 0 && obfita(m)){
                p = m;
                found++;
            }
        }
        else if (q == 0 && obfita(m)){
            q = m;
            found++;
        }

        if (p!=0 && m%2!=0) {
            m = m + 2;
        }
        else
            m++;

    }

    wynik(found, p, q);

    return 0;
}
