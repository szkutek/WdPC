#include <stdio.h>
#include <stdlib.h>

#define MAXN 100


typedef struct{
    char wart;
    int G;
    int D;
    int L;
    int P;
}PUNKT;

int N=1, M=1; //mapa
int P=0; // ilosc krokow
int L=0; // dlugosc sekwencji

PUNKT mapa[MAXN][MAXN+1];
char sekwencja[MAXN+1]={0};


void read_data(void){

    scanf("%d ", &N);
    scanf("%d ", &M);

    for (int i=0; i<M; i++){
        for (int j=0; j<N+1; j++){
            mapa[i][j].wart = getchar();
        }
        mapa[i][N].wart = '\0';
    }

    scanf("%d", &P);
    scanf("%d", &L);

    scanf("%s", sekwencja);
}

void print_map(void){
    for (int i=0; i<M; i++){
        for (int j=0; j<N; j++){
             printf("%c", mapa[i][j].wart);
        }
        printf("\n");
    }
}

int eval_move(int i, int j, int start_path, int moves_num){

    if ( i<0 || i>=M || j<0 || j>=N ) return 0; // warunek zeby nie wyjsc poza mape


    if (start_path==L && moves_num==P){ // koniec sciezki
        mapa[i][j].wart = 'X';
        return 1;
    }

    switch (sekwencja[start_path]){
        case 'G':
            if ((mapa[i-1][j  ].wart=='.' || mapa[i-1][j  ].wart =='X') && !mapa[i-1][j  ].G ){
                 mapa[i-1][j  ].G = 1;
                if (!eval_move(i-1, j  , start_path+1, moves_num+1)) mapa[i-1][j  ].G = 0;
            }
            break;
        case 'D':
            if ((mapa[i+1][j  ].wart=='.' || mapa[i+1][j  ].wart =='X') && !mapa[i+1][j  ].D ){
                 mapa[i+1][j  ].D = 1;
                if (!eval_move(i+1, j  , start_path+1, moves_num+1)) mapa[i+1][j  ].D = 0;
            }
            break;
        case 'L':
            if ((mapa[i  ][j-1].wart=='.' || mapa[i  ][j-1].wart =='X') && !mapa[i  ][j-1].L ){
                 mapa[i  ][j-1].L = 1;
                if (!eval_move(i  , j-1, start_path+1, moves_num+1)) mapa[i  ][j-1].L = 0;
            }
            break;
        case 'P':
            if ((mapa[i  ][j+1].wart=='.' || mapa[i  ][j+1].wart =='X') && !mapa[i  ][j+1].P ){
                 mapa[i  ][j+1].P = 1;
                if (!eval_move(i  , j+1, start_path+1, moves_num+1)) mapa[i  ][j+1].P = 0;
            }
            break;
        case 'S':
                eval_move(i  , j  , start_path+1, moves_num);
            break;
        case '?':

            if ((mapa[i-1][j  ].wart=='.' || mapa[i-1][j  ].wart =='X') && !mapa[i-1][j  ].G ){
                 mapa[i-1][j  ].G = 1;
                if (!eval_move(i-1, j  , start_path+1, moves_num+1)) mapa[i-1][j  ].G = 0;
            }

            if ((mapa[i+1][j  ].wart=='.' || mapa[i+1][j  ].wart =='X') && !mapa[i+1][j  ].D ){
                 mapa[i+1][j  ].D = 1;
                if (!eval_move(i+1, j  , start_path+1, moves_num+1)) mapa[i+1][j  ].D = 0;
            }

            if ((mapa[i  ][j-1].wart=='.' || mapa[i  ][j-1].wart =='X') && !mapa[i  ][j-1].L ){
                 mapa[i  ][j-1].L = 1;
                if (!eval_move(i  , j-1, start_path+1, moves_num+1)) mapa[i  ][j-1].L = 0;
            }

            if ((mapa[i  ][j+1].wart=='.' || mapa[i  ][j+1].wart =='X') && !mapa[i  ][j+1].P ){
                 mapa[i  ][j+1].P = 1;
                if (!eval_move(i  , j+1, start_path+1, moves_num+1)) mapa[i  ][j+1].P = 0;
            }

            eval_move(i  , j  , start_path+1, moves_num);

            break;
    }

    return 0;
}

void zeruj_mape(void){

    for (int i=0; i<M; i++){
        for (int j=0; j<N; j++){
            mapa[i][j].G = 0;
            mapa[i][j].D = 0;
            mapa[i][j].L = 0;
            mapa[i][j].P = 0;

            }
        }
}


int find_endpoint(){

    for (int i=0; i<M; i++){
        for (int j=0; j<N; j++){
            if (mapa[i][j].wart=='.' || mapa[i][j].wart=='X'){

                zeruj_mape();

                eval_move( i, j, 0, 0);
            }
        }
    }


    return 0;
}


int main(void){

    read_data();

    find_endpoint();

    print_map();

    return 0;
}
