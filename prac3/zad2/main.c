#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_TAB 33

int is_letter(char c){
    return (c >= 'A' && c <= 'Z');
}

int convert_to_base10(int nlen, int base, char n[nlen]){
    int num10=0, pot=1, i=0;
    for (i=nlen; i>0; i--){
        if (is_letter(n[i-1])) num10 += (n[i-1]-'A'+10)*pot;
        else                   num10 += (n[i-1]-'0')*pot;
        pot *= base;
    }
    return num10;
}

int convert_to_new_base(int num10, int new_base, char res[]){
    int j=0, tmp=0;
    while (num10>0){
        tmp = num10%new_base;
        if (tmp<10) res[j] = tmp + '0';
        else        res[j] = tmp + 'A' - 10;
        num10 /= new_base;
        j++;
    }
    return j-1;
}



int main(void)
{
    int base=0, new_base=0;
    char n[MAX_TAB]={0};

    int num10=0;

    char res[MAX_TAB]={0};
    int m=0;


    printf("Podaj stary i nowy system pozycyjny oraz liczbe naturalna:\n");
    scanf("%d %d %s", &base, &new_base, n);

    //length(n) = nlen+1
    int i=0;
    while (n[i]!='\0') i++;

    printf("%d\n", i);

    if (i==1 && n[0]=='0') puts("0");
    else {
        num10 = convert_to_base10(i, base, n);

        m = convert_to_new_base(num10, new_base, res);

        // print results
        for (int k=0; k<m+1; k++){
            printf("%c", res[m-k]);
        }
        puts("");
    }

    return 0;
}
