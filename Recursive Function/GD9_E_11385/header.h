#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARRAY 5
typedef char string[64];

typedef struct mahasiswa {
    string nama, npm;
    float ipk;
} mahasiswa;

void init(mahasiswa m[], int index);
void print_all(mahasiswa m[], int index);

int get_empty_index(mahasiswa m[], int index);
int is_empty(mahasiswa m[], int index);

int find(mahasiswa m[], int index, string npm);
