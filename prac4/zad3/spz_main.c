#include "f-protot.h"

int main(void){

//    int *mniejsze;
//    int *rowne;

    if (input_and_check_data()) return 0;

    C_S(A,n,m);
    output_data(B,n);


    free(rowne);
    free(mniejsze);
    free(A);
    free(B);

    return 0;
}
