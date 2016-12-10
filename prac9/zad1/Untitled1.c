//// 290207
//// lista 9
//// zad 1
//
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX_N 999999
//
//void rzymska(int n){
//    if (n<1 || n>MAX_N) {
//        printf("Brak reprezentacji\n");
//        return;
//    }
//
//    char num[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M'};
//    //              1    5    10   50  100  500  1000
//
//    int cyfra, reszta;
//    int dzielnik = 1000;
//
//    cyfra   = n/dzielnik;
//    reszta  = n%dzielnik;
//
//    int indeks=6;
//    for (int i = 1; i <= cyfra; i++) printf("M");
//
//    for (indeks=4, dzielnik=1000; indeks>=0; indeks-=2, dzielnik/=10){
//        cyfra   = reszta/(dzielnik/10);
//        reszta  = reszta%(dzielnik);
//
//        if (cyfra < 4)
//            for (int i = 1; i <= cyfra; i++) printf("%c", num[indeks]);
//
//        else if (cyfra == 4)
//            printf("%c%c",num[indeks], num[indeks+1]);
//
//        else if (cyfra > 4 && cyfra < 9){
//            printf("%c", num[indeks+1]);
//            for (int i = 1; i <= cyfra - 5; i++) printf("%c", num[indeks]);
//        }
//        else if (cyfra == 9)
//            printf("%c%c", num[indeks], num[indeks + 2]);
//
//    }
//}
//
//int main(void)
//{
//
////    int n = 0;
////    scanf("%d", &n);
//
//    for (int i=1; i<70; i++){
//        printf("%d -> ", i);
//        rzymska(i);
//        printf("\n");
//
//    }
//    rzymska(100);
//
//
//    return 0;
//}
//
