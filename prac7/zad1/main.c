#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct wezel{
    int x;
    struct wezel *lewy, *prawy;
} ;



//int szukaj(int a);

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


int main(void){

    int n;
//    int *wartosci;

    scanf("%d", &n);
    //wartosci = (int *)calloc(n, sizeof(int));
    int x;
    scanf("%d", &x);

    struct wezel *root=NULL;
    for (int i=0; i<n; i++){
        scanf("%d", &x);
        root = wstaw(root, x);
    }

    wypiszBST(root);

//    int q;
//    int *zapytania;
//    scanf("%d", &q);
//    zapytania = (int *)calloc(n, sizeof(int));
//    for (int i=0; i<q; i++){
//        scanf(" %d", &(zapytania+i));
//    }

    return 0;
}
