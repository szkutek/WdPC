#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERSE_LENGTH 1026 /*maks. dlugosc wiersza - 1024 czy wiecej?*/

int read_verse(char verse[], int max);
int parse(int n, char verse[n]);
//void move(int x, int y, char board[size][size]);
void print_board(char letters[], int size, int board[size][size]);
int find_size(int n, char verse[n]);

int size=0;

int main(void){

    extern size=0;
    int n=0;
    char verse[MAX_VERSE_LENGTH];
    char letters[]={"abcdefghijklmnopqrs"};

    while((n=read_verse(verse,MAX_VERSE_LENGTH)) > 0){
        parse(n, verse);

    }

    //print_board(letters, size, board);

    return 0;
}


int read_verse(char verse[], int max){
    int c, i;

    for (i=0; i<max-1 && ((c=getchar())!=EOF); i++){

        if ((verse[i]=c) == '\n'){
            ++i;
            break;
        }
    }
    verse[i]='\0';
    return i;
}

int parse(int n, char verse[n]){
    if (size==0) find_size(verse);
    else






    return 0;
}


int find_size(int n, char verse[n]){
    bool found = false;
    int i=0;

    while (!found && i<n){
        if (is_char(i,'S') && is_char(i+1,'Z') && is_char(i+2,'[') &&
            is_number(i+3) &&
            (is_char(i+4,']') || (is_numer(i+4) && is_char(i+5,']')))){
                if (is_char(i+4,']'))
                    extern size = verse[i+3]-'0';
                else
                    extern size = 10*(verse[i+3]-'0') + verse[i+4]-'0';

            }
        i++;
        if (size>0 && size<20) found=true;
        else size=0;
    }

    return found ? i-1 : 0;
}


bool is_char(int n, char c){
    return n<MAX_VERSE_LENGTH && verse[n]==c;
}

bool is_number(int n){
    return verse[n]>='0' && verse[n]<='9';
}

bool is_small_letter(int n){
    return verse[n]>='a' && verse[n]<='z';
}
