#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 5
typedef char string[64];

typedef struct pesawat {
    string kode_pesawat;
    int jumlah_penumpang;
} pesawat;

void init(pesawat p[]);
void print(pesawat p[]);

int is_empty(pesawat p[]);
int is_jumlah_penumpang_unique(pesawat p[], int key);

void bubble_sort_desc_int(pesawat p[]);
void bubble_sort_desc_str(pesawat p[]);

int binary_search_int(pesawat p[], int left, int right, int data);
int binary_search_str(pesawat p[], int left, int right, string data);
int sequential_search(pesawat p[], int data);

void generate_characters(char c[]);
bool is_char_unique(char c[], char key);
int find_char(char c[], char key);
