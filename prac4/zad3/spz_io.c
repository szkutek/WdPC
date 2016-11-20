#include "f-protot.h"

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

void output_data(int B[], int n){

    for (int i=0; i<n; i++){
        printf("%d ", B[i]);
    }
    puts("");
}
