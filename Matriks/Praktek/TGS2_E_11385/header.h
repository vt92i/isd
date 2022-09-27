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

void encrypt_kode_pesanan(Meja m[ROW][COL]);
void print_matrix_rotate90deg(Meja m[ROW][COL]);

Meja create_meja(string nama_pelanggan, string nomor_meja, int kode_pesanan);
Index find_data_by_nomor_meja(Meja m[ROW][COL], string nomor_meja);
Index find_data_by_nama_pelanggan(Meja m[ROW][COL], string nama_pelanggan);

bool is_filled(Meja data[ROW][COL], Index index);
