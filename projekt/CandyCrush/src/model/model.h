#ifndef MODEL_H
#define MODEL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "../types.h"
//
//#define WIDTH 10
//#define HEIGHT 10
//#define WIDTH 3
//#define HEIGHT 2


//int koniec_gry=0;
Candy candies[HEIGHT][WIDTH];
// counted candies
int horizontal[WIDTH][2];
int vertical[HEIGHT][2];


int random_candy();

int make_move(int x1, int y1, int x2, int y2);

int model_main();

CandyCount count_candies(int x, int y);

int is_fig_T(int x, int y);

int is_fig_I(int x, int y);

int is_fig_L(int x, int y);

#endif