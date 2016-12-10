// 290207
// lista 9
// zad 1

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 999999

void rzymska(int n, int indeks){
    char num[] = { 'I', 'V', 'X', 'L', 'C', 'D',  'M'};

    if (indeks==6)
		for (int i = 1; i <= n; i++) printf("%c", num[indeks]);

    else if (n < 4)
        for (int i = 1; i <= n; i++) printf("%c", num[indeks]);

    else if (n == 4)
        printf("%c%c",num[indeks], num[indeks+1]);

	else if (n > 4 && n < 9){
        printf("%c", num[indeks+1]);
        for (int i = 1; i <= n - 5; i++) printf("%c", num[indeks]);
    }
	else if (n == 9)
		printf("%c%c", num[indeks], num[indeks + 2]);
}

void drukuj(int n){
    if (n<1 || n>MAX_N) printf("Brak reprezentacji");
    else {
        rzymska( n/1000         , 6); // tys.
        rzymska((n % 1000) / 100, 4); // setki
        rzymska((n % 100) / 10  , 2); // dzies.
        rzymska((n % 10)        , 0); // jednosci
    }
}

int main(void)
{

    int n = 0;
    scanf("%d", &n);
    printf("%d -> ", n);
    drukuj(n);
    printf("\n");

//    for (int i=0; i<55; i++){
//        printf("%d -> ", i);
//        drukuj(i);
//        printf("\n");
//    }
//    for (int i=100; i<1700; i+=100){
//        printf("%d -> ", i);
//        drukuj(i);
//        printf("\n");
//    }

    return 0;
}
