#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <malloc.h>

typedef char string[50];

typedef struct tNode *address;

typedef struct {
    int nim;
    string nama;
    float ipk;
} Mahasiswa;

typedef struct tNode {
    Mahasiswa data;
    address next;
} Node;

typedef struct
{
    address First;
} List;

Mahasiswa initMahasiswa(int nimbaru, string namabaru, float ipkbaru);
void inisialisasi(List *L);
address alokasiData(Mahasiswa databaru);
int isEmpty(List L);

void insertFirst(List *L, Mahasiswa databaru);
void insertLast(List *L, Mahasiswa databaru);
void deleteFirst(List *L);
void deleteLast(List *L);
void showList(List L);

address findNode(List L, int nim);

void showListHighestIPK(List L);

void deleteIPK(List *L);

void deleteAt(List *L, int nim);
