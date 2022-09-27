#include "header.h"

void isiData(Mahasiswa *M, int nimbaru, char namabaru[], float ipkbaru)
{
	(*M).nim = nimbaru;
	strcpy((*M).nama, namabaru);
	(*M).ipk = ipkbaru;
}

void tampilData(Mahasiswa M)
{
	printf("\nTampilkan Mahasiswa...");
	printf("\nNim   : %d", M.nim);
	printf("\nNama  : %s", M.nama);
	printf("\nIPK   : %0.2f \n", M.ipk);
}

void ubahIPK (Mahasiswa *M, float ipkbaru)
{
	(*M).ipk = ipkbaru;
}
