#include <stdio.h>
#include <float.h>

int main(void){

    //printf("DBL_MAX = %f\n", DBL_MAX);
    //printf("FLT_MAX = %f\n", FLT_MAX);

    float c = 0;
    int n = 0;

    for (int i=0; i<1000; i++){
        if (n%2==0){
            c += 1.0f / ((2*n+1)*(2*n+1));
        }
        else {
            c -= 1.0f / ((2*n+1)*(2*n+1));
        }
        n++;
    }
    printf("c = %1.30f\n", c);

    return 0;
}
