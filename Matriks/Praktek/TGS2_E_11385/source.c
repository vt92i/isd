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

void encrypt_kode_pesanan(Meja m[ROW][COL]) {
    int i, j, k;

    int matrix_a[ROW][COL];
    int matrix_b[ROW][COL];

    printf("\nInput Matrix (5 x 5) : \n");
    for (i = 0; i < ROW; i++) {
        scanf("%d %d %d %d %d", &matrix_a[i][0], &matrix_a[i][1], &matrix_a[i][2], &matrix_a[i][3], &matrix_a[i][4]);
        for (j = 0; j < COL; j++) {
            matrix_b[i][j] = m[i][j].kode_pesanan;
        }
    }

    printf("\nMatrix Sebelum\n");
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("[%d]\t\t", m[i][j].kode_pesanan);
        }
        printf("\n");
    }

    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (matrix_b[i][j] != 0) {
                m[i][j].kode_pesanan = 0;
                for (k = 0; k < COL; k++) {
                    m[i][j].kode_pesanan += matrix_b[i][k] * matrix_a[k][j];
                }
            }
        }
    }

    printf("\nMatrix Sesudah\n");
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("[%d]\t\t", m[i][j].kode_pesanan);
        }
        printf("\n");
    }
}

void print_matrix_rotate90deg(Meja m[ROW][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = COL - 1; j >= 0; j--) printf("[%s]\t\t", m[j][i].nomor_meja);
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

Index find_data_by_nomor_meja(Meja m[ROW][COL], string nomor_meja) {
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

Index find_data_by_nama_pelanggan(Meja m[ROW][COL], string nama_pelanggan) {
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
