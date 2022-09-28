#include "header.h"

Data make_data(int id, string no_buku, string judul_buku, string tanggal_terbit, string kategori) {
    Data D;

    D.id = id;
    strcpy(D.judul_buku, judul_buku);
    strcpy(D.no_buku, no_buku);
    strcpy(D.tanggal_terbit, tanggal_terbit);
    strcpy(D.kategori, kategori);

    return D;
}

Data* find_by_id(Data* d_ptr, Data data[ROW][COL], int id) {
    int i, j;

    Data D = make_data(0, "-", "-", "-", "-");
    Data *ptr_copy, *temp;

    ptr_copy = *data;
    temp = &D;

    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (ptr_copy->id == id)
                return ptr_copy;
            else if (d_ptr->id == id)
                return d_ptr;
            ptr_copy++;
        }
    }
    return temp;
}

void init_data(Data data[ROW][COL]) {
    int i, j, id = 1;

    Data* d_ptr;
    d_ptr = *data;

    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            *d_ptr = make_data(id, "-", "-", "-", "-");
            id++;
            d_ptr++;
        }
    }
}

void print_data(Data data[ROW][COL]) {
    int i, j;

    Data* d_ptr;
    d_ptr = *data;

    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("[%d | %s (%s)] \t", d_ptr->id, d_ptr->no_buku, d_ptr->kategori);
            d_ptr++;
        }
        printf("\n");
    }
}

void input_data(Data* d_ptr) {
    while (true) {
        printf("Masukan No Buku : ");
        fflush(stdin);
        gets(d_ptr->no_buku);

        if (strlen(d_ptr->no_buku) != 4 || strcmpi(d_ptr->no_buku, "-") == 0)
            printf("\nNo Buku harus 4 digit!\n");
        else
            break;
    }

    while (true) {
        printf("Masukan Judul Buku : ");
        fflush(stdin);
        gets(d_ptr->judul_buku);

        if (strlen(d_ptr->judul_buku) == 0 || strcmpi(d_ptr->judul_buku, "-") == 0)
            printf("\nJudul harus diisi!\n");
        else
            break;
    }

    while (true) {
        printf("Masukan Tanggal Terbit : ");
        fflush(stdin);
        gets(d_ptr->tanggal_terbit);

        if (strlen(d_ptr->tanggal_terbit) == 0 || strcmpi(d_ptr->tanggal_terbit, "-") == 0)
            printf("\nTanggal Terbit harus diisi!\n");
        else
            break;
    }

    while (true) {
        printf("Masukan Kategori : ");
        fflush(stdin);
        gets(d_ptr->kategori);

        if (strcmp(d_ptr->kategori, "Penting") == 0 || strcmp(d_ptr->kategori, "Terkenal") == 0)
            break;
        else
            printf("\nKategori harus antara Penting atau Terkenal!\n");
    }
}
