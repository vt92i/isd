// Benidiktus Violaz Morello Anjolie - 210711385 - ISD E

#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 4
#define COL 5

typedef char string[24];

typedef struct Data {
    int id;
    string no_buku, judul_buku;
    string tanggal_terbit, kategori;
} Data;

Data make_data(int id, string no_buku, string judul_buku, string tanggal_terbit, string kategori);
Data* find_by_id(Data* d_ptr, Data data[ROW][COL], int id);

void init_data(Data data[ROW][COL]);
void print_data(Data data[ROW][COL]);
void input_data(Data* d_ptr);
