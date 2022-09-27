#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"

void init(Customer C[]) {
    int i;
    for (i = 0; i < 5; i++) {
        strcpy(C[i].nama, "-");
        strcpy(C[i].nik, "-");
        strcpy(C[i].pekerjaan, "-");
        C[i].umur = 0;
    }
}

void print_data(Customer C[]) {
    int i;
    for (i = 0; i < 5; i++) {
        printf("\n[ Data %d ]\n", i + 1);
        printf("Nama Customer : %s \n", C[i].nama);
        printf("NIK Customer : %s \n", C[i].nik);
        printf("Pekerjaan : %s \n", C[i].pekerjaan);
        if (C[i].umur == 0) {
            printf("Umur : - \n");
        } else {
            printf("Umur : %d \n", C[i].umur);
        }
    }
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
        if (strcmp(C[i].nama, "-") == 0) return i;
    }
    return -1;
}
