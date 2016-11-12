//290207
//lista 5
//zadanie 2

#include <stdio.h>
#include <math.h>

int main(void){

    double a=0, b=0, c=0;
    double delta=0, sqrt_delta=0;
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a==0 && b==0) puts("brak");
    else if (a==0)    printf("%g\n", -c/b);
    else {
        delta = b*b-4*a*c;
        if (delta<0)
            puts("brak");
        else if (delta==0)
            printf("%g\n", -b/(2*a));
        else {
            sqrt_delta = sqrt((double)delta);
            printf("%g, %g\n", (-b-sqrt_delta)/(2*a), (-b+sqrt_delta)/(2*a));
        }
    }

    return 0;
}
