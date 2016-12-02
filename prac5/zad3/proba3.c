#include <stdio.h>
#include <stdlib.h>

int maksimum(int n, int tab[]){
    int max=tab[0];
    for (int i=1; i<n; i++){
        if (tab[i]>max) max=tab[i];
    }
    return max;
}

int minimum(int n, int tab[]){
    int min=tab[0];
    for (int i=1; i<n; i++){
        if (tab[i]<min) min=tab[i];
    }
    return min;
}

//void szukaj(int a, int b, int i, int suma){
//    int suma=0;
//    for (b=0; b<=x; b++){
//        min = (b<min) ? b : min;
//        max = (b>max) ? b : max;
//        suma += b*a;
//        if (n==i){
//            if (x==suma && max-min<=d) ilosc++;
//        }
//        else
//            szukaj(A[i+1], B[i+1], i+1);
//
//    }
//    return suma;
//}



int main(void){

    int x=0, d=0, n=0;
    int ilosc=0;
    int A[5]={0};
    int B[5]={0};
    int max=0, min=0, suma=0;

    scanf("%d %d %d", &x,&d,&n);
    for (int e=0; e<n; e++){
        scanf("%d", &A[e]);
    }



    for (B[0]=0; B[0]<=x; B[0]++){
        min=B[0];
        max=B[0];
        suma = B[0]*A[0];
        if (n==1){
            if (x==suma) ilosc++;
        }
        else
        for (B[1]=B[0]-d; B[1]<=B[0]+d; B[1]++){
            min = (B[1]<min) ? B[1] : min;
            max = (B[1]>max) ? B[1] : max;
            suma +=B[1]*A[1];
            if (n==2){
                if (x==suma) ilosc++;
                min=B[0];
                max=B[0];
                suma -= B[1]*A[1];
            }
            else if (suma<=x)
            for (B[2]=B[0]-d; B[2]<=B[0]+d; B[2]++){
                min = (B[2]<min) ? B[2] : min;
                max = (B[2]>max) ? B[2] : max;
                suma += B[2]*A[2];
                if (n==3){
                    if (x==suma && max-min<=d) ilosc++;
                    min=minimum(2,B);
                    max=maksimum(2,B);
                    suma -= B[2]*A[2];
                }
                else if (suma<=x)
                for (B[3]=B[0]-d; B[3]<=B[0]+d; B[3]++){
                    min = (B[3]<min) ? B[3] : min;
                    max = (B[3]>max) ? B[3] : max;
                    suma += B[3]*A[3];
                    if (n==4){
                        if (x==suma && max-min<=d) ilosc++;
                        min=minimum(3,B);
                        max=maksimum(3,B);
                        suma -= B[3]*A[3];
                    }
                    else if (suma<=x)
                    for (B[4]=B[0]-d; B[4]<=B[0]+d; B[4]++){
                        min = (B[4]<min) ? B[4] : min;
                        max = (B[4]>max) ? B[4] : max;
                        suma += B[4]*A[4];
                        if (x==suma && max-min<=d) ilosc++;
                            min=minimum(4,B);
                            max=maksimum(4,B);
                            suma -= B[4]*A[4];
                    }
                }
            }
        }
    }


    printf("%d\n", ilosc);

    return 0;
}
