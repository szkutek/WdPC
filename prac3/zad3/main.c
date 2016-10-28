#include <stdio.h>
#include <stdlib.h>

#define MAX_VERSE_LENGTH 1026 /*maks. dlugosc wiersza - 1024 czy wiecej?*/

int read_verse(char verse[], int max);
int parse(int n, char verse[n]);
//void move(int x, int y, char board[size][size]);
void print_board(char letters[], int size, int board[size][size]);
int find_size(char verse[]);

int main(void){

    int size=0, n=0;
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

    find_size(verse);






    return 0;
}


int find_size(char verse[]){
    char pattern[]="SZ[";

    for (i=0, j=0; )


}
