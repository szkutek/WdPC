#ifndef TYPES_H
#define TYPES_H

#define WIDTH 10
#define HEIGHT 10

#define MOVES_ALLOWED 4

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int color;
    int special;
} Candy;

typedef Point CandyCount;


#endif