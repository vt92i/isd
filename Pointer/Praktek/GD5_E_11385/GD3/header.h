#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA 10

#define ROW 2
#define COL 5

typedef char string[12];

typedef struct Data {
    int id;
    string nama, tanggal_lahir;
} Data;

Data make_data(int id, string nama, string tanggal_lahir);
Data* find_by_id(Data* d_ptr, Data data[ROW][COL], int id);

void init_data(Data data[ROW][COL]);
void print_data(Data data[ROW][COL]);
void input_data(Data* d_ptr);
