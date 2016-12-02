//
//#include <stdio.h>
//#include <stdlib.h>
////
////int max(int n, int tab[]){
////    int max=tab[0];
////    for (int i=1; i<n; i++){
////        if (tab[i]>max) max=tab[i];
////    }
////    return max;
////}
////
////int min(int n, int tab[]){
////    int min=tab[0];
////    for (int i=1; i<n; i++){
////        if (tab[i]<min) min=tab[i];
////    }
////    return min;
////}
//
//int main(void){
//
//    int x=0, d=0, n=0;
//    int ilosc=0;
//    scanf("%d %d %d", &x,&d,&n);
//
//    int A[5]={0};
//    for (int e=0; e<n; e++){
//        scanf("%d", &A[e]);
//    }
//
//    int B[5]={0};
//    int max=0, min=0, suma=0;
//    for (B[0]=0; B[0]<=x; B[0]++){
//        min=B[0];
//        max=B[0];
//        suma += B[0]*A[0];
//        if (n==1){
//            if (x==suma) ilosc++;
//        }
//        else
//        for (B[1]=B[0]-d; B[1]<=B[0]+d; B[1]++){
//            min = (B[1]<min) ? B[1] : min;
//            max = (B[1]>max) ? B[1] : max;
//            suma +=B[1]*A[1];
//            if (n==2){
//                if (x==suma) ilosc++;
//            }
//            else if (suma<=x)
//            for (B[2]=B[0]-d; B[2]<=B[0]+d; B[2]++){
//                min=B[0];
//                max=B[0];
//                suma += B[2]*A[2];
//                if (n==3){
//                    if (x==suma && max-min<=d) ilosc++;
//                }
//                else
//                for (B[3]=B[0]-d; B[3]<=B[0]+d; B[3]++){
//                    min=B[0];
//                    max=B[0];
//                    suma += B[3]*A[3];
//                    if (n==4){
//                        if (x==suma && max-min<=d) ilosc++;
//                    }
//                    else
//                    for (B[4]=B[0]-d; B[4]<=B[0]+d; B[4]++){
//                        min=B[0];
//                        max=B[0];
//                        suma += B[4]*A[4];
//                        if (x==suma && max-min<=d) ilosc++;
//                    }
//                }
//            }
//        }
//    }
//
//
//    printf("%d\n", ilosc);
//
//    return 0;
//}
