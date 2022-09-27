#include "header.h"

void isiData(Mahasiswa *M, int nimbaru, char namabaru[], float ipkbaru)
{
	(*M).nim = nimbaru;
	strcpy((*M).nama, namabaru);
	(*M).ipk = ipkbaru;
}

void tampilData(Mahasiswa M[])
{
	int i;
	for (i=0; i<=2; i++)
	{
		printf("\nNim   : %d", M[i].nim);
		printf("\nNama  : %s", M[i].nama);
		printf("\nIPK   : %0.2f \n\n", M[i].ipk);
	}
}
