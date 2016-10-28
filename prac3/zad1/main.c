//290207
//lista 3
//zadanie 1

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int no_ones=0, longest_ones=0, longest_zeros=0;
    int len1=0, len0=0;

    unsigned int n = 0;
    scanf("%ud", &n);

    int i=0;
    unsigned int m=n/2;

    for (i=0; i<32; i++){
        if (n%2 != m%2){
            if (n%2==0){
                len0++;
                if (longest_zeros<len0){
                    longest_zeros=len0;
                }
                len0=0;
            }
            else {
                no_ones++;
                len1++;
                if (longest_ones<len1){
                    longest_ones=len1;
                }
                len1=0;
            }
        }
        else if (n%2==1){
            no_ones++;
            len1++;
        }
        else len0++;

    n=m;
    m=m/2;
    }

    if (longest_zeros<len0){
        longest_zeros=len0;
    }
    else if (longest_ones<len1){
        longest_ones=len1;
    }

    printf("ilosc jedynek: %d\n", no_ones);
    printf("dlugosc najdluzszego ciagu zer: %d\n", longest_zeros);
    printf("dlugosc najdluzszego ciagu jedynek: %d\n", longest_ones);

    return 0;
}
