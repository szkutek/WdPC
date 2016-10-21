#include <stdio.h>

int main(void)
{
    int lata, okresow_w_roku;
    float procent;
    int kwota;
    int rok, okres;
    float kwota_pocz;

    printf("Podaj kwote poczatkowa w zlotowkach:\n");
    scanf("%f", &kwota_pocz);
    printf("Podaj oprocentowanie:\n");
    scanf("%f", &procent);
    printf("Podaj liczbe lat:\n");
    scanf("%d", &lata);
    printf("Podaj liczbe okresow:\n");
    scanf("%d", &okresow_w_roku);

    //kwota_pocz=10000;     /* kwota lokaty */
    //lata=10;              /* liczba lat lokaty */
    //okresow_w_roku=4;     /* liczba okresow w roku */
    //procent=0.05;         /* oprocentowanie roczne */

    kwota=(int)(kwota_pocz*100.0f); rok=1;
    printf("ROK:\t | \t KWOTA:\n");
    while (rok <= lata) {
        okres=1;
        while (okres <= okresow_w_roku) {
            kwota=kwota*(1.0+procent/okresow_w_roku*0.81);
            okres=okres+1;
        }
        printf("%d \t | \t %9.2f \n",rok,(float)kwota*0.01f);
        rok=rok+1;
    }
    return 0;
}
