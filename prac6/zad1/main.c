//290207
//lista 6
//zad 1

#include <stdio.h>
#include <stdlib.h>

int *MaxElem(int *tab,int n){ //zwracaj�c� wska�nik na element maksymalny
    int *m=tab;
    int *ptr;
    for (ptr=tab; ptr<tab+n; ptr++){
        if (*ptr>*m)
            m=ptr;
    }
    return m;
}

double Srednia(int *tab,int n){ // � zwracaj�c� �redni� arytmetyczn� liczb zawartych w tablicy
    double suma=0.0;
    for (int i=0; i<n; i++){
        suma += tab[i];
    }
    return (suma/n);
}

void Wypisz(int *tab,int n){ // � wypisuj�c� liczb� element�w oraz kolejne elementy tablicy
//    for (int i=0; i<n; i++) printf("%d ", tab[i]);
    int *ptr;
    for (ptr=tab; ptr<tab+n; ptr++)
        printf("%d ", *ptr);
    puts("");
}

void Sortuj(int *tab,int n){ // � sortuj�ca malej�co elementy tablicy
    int pom;
    for (int k=0; k<n; k++){
        for (int i=0; i<n-1; i++){
            if (tab[i]<tab[i+1]){
                pom = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = pom;
            }
        }
    }
}

int ileParzystych(int *tab,int n){ // � zwracaj�c� ilo�� parzystych element�w tablicy
    int parz=0;
    int *ptr;
    for (ptr=tab; ptr<tab+n; ptr++){
        if ((*ptr)%2==0) parz++;
    }
    return parz;
}

void Odwroc(int *tab,int n){ // odwraca kolejno�� element�w w tablicy
    int pom;
    for (int i=0; i<n/2; i++){
        pom = tab[i];
        tab[i] = tab[n-1-i];
        tab[n-1-i] = pom;
    }
}

int main(void)
{
    int n=0;
    scanf("%d", &n);
//    int tab[n];
    int *tab;
    tab = malloc(n * sizeof(int));

    for (int i=0; i<n; i++)
        scanf("%d", tab + i);

    int *m;
    m = MaxElem(tab, n);
    printf("MaxElem = %d o wskazniku %p \n", *m, m);

    printf("Srednia = %g \n", Srednia(tab,n));

    printf("Parzystych = %d \n", ileParzystych(tab,n));

    puts("tablica:");
    Wypisz(tab,n);

    puts("posortowana:");
    Sortuj(tab,n);
    Wypisz(tab,n);

    puts("odwrocona:");
    Odwroc(tab,n);
    Wypisz(tab,n);

    free(tab);
    return 0;
}
