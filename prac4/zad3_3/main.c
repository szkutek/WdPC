#include <stdio.h>
#include <stdlib.h>

#define MAX_N 10000

int n, m;
int *A;
int *B;
int *mniejsze;
int *rowne;

int input_and_check_data(void);
void output_data(int B[]);

void C_K_E(int A[], int n, int m);
void C_K_L(int rowne[], int m);
void Reorg(int A[], int mniejsze[], int n, int m);
void C_S(int A[], int n, int m);

int main(void){

//    int *mniejsze;
//    int *rowne;

    if (input_and_check_data()) return 0;

    //B = C_S(A,n,m);
    B = (int *)(malloc(n * sizeof(int)));
    C_S(A,n,m);

    output_data(B);

    free(A);
    free(B);

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

    A = (int *)malloc(n * sizeof(int));
    int k=0;
    for (int i=0; i<n; i++){
        scanf("%d", &k);
        if (k<0 || k>m-1){
            printf("\nError: value of element of input data out of range;\n");
            printf(" must be between 0 and %d (inclusive).\n", m-1);
            return 1;
        }
        A[i]=k;
    }
    return 0;
}

void output_data(int B[]){

    for (int i=1; i<=n; i++){
        printf("%d ", B[i]);
    }
    puts("");
}


void C_K_E(int A[], int n, int m){ //POLICZ-KLUCZE-ROWNE(A, n, m)
//    extern int *rowne;
    rowne = (int *)(malloc(m * sizeof(int)));

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
        indeks=nastepny[klucz];
        B[indeks]=A[i];
        nastepny[klucz]++;
    }
    free(nastepny);
    //return B;
}

void C_S(int A[], int n, int m){  //SORTOWANIE-PRZEZ-ZLICZANIE(A, n, m)
//    extern int *rowne;
//    rowne = (int *)(malloc(m * sizeof(int)));
    C_K_E(A,n,m);

    //extern int *mniejsze;
//    mniejsze = (int *)(malloc(m * sizeof(int)));
    C_K_L(rowne,m);

//    extern int* B;
//    B = (int *)(malloc(n * sizeof(int)));
    Reorg(A,mniejsze,n,m);

    free(rowne);
    free(mniejsze);
//    return B;
}

