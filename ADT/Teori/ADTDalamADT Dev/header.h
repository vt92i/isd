#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
       int nim;
       char nama[100];
       float ipk;
 }Mahasiswa;

typedef struct {
	char kode_prodi[10];
	char nama_prodi[20];
	Mahasiswa M;
}Prodi;

void isiDataMhs(Mahasiswa *M, int nimbaru, char namabaru[], float ipkbaru);
void tampilDataMhs(Mahasiswa M);
void isiDataProdi(Prodi *P, char kodeprodi[], char namaprodi[], Mahasiswa mhs);
void tampilDataProdi(Prodi P);
