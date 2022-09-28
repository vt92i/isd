#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct tNode *address;
typedef struct tNode {
    int data;
    address next;
} Node;

typedef struct
{
    address First;
} List;

void inisialisasi(List *L);
address alokasiData(int databaru);
int isEmpty(List L);

void insertFirst(List *L, int databaru);
void insertLast(List *L, int databaru);
void deleteFirst(List *L);
void deleteLast(List *L);
void deleteAll(List *L);
void showList(List L);

Node *cariData(List L, int data);
