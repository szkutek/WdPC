#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 65536
int size=0;

int read_file(int max, int file[max]){
    int c, i;

    for (i=0; i<max-1 && ((c=getchar())!=EOF); i++){
        file[i]=c;
    }
    file[i]='\0';
    return i; // zwraca dlugosc wektora
}

bool is_char(int n, char c, int file[n]){
    return n<MAX_LEN && file[n]==c;
}

bool is_number(int n, int file[n]){
    return file[n]>='0' && file[n]<='9';
}

bool is_small_letter(int n, int file[n]){
    return file[n]>='a' && file[n]<='z';
}

int find_size(int n, int file[n]){
    bool found=false;
    int i=0;

    while (i<n-4){
        if (is_char(i,'S', file) && is_char(i+1,'Z', file) && is_char(i+2,'[', file) &&
            is_number(i+3, file) &&
            (is_char(i+4,']', file) || (is_number(i+4, file) && is_char(i+5,']', file)))){
                if (is_char(i+4,']', file))
                    size = file[i+3]-'0';
                else
                    size = 10*(file[i+3]-'0') + file[i+4]-'0';

            }
        i++;
        if (size>0 && size<20) found=true;
        else size=0;
    }

    return found ? i-1 : 0;
}




int main(void){
    int n = 0;
    int file[MAX_LEN]={0};
    n = read_file(MAX_LEN, file);

    //if (size==0)
    int i=0;
    i = find_size(n, file);
    printf("%d", i);

    int k=i;
    while (k<n){

        k++;
    }
    return 0;
}
