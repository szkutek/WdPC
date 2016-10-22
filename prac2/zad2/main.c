//290207
//lista 2
//zadanie 2

#include <stdio.h>
#include <math.h>

int pozostale(int c);


int main(void){
    int c, z;
    int i = 0;
    if ((c=getchar()) != EOF){
        ;
    }

    while ((z=getchar()) != EOF || c!=EOF) {
        if (c!=z){
            if (i==0){
                c = pozostale(c);
                putchar(c);
            }
            else {
                putchar('\n');
                i=0;
            }
        }
        else i++;

        c=z;
    }

    return 0;
}


int pozostale(int c){
    if (c >= 'A' && c <= 'Z')
            c=c-'A'+'a';
        else if (c >= 'a' && c <= 'z')
            c=c-'a'+'A';
        else if (c == ' ')
            c='!';
    return c;
}
