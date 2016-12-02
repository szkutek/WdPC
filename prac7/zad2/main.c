// 290207
// lista 7
// zadanie 2

#include <stdio.h>
#include <stdlib.h>

struct ulamek{
    int l;
    int m;
} ulamek;

int nwd(int n, int m){
    int k=0;
    if (n<m){
        k = m; m = n; n = k;
    }
    while (m!=0) {
        k = n % m;
        n = m;
        m = k;
    }
    return n;
}

struct ulamek utworz(int licznik, int mianownik){
    ulamek.l = licznik;
    ulamek.m = mianownik;
    return ulamek;
}

struct ulamek suma(struct ulamek a, struct ulamek b){
    ulamek.l = a.l * b.m + b.l * a.m;
    ulamek.m = a.m * b.m;
    return ulamek;
}

struct ulamek roznica(struct ulamek a, struct ulamek b){
    ulamek.l = a.l * b.m - b.l * a.m;
    ulamek.m = a.m * b.m;
    return ulamek;
}

struct ulamek iloczyn(struct ulamek a, struct ulamek b){
    ulamek.l = a.l * b.l;
    ulamek.m = a.m * b.m;
    return ulamek;
}

struct ulamek iloraz(struct ulamek a, struct ulamek b){
    struct ulamek pom;
    pom.l = b.m;
    pom.m = b.l;
    return iloczyn(a,pom);
}

struct ulamek uprosc(struct ulamek a){
    int nwd_a = nwd(a.l, a.m);
    if (nwd_a > 1){
        a.l /= nwd_a;
        a.m /= nwd_a;
    }
    return a;
}

void wypisz(struct ulamek a){
    a = uprosc(a);
    if (a.l==a.m){
        puts("1 ");
    }
    else if (a.l>a.m){
        int calk = a.l/a.m;
        int reszta = a.l % a.m;
        if (reszta==0)  printf("%d \n",calk);
        else            printf("%d %d/%d \n",calk, reszta, a.m);
    }
    else
        printf("%d/%d \n", a.l, a.m);
}

void testuj(void){
    struct ulamek a,b,c,d;
    a = utworz(1,2);
    b = utworz(1,4);
    c = utworz(12,5);
    d = utworz(5,5);

    puts("Wypisz 1/2");
    wypisz(a);
    puts("Wypisz 12/5");
    wypisz(c);
    puts("Wypisz 5/5");
    wypisz(d);

    puts("Suma 1/2 + 1/4 ");
    wypisz( suma(a,b) );
    puts("Suma 12/5 + 1/4 ");
    wypisz( suma(c,b) );
    puts("Suma 12/5 + 5/5 ");
    wypisz( suma(c,d) );

    puts("Roznica 1/2 - 1/4 ");
    wypisz( roznica(a,b) );
    puts("Roznica 12/5 - 1/4 ");
    wypisz( roznica(c,b) );
    puts("Roznica 12/5 - 5/5 ");
    wypisz( roznica(c,d) );

    puts("Iloczyn 1/2 * 1/4 ");
    wypisz( iloczyn(a,b) );
    puts("Iloczyn 12/5 * 1/4 ");
    wypisz( iloczyn(c,b) );
    puts("Iloczyn 12/5 * 5/5 ");
    wypisz( iloczyn(c,d) );

    puts("Iloraz 1/2 / 1/4 ");
    wypisz( iloraz(a,b) );
    puts("Iloraz 12/5 / 1/4 ");
    wypisz( iloraz(c,b) );
    puts("Iloraz 12/5 / 5/5 ");
    wypisz( iloraz(c,d) );
}

int main(void){
    testuj();

    return 0;
}
