#include <stdio.h>
#include <stdlib.h>

#define MAXN 100

int N=1, M=1; //mapa
int P=0, L=0; //sekwencja

char mapa[MAXN][MAXN+1]={{0}};
char sekwencja[MAXN+1]={0};

void read_data(void){

    scanf("%d", &N);
    scanf("%d", &M);

    for (int i=0; i<M; i++){
         scanf("%s", mapa[i]);
    }

    scanf("%d", &P);
    scanf("%d", &L);

    scanf("%s", sekwencja);
//    char *s = sekwencja;
//    for (int i=0; i<L; i++, s++){
//        *s = getchar();
//    }
//    *s = '\0';
}

void print_map(void){
    for (int i=0; i<M; i++){
        printf("%s\n", mapa[i]);
    }
}

int eval_move(int i, int j, int start_path, int moves_num){

    if (start_path==L && moves_num==P && (mapa[i][j]=='.' || mapa[i][j]=='X')){
        mapa[i][j] = 'X';
        return 1;
    }

    switch (sekwencja[start_path]){ // dodaj warunki zeby nie wyjsc poza mape!
        case 'G':
            if ((mapa[i-1][j  ]=='.' || mapa[i-1][j  ] =='X') )
                eval_move(i-1, j  , start_path+1, moves_num+1);
            break;
        case 'D':
            if ((mapa[i+1][j  ]=='.' || mapa[i+1][j  ] =='X') )
                eval_move(i+1, j  , start_path+1, moves_num+1);
            break;
        case 'L':
            if ((mapa[i  ][j-1]=='.' || mapa[i  ][j-1] =='X') )
                eval_move(i  , j-1, start_path+1, moves_num+1);
            break;
        case 'P':
            if ((mapa[i  ][j+1]=='.' || mapa[i  ][j+1] =='X') )
                eval_move(i  , j+1, start_path+1, moves_num+1);
            break;
        case 'S':
                eval_move(i  , j  , start_path+1, moves_num);
            break;
//        case '?':
//
//            break;
    }

    return 0;
}

//int eval_path(int i, int j, int start_path){
////    for (int k=start_path; k<L; k++){
//
//
//    if (sekwencja[start_path]=='?'){
//
//        sekwencja[start_path]='?';
//        eval_move(i, j, start_path);
//
//    }
//    return 0;
//}


int find_endpoint(){

    for (int i=0; i<M; i++){
        for (int j=0; j<N; j++){
            if (mapa[i][j]=='.' || mapa[i][j]=='X'){
                eval_move(i,j,0, 0);
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
