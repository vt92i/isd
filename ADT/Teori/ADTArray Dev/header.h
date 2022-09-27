#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
       int nim;
       char nama[100];
       float ipk;
 }Mahasiswa;

void isiData(Mahasiswa *M, int nimbaru, char namabaru[], float ipkbaru);
void tampilData(Mahasiswa M[]);
