//290207
//lista 1
//zadanie 1

#include <stdio.h>
#include <math.h>

int main(void){

    double a, b;
    printf("Podaj a i b:\n");
    scanf("%lf %lf", &a, &b);

    double suma, roznica, iloczyn, iloraz;
    int modulo, a2, b2;
    a2 = round(a);
    b2 = round(b);

    suma = a+b;
    roznica = a-b;
    iloczyn = a*b;

    printf("%g+%g=%.16g\n",a,b,suma);
    printf("%g-%g=%.16g\n",a,b,roznica);
    printf("%g*%g=%.16g\n",a,b,iloczyn);

    if (b==0) {
        printf("Nie dzielimy przez 0!\n");
    }
    else {
        iloraz = a/b;
        modulo = a2%b2;

        printf("%g/%g=%.16g\n",a,b,iloraz);
        printf("%d mod %d=%d\n",a2,b2,modulo);

    }
    return 0;
}
