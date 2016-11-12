// 290207
// lista 4
// zad 2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long mem[64]={0,1};

long long fibRec(int n){
    if (n<0 || n>62)    return -1;
    else if (n==0)      return 0;
    else if (n==1)      return 1;
    else                return fibRec(n-1)+fibRec(n-2);
}

long long fibIte(int n){
    if (n<0 || n>62)    return -1;
    else if (n==0)      return 0;
    else if (n==1)      return 1;
    else {
        long long f1=0, f2=1;
        for (int i=2; i<=n; i++){
            f2 += f1;
            f1 = f2-f1;
        }
        return f2;
    }
}

long long fibRecMem(int n){
    if (n<0 || n>62)    return -1;
    else if (n==0)      return mem[0];
    else if (n==1)      return mem[1];

    else {
        if (mem[n]==0)  mem[n] = fibRecMem(n-1) + mem[n-2];
        return mem[n];
    }
}


int main(void)
{
    int fib_function=0, n=0;
    long long fib_number=0;
    puts("Wpisz 1 dla fibRec, 2 dla fibIte lub 3 dla fibRecMem oraz numer ciagu fibonacciego:");
    puts("(np. 1 20 dla fibRec(20))");
    scanf("%d %d", &fib_function, &n);

    clock_t start_t, end_t;

    start_t = clock();
    switch (fib_function){
    case 1:
        fib_number=fibRec(n);
        break;
    case 2:
        fib_number=fibIte(n);
        break;
    case 3:
        fib_number=fibRecMem(n);
        break;
    }
    end_t=clock();

    printf("%lld, time=%ld ms\n", fib_number, end_t-start_t);

    return 0;
}
