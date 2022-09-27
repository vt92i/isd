#include "header.h"

void init_meja(Meja m[ROW][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            strcpy(m[i][j].nama_pelanggan, "-");
            strcpy(m[i][j].nomor_meja, "-");
            m[i][j].kode_pesanan = 0;
        }
    }
}

void print_meja(Meja m[ROW][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("[%s]\t\t", m[i][j].nomor_meja);
        }
        printf("\n");
    }
}

Meja create_meja(string nama_pelanggan, string nomor_meja, int kode_pesanan) {
    Meja m;
	strcpy(m.nama_pelanggan, nama_pelanggan);
    strcpy(m.nomor_meja, nomor_meja);
    m.kode_pesanan = kode_pesanan;
    return m;
}

Index find_data(Meja m[ROW][COL], string nomor_meja) {
    int i, j;
    Index index;
    index.i = -1;

    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (strcmpi(m[i][j].nomor_meja, nomor_meja) == 0) {
                index.i = i;
                index.j = j;
                return index;
            }
        }
    }

    return index;
}

Index find_data_by_name(Meja m[ROW][COL], string nama_pelanggan) {
    int i, j;
    Index index;
    index.i = -1;

    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (strcmpi(m[i][j].nama_pelanggan, nama_pelanggan) == 0) {
                index.i = i;
                index.j = j;
                return index;
            }
        }
    }

    return index;	
}

bool is_filled(Meja m[ROW][COL], Index index) {
    if (strcmpi(m[index.i][index.j].nomor_meja, "-")) return true;
    return false;
}
