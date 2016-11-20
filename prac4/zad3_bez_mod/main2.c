#include <stdio.h>
#include <stdlib.h>

#define MAX_N 10000

int n=0, m=0;
int A[MAX_N]={0};
int B[MAX_N]={0};
//int rowne[MAX_N]={0};
//int mniejsze[MAX_N]={0};
int* rowne;
int* mniejsze;

int input_and_check_data(void);
void output_data(int B[]);

int* C_K_E(int A[], int n);
int* C_K_L(int rowne[], int m);
int* Reorg(int A[], int mniejsze[], int n, int m);
int* C_S(int A[], int n, int m);


int main(void){
    if (input_and_check_data()) return 0;

//    extern int* B;
    int *B;
    B = C_S(A,n,m);

    output_data(B);
    return 0;
}

int input_and_check_data(void){
    scanf("%d %d", &n, &m);

    if (n<1 || n>MAX_N){
        printf("\nError: size of input table out of range;\n");
        printf(" must be between 1 and %d (inclusive).\n", MAX_N);
        return 1;
    }
    if (m<1 || m>n){
        printf("\nError: cardinality of key set out of range;\n");
        printf(" must be between 1 and %d (inclusive).\n", n);
        return 1;
    }

    for (int i=0; i<n; i++){
        scanf("%d", &A[i]);
        if (A[i]<0 || A[i]>m-1){
            printf("\nError: value of element of input data out of range;\n");
            printf(" must be between 0 and %d (inclusive).\n", m-1);
            return 1;
        }
    }

    return 0;
}

void output_data(int B[]){
    for (int i=0; i<n; i++){
        printf("%d ", B[i]);
    }
}

int* C_K_E(int A[], int n){ //POLICZ-KLUCZE-ROWNE(A, n, m)
    static int rowne[MAX_N];
    for (int i=0; i<m; i++){
        rowne[A[i]]++;
    }
    return rowne;
}

int* C_K_L(int rowne[], int m){ //POLICZ-KLUCZE-MNIEJSZE(rowne, m)
    // int mniejsze[m];
    mniejsze[0]=0;
    for (int i=1; i<m; i++){
        mniejsze[i] = mniejsze[i-1] + rowne[i-1];
    }
    return mniejsze;
}

int* Reorg(int A[], int mniejsze[], int n, int m){ // REORGANIZUJ(A, mniejsze, n, m)
//    extern int* B;
    int nastepny[m];

    for (int i=0; i<m; i++){
        nastepny[i] = mniejsze[i] + 1;
    }

    int klucz=0;
    int indeks=0;
    for (int i=0; i<n; i++){
        klucz=A[i];
        indeks=nastepny[klucz];
        B[indeks]=A[i];
        nastepny[klucz]++;
    }

    return B;
}

int* C_S(int A[], int n, int m){  //SORTOWANIE-PRZEZ-ZLICZANIE(A, n, m)
    extern int *rowne;
    rowne = C_K_E(A,n);
    extern int* mniejsze;
    mniejsze = C_K_L(rowne,m);

    int* B;
    B = Reorg(A,mniejsze,n,m);

    return B;
}
