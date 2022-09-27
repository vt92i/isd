#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 5
#define COL 5

typedef char string[64];

typedef struct {
    int i;
    int j;
} Index;

typedef struct {
    string nama_pelanggan;
    string nomor_meja;
    int kode_pesanan;
} Meja;

void init_meja(Meja m[ROW][COL]);
void print_meja(Meja m[ROW][COL]);

Meja create_meja(string nama_pelanggan, string nomor_meja, int kode_pesanan);
Index find_data(Meja m[ROW][COL], string nomor_meja);
Index find_data_by_name(Meja m[ROW][COL], string nama_pelanggan);


bool is_filled(Meja data[ROW][COL], Index index);
