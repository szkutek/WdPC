#ifndef MODEL_H
#define MODEL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "../types.h"

int player_moves;
int score;
bool flag;

Candy candies[HEIGHT][WIDTH];

// counted candies
Point horizontal[WIDTH];
Point vertical[HEIGHT];

CandyCount count_candies(Point p);


int random_candy();
void draw_board();
bool in_board(int x, int y);
int neighbor_candy(Point source, Point dest);
bool swap_candy(Point source, Point dest);
void clear_counted();
CandyCount count_candies(Point p);
void check_one_candy(Point p);
int check_swap(Point source, Point dest, bool do_swap);
int init_board();
void destroy_candy(Point p);
int update_board(Point source, Point dest);
void fill_voids();
void check_board();

#endif
