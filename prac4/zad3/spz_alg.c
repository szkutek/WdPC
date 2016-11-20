#include "f-protot.h"


void C_K_E(int A[], int n, int m){ //POLICZ-KLUCZE-ROWNE(A, n, m)
//    extern int *rowne;
    rowne = (int *)(malloc(m * sizeof(int)));
    for (int i=0; i<m; i++) rowne[i]=0;

    int klucz=0, k=m;
    for (int i=0; i<n; i++){
        klucz=A[i];
        rowne[klucz]++;
        k++;
    }
    //return rowne;
}

void C_K_L(int rowne[], int m){ //POLICZ-KLUCZE-MNIEJSZE(rowne, m)
    // int rowne[m] = C_K_E(m);
//    extern int *mniejsze;
    mniejsze = (int *)(malloc(m * sizeof(int)));
    for (int i=0; i<m; i++) mniejsze[i]=0;

    mniejsze[0]=0;
    for (int i=1; i<m; i++){
        mniejsze[i] = mniejsze[i-1] + rowne[i-1];
    }
    //return mniejsze;
}

void Reorg(int A[], int mniejsze[], int n, int m){ // REORGANIZUJ(A, mniejsze, n, m)
//    extern int *B;
//    B = (int *)(malloc(n * sizeof(int)));
    int *nastepny;
    nastepny = (int *)(malloc(m * sizeof(int)));

    for (int i=0; i<m; i++){
        nastepny[i] = mniejsze[i] + 1;
    }

    int klucz=0;
    int indeks=0;
    for (int i=0; i<n; i++){
        klucz=A[i];
        indeks=nastepny[klucz]-1;
        B[indeks]=A[i];
        nastepny[klucz]++;
    }
    free(nastepny);
    //return B;
}

void C_S(int A[], int n, int m){  //SORTOWANIE-PRZEZ-ZLICZANIE(A, n, m)

    B = (int *)(malloc(n * sizeof(int)));
    for (int i=0; i<n; i++) B[i]=0;


    C_K_E(A,n,m);
    //output_data(rowne,m);

    C_K_L(rowne,m);
    //output_data(mniejsze,m);

    Reorg(A,mniejsze,n,m);
    //output_data(B,n);

//    return B;
}
