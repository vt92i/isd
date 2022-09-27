#include "header.h"

void isiDataMhs(Mahasiswa *M, int nimbaru, char namabaru[], float ipkbaru)
{
	(*M).nim = nimbaru;
	strcpy((*M).nama, namabaru);
	(*M).ipk = ipkbaru;
}

void tampilDataMhs(Mahasiswa M)
{
	printf("\nNim   : %d", M.nim);
	printf("\nNama  : %s", M.nama);
	printf("\nIPK   : %0.2f \n", M.ipk);
}

void isiDataProdi(Prodi *P, char kodeprodi[], char namaprodi[], Mahasiswa mhs)
{
	strcpy((*P).kode_prodi, kodeprodi);
	strcpy((*P).nama_prodi, namaprodi);
	(*P).M = mhs;
	//(*P).M.nama = mhs.nama;
}

void tampilDataProdi(Prodi P)
{
	printf ("\nProdi %s, memiliki kode prodi %s", P.nama_prodi, P.kode_prodi);
	printf ("\nMemiliki mahasiswa : ");
	tampilDataMhs(P.M);
	//printf ("\nMemiliki mahasiswa dengan nama : %s \n", P.M.nama);
}
