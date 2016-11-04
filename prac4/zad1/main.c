//290207
//lista 4
//zadanie 1

#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 132

int is_digit(char c){
    return (c >= '0' && c <= '9');
}

int is_min(int num_len, int nsgn, char num[], int min_len, int msgn, char min[]){
    int k=0;

    if (msgn==1 && nsgn==0) return 0;

    else if (msgn==0 && nsgn==1) return 1;

    else if (msgn==0 && nsgn==0){
        if (min_len>num_len) return 1;
        else if (min_len==num_len){
            for (k=0; k<min_len; k++){
                if (min[k]>num[k]) return 1;
                else if (min[k]<num[k]) return 0;
            }
        }
        else return 0;
    }

    //else if (msgn==1 && nsgn==1){
    else {
        if (min_len<num_len) return 1;
        else if (min_len==num_len){
            for (k=0; k<min_len; k++){
                if (min[k]>num[k])      return 0;
                else if (min[k]<num[k]) return 1;
            }
        }
        else return 0;
    }

    return 0;
}


int main(void){

    int c=0, z=0;

    char num[MAX_DIGITS] = {0};
    int num_len = 0;
    int nsgn=0;

    char min[MAX_DIGITS] = {0};
    int min_len=0;
    int msgn=0;

    int i=0;
    int k=0;
    int first_number=1;
    int found_not_zero=0;

    c=getchar();
    while ( (z=getchar()) != EOF || c!=EOF ){

        if (!is_digit(c) && is_digit(z)){
            if (c=='-') nsgn=1;
            else        nsgn=0;
        }
        else if (is_digit(c) && !is_digit(z)){
            num[i]=c; //even if '0'
            num_len=i+1; //length(num)

            if (first_number || is_min(num_len, nsgn, num, min_len, msgn, min)){
                first_number=0;
                min_len=num_len;
                msgn=nsgn;

                for (k=0; k<MAX_DIGITS; k++){
                    min[k]=num[k];
                }
            }

            k=0;
            while (k<MAX_DIGITS && num[k]!=0){
                num[k]=0;
                k++;
            }
            nsgn=0;
            i=0;
            found_not_zero=0;
        }
        else if (is_digit(c)){
            if (found_not_zero){
                num[i]=c;
                i++;
            }
            else if (!found_not_zero && c!='0'){
                found_not_zero=1;
                num[i]=c;
                i++;
            }
        }
//        else if ( is_digit(c) ){
//            if ( found_not_zero || (!found_not_zero && c!='0') ){
//                found_not_zero=1;
//                num[i]=c;
//                i++;
//            }
//        }

        c=z;
    }

    if (msgn && min[0]!='0') printf("-");
    for (int l=0; l<min_len; l++){
        printf("%c", min[l]);
    }
    puts("");

    return 0;
}
