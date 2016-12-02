#include <stdio.h>
#include <stdlib.h>

struct ulamek
{
    int x;
    int y;
}ulamek;
struct ulamek utworz(int licznik,int mianownik)
{
    ulamek.x = licznik;
    ulamek.y = mianownik;
    return ulamek;
};
struct ulamek suma(struct ulamek a,struct ulamek b)
{
    int w_mian = a.y*b.y;
    int licz1 = a.x*b.y;
    int licz2 = b.x*a.y;
    licz1 += licz2;
    ulamek.x = licz1;
    ulamek.y = w_mian;
    return ulamek;
};

struct ulamek roznica(struct ulamek a,struct ulamek b)
{
    int w_mian = a.y*b.y;
    int licz1 = a.x*b.y;
    int licz2 = b.x*a.y;
    licz1 -= licz2;
    ulamek.x = licz1;
    ulamek.y = w_mian;
    return ulamek;
};/*
struct ulamek iloczyn(struct ulamek a,struct ulamek b);
struct ulamek iloraz(struct ulamek a,struct ulamek b);
struct ulamek uprosc(struct ulamek a);*/
void wypisz(struct ulamek a)
{
    printf("%d/%d\n",a.x, a.y);
};

int main()
{
    int a = 1, b=2, c=3, d=4;
    struct ulamek k, l, s;
    k = utworz(a,b);
    wypisz(k);
    l = utworz(c,d);
    wypisz(l);
    s = suma(k,l);
    wypisz(s);
    s = roznica(k,l);
    wypisz(s);
    return 0;
}
