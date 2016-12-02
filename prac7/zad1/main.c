//290207

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct wezel{
    int x;
    struct wezel *lewy, *prawy;
};

struct wezel *wstaw(struct wezel *wez, int wartosc){

    if (wez==NULL){
        struct wezel *tmp;
        tmp = (struct wezel *)malloc(sizeof(struct wezel));
        tmp->x = wartosc;
        tmp->lewy = NULL;
        tmp->prawy = NULL;
        return tmp;
    }

    if(wartosc >= (wez->x)) {
        wez->prawy = wstaw(wez->prawy,wartosc);
    }
    else if(wartosc < (wez->x)) {
        wez->lewy = wstaw(wez->lewy,wartosc);
    }

    return wez;
}

void wypiszBST(struct wezel *wez) {
    if (wez != NULL) {
        wypiszBST(wez->lewy);
        printf("%d ",wez->x);
        wypiszBST(wez->prawy);
    }
}

int szukaj(int a, struct wezel *wez){
    int i = 0;
    while (wez != NULL){
        if (a == (wez->x)) return i;

        else if(a > (wez->x)) {
            wez = wez->prawy;
            i++;
        }
        else if(a < (wez->x)) {
            wez = wez->lewy;
            i++;
        }
    }

    return -1;
}

int main(void){

    int n;
    scanf("%d", &n);
    int x;

    struct wezel *root=NULL;
    for (int i=0; i<n; i++){
        scanf("%d", &x);
        root = wstaw(root, x);
    }

//    puts("Drzewo");
//    wypiszBST(root);

//    puts("");
//    puts("Wyniki");

    int q;
    scanf("%d", &q);
    int zapytanie;
    int odp;
    for (int i=0; i<q; i++){
        scanf("%d", &zapytanie);
        odp = szukaj(zapytanie,root);
        if (odp==-1)    printf("wierzcholek %d nie istnieje\n", zapytanie);
        else            printf("wierzcholek %d jest na glebokosci %d\n", zapytanie, odp);
    }

    return 0;
}
