#ifndef HEADER
#define HEADER

#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 3
#define COL 5

typedef char string[64];

typedef struct {
    int value;
    string status;
} Data;

typedef struct {
    int i;
    int j;
} Index;

void init_matriks(Data data[ROW][COL]);
void print_matriks(Data data[ROW][COL]);

Data create_data(int value, char status[]);
Index find_data(Data data[ROW][COL], int value);

bool is_filled(Data data[ROW][COL], Index index);

#endif
