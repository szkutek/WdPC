#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_TAB 33

int isLetter(char c){
    return (c >= 'A' && c <= 'Z');
}



int main(void)
{
    int base=0, new_base=0;
    char n[MAX_TAB]={0};
    printf("Podaj stary i nowy system poz. oraz liczbe:\n");
    scanf("%d %d %s", &base, &new_base, n);

    //length(n) = nlen+1 (bc '\0')
    int i=0;
    while (n[i]!='\0') i++;
    int nlen=i;

    // change to decimal
    int num10=0, pot=1;
    for (i=nlen; i>0; i--){
        if (isLetter(n[i-1])) num10 += (n[i-1]-'A'+10)*pot;
        else                 num10 += (n[i-1]-'0')*pot;
        pot *= base;
    }

    //printf("%d\n", num10);



    int j=0, m=0, tmp=0;
    char res[MAX_TAB]={0};

    // convert from base 10 to new base
    while (num10>0){
        tmp = num10%new_base;
        if (tmp<10) res[j] = tmp + '0';
        else        res[j] = tmp + 'A' - 10;
        num10 /= new_base;
        j++;
    }
    m=j-1;


    for (int k=0; k<m+1; k++){
        printf("%c", res[m-k]);
    }

    return 0;
}
