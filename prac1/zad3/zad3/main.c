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
            m += 2;
        }
        else
            m++;

    }

    wynik(found, p, q);

    return 0;
}
