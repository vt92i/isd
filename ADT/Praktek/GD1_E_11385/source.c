#include "header.h"

Mahasiswa makeMahasiswa(string nama, string npm) {
    Mahasiswa M;
    strcpy(M.nama, nama);
    strcpy(M.npm, npm);

    return M;
}

void initMahasiswa(Mahasiswa M[]) {
    int i;
    for (i = 0; i < 5; i++) {
        strcpy(M[i].nama, "-");
        strcpy(M[i].npm, "-");
    }
}

void tampilMahasiswa(Mahasiswa M[]) {
    int i;
    for (i = 0; i < 5; i++) {
        printf("\n==== DATA %d ==== \n", i + 1);
        printf("Nama Mahasiswa		: %s \n", M[i].nama);
        printf("NPM Mahasiswa		: %s \n\n", M[i].npm);
    }
}

void hapusMahasiswa(Mahasiswa M[], string npm) {
    int i;

    for (i = 0; i < 5; i++) {
        if (strcmp(M[i].npm, npm) == 0) {
            M[i] = makeMahasiswa("-", "-");
            printf("\nData telah dihapus! \n");
            return;
        }
    }
    printf("\nData tidak ditemukan! \n");
}

int isFull(Mahasiswa M[]) {
    int i;
    for (i = 0; i < 5; i++) {
        if (strcmp(M[i].nama, "-") == 0) {
            return i;
        }
    }
    return -1;
}
