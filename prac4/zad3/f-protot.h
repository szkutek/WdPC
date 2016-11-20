#include <stdio.h>
#include <stdlib.h>

#define MAX_N 10000

int n, m;
int *A;
int *B;
int *mniejsze;
int *rowne;

int input_and_check_data(void);
void output_data(int B[], int n);

void C_K_E(int A[], int n, int m);
void C_K_L(int rowne[], int m);
void Reorg(int A[], int mniejsze[], int n, int m);
void C_S(int A[], int n, int m);
