#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//#define MAX_LEN 65536
#define MAX_LEN 1024

int size=0;
int board[20][20]={{0}};

int read_file(int max, int file[]){
    int c, i;

    for (i=0; i<max-1 && ((c=getchar())!=EOF); i++){
        file[i]=c;
    }
    file[i]='\0';
    return i; // zwraca dlugosc wektora
}

int read_line(int max, int file[]){
    int c, i;

    for (i=0; i<max && ((c=getchar())!=EOF); i++){
        file[i]=c;
        if (c=='\n') break;
    }

    if (i==0 && c=='\n') return -1; // zwraca ze w linii jest tylko '\n'
    else                 return i; // zwraca dlugosc linii
}

void clear_file(int n, int file[]){
    for (int k=0; k<n; k++){
        file[k]=0;
    }
}

bool is_char(int n, char c, int file[]){
    return n<MAX_LEN && file[n]==c;
}

bool is_number(int n, int file[]){
    return file[n]>='0' && file[n]<='9';
}

bool is_small_letter(int n, int file[]){
    return file[n]>='a' && file[n]<='z';
}

int find_size(int n, int file[]){
    bool found=false;
    int i=0;

    while (i<n-4 && !found){
        if (is_char(i,'S', file) && is_char(i+1,'Z', file) && is_char(i+2,'[', file) &&
            is_number(i+3, file) &&
            (is_char(i+4,']', file) || (is_number(i+4, file) && is_char(i+5,']', file)))){
                if (is_char(i+4,']', file))
                    size = file[i+3]-'0';
                else
                    size = 10*(file[i+3]-'0') + file[i+4]-'0';

            }
        i++;
        if (size>0 && size<20) found=true;
        else size=0;
    }

    return found ? i : 0;
}

void make_a_move(int i, int file[], int move1, int move2){
    switch (file[i+1]){
    case 'B':
        board[move1][move2]=1;
        break;
    case 'W':
        board[move1][move2]=-1;
        break;
    }
}

void play(int k, int n, int file[]){

    for (int i=k; i<n-4; i++){
        if (is_char(i,';', file) && (is_char(i+1,'B', file) || is_char(i+1,'W', file))
            && is_char(i+2,'[', file)
            && is_small_letter(i+3,file) && is_small_letter(i+4, file)
            && is_char(i+5,']', file))
        {

            make_a_move(i, file, file[i+4]-'a', file[i+3]-'a');
        }
    }
}

void draw_board(){
    // first line
    printf(" ");
    for (int i=0; i<size; i++){
        printf(" %c", 'A'+i);
    }
    // next
    int noX=0, noO=0;
    int maxX=0, maxO=0;
    puts("");
    for (int i=0; i<size; i++){
        printf("%c", 'A'+i);
        for (int k=0; k<size; k++){
            switch (board[i][k]){
            case 1:
                printf(" %c", 'X');
                noX++;
                break;
            case -1:
                printf(" %c", 'O');
                noO++;
                break;
            default:
                printf(" %c", '.');
                break;
            }
        }
        if (noX>maxX) maxX=noX;
        if (noO>maxO) maxO=noO;
        noX=0;
        noO=0;
        puts("");
    }
    printf("%d %d", maxX, maxO);
}

int main(void){
    int n = 0;
    int i = 0;
    int file[MAX_LEN]={0};
    //n = read_file(MAX_LEN, file);

    while ( (n=read_line(MAX_LEN, file))!=0 ){ // n - dlugosc linii
        if (n==-1) continue;
        if (size==0) {
            i = find_size(n, file); // i - nr pozycji na ktorej znajduje sie SZ[]
            play(i, n, file);
        }
        else play(0, n, file);
        clear_file(n,file);
    }
    draw_board();

    return 0;
}
