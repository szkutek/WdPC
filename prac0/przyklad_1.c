#include <stdio.h>

/* wypisz zestawienie stanu konta, jesli kwote 10 tys. zl.
   wlozylismy na lokate 10 letnia oprocentowana 5% rocznie
   i procenty sa dopisywane co kwartal. */

int main(void) // wersja zmiennoprzecinkowa
{
    int lata, okresow_w_roku;
    float procent, kwota_pocz, kwota2;
    int kwota;
    int rok, okres;

    kwota_pocz=10000;     /* kwota lokaty */
    lata=10;              /* liczba lat lokaty */
    okresow_w_roku=4;     /* liczba okresow w roku */
    procent=0.05;         /* oprocentowanie roczne */

    kwota=(int)(kwota_pocz*100.0f);
    kwota2=kwota_pocz;
    rok=1;
    printf("ROK:\t | \t KWOTA (na int): | \t KWOTA (na float) :\n");
    while (rok <= lata) {
        okres=1;
        while (okres <= okresow_w_roku) {
            kwota=kwota*(1.0+procent/okresow_w_roku);
            kwota2=kwota2*(1.0+procent/okresow_w_roku);
            okres=okres+1;
        }
        printf("%d \t | \t %9.2f \t | \t %9.2f\n",rok,(float)kwota*0.01f,kwota2);
        rok=rok+1;
    }
    return 0;
}
