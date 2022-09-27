#include "header.h"

Data make_data(int id, string nama, string tanggal_lahir) {
    Data D;

    D.id = id;
    strcpy(D.nama, nama);
    strcpy(D.tanggal_lahir, tanggal_lahir);

    return D;
}

Data* find_by_id(Data* d_ptr, Data data[ROW][COL], int id) {
    int i, j;

    Data D = make_data(0, "-", "-");
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
            *d_ptr = make_data(id, "-", "-");
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
            printf("[%d | %s] ", d_ptr->id, d_ptr->nama);
            d_ptr++;
        }
        printf("\n");
    }
}

void input_data(Data* d_ptr) {
    while (true) {
        printf("Masukan Nama: ");
        fflush(stdin);
        gets(d_ptr->nama);

        if (strlen(d_ptr->nama) == 0 || strcmpi(d_ptr->nama, "-") == 0)
            printf("\nNama harus diisi!\n");
        else
            break;
    }

    while (true) {
        printf("Masukan Tanggal Lahir: ");
        fflush(stdin);
        gets(d_ptr->tanggal_lahir);

        if (strlen(d_ptr->tanggal_lahir) == 0 || strcmpi(d_ptr->tanggal_lahir, "-") == 0)
            printf("\nTanggal Lahir harus diisi!\n");
        else
            break;
    }
}
