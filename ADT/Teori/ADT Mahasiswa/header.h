#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int nim;
	char nama[100];
	float ipk;
}Mahasiswa;

void isiData(Mahasiswa *M, int nimbaru, char namabaru[], float ipkbaru);
void tampilData(Mahasiswa M);
void ubahIPK (Mahasiswa *M, float ipkbaru);
