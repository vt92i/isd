#include "header.h"

string _hyphen = "-";

void init(Customer C[]) {
    int i, j;
    for (i = 0; i < 5; i++) {
        C[i] = make_customer(_hyphen, _hyphen, _hyphen, 0);
        for (j = 0; j < 2; j++) {
            C[i].bank[j] = make_bank(_hyphen, _hyphen);
        }
    }
}

void print_data(Customer C[]) {
    int i, j;
    for (i = 0; i < 5; i++) {
        printf("\n[ Data Customer %d ]\n", i + 1);
        printf("Nama Customer \t: %s \n", C[i].nama);
        printf("NIK Customer \t: %s \n", C[i].nik);
        printf("Pekerjaan \t: %s \n", C[i].pekerjaan);
        if (C[i].umur == 0) {
            printf("Umur \t\t: - \n");
        } else {
            printf("Umur \t\t: %d \n", C[i].umur);
        }
        for (j = 0; j < 2; j++) {
            printf("\t[ Data Bank %d ]\n", j + 1);
            printf("\tNama Bank %d \t: %s\n", j + 1, C[i].bank[j].nama);
            printf("\tNo. Rekening %d \t: %s\n", j + 1, C[i].bank[j].rekening);
        }
    }
}

Customer make_customer(string nama, string nik, string pekerjaan, int umur) {
    Customer C;

    strcpy(C.nama, nama);
    strcpy(C.nik, nik);
    strcpy(C.pekerjaan, pekerjaan);
    C.umur = umur;

    return C;
}

Customer edit_customer(string nama, string nik, string pekerjaan, int umur) {
    Customer C;

    strcpy(C.nama, nama);
    strcpy(C.nik, nik);
    strcpy(C.pekerjaan, pekerjaan);
    C.umur = umur;

    return C;
}

Customer delete_customer() {
    return make_customer(_hyphen, _hyphen, _hyphen, 0);
}

Bank make_bank(string nama, string rekening) {
    Bank B;

    strcpy(B.nama, nama);
    strcpy(B.rekening, rekening);

    return B;
}

Bank edit_bank(string nama, string rekening) {
    Bank B;

    strcpy(B.nama, nama);
    strcpy(B.rekening, rekening);

    return B;
}

Bank delete_bank() {
    return make_bank(_hyphen, _hyphen);
}

int find_data(Customer C[], string data) {
    int i;
    for (i = 0; i < 5; i++) {
        if (strcmp(C[i].nik, data) == 0) return i;
    }
    return -1;
}

int find_empty(Customer C[]) {
    int i;
    for (i = 0; i < 5; i++) {
        if (strcmp(C[i].nama, _hyphen) == 0) return i;
    }
    return -1;
}
