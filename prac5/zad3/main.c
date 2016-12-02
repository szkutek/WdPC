//#include <stdio.h>
//#include <stdlib.h>
//
//int max(int n, int tab[]){
//    int max=tab[0];
//    for (int i=1; i<n; i++){
//        if (tab[i]>max) max=tab[i];
//    }
//    return max;
//}
//
//int min(int n, int tab[]){
//    int min=tab[0];
//    for (int i=1; i<n; i++){
//        if (tab[i]<min) min=tab[i];
//    }
//    return min;
//}
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
//    for (B[0]=0; B[0]<=x; B[0]++){
//        if (n==1){
//            if (x==B[0]*A[0]) ilosc++;
//        }
//        else
//        for (B[1]=0; B[1]<=x; B[1]++){
//            if (n==2){
//                if (x==B[0]*A[0]+B[1]*A[1] && max(n,B)-min(n,B)<=d) ilosc++;
//            }
//            else
//            for (B[2]=0; B[2]<=x; B[2]++){
//                if (n==3){
//                    if (x==B[0]*A[0]+B[1]*A[1]+B[2]*A[2] && max(n,B)-min(n,B)<=d) ilosc++;
//                }
//                else
//                for (B[3]=0; B[3]<=x; B[3]++){
//                    if (n==4){
//                        if (x==B[0]*A[0]+B[1]*A[1]+B[2]*A[2]+B[3]*A[3] && max(n,B)-min(n,B)<=d) ilosc++;
//                    }
//                    else
//                    for (B[4]=0; B[4]<=x; B[4]++){
//                        if (x==B[0]*A[0]+B[1]*A[1]+B[2]*A[2]+B[3]*A[3]+B[4]*A[4] && max(n,B)-min(n,B)<=d) ilosc++;
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
