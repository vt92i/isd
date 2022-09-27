#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[24];

typedef struct {
    string nama;
    string npm;
} Mahasiswa;

Mahasiswa makeMahasiswa(string nama, string npm);
void initMahasiswa(Mahasiswa M[]);
void tampilMahasiswa(Mahasiswa M[]);
void hapusMahasiswa(Mahasiswa M[], string npm);
int isFull(Mahasiswa M[]);
