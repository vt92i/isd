#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 128
typedef char string[64];
typedef int address;

typedef struct resto {
    string nama_makanan;
    int order_id, harga;
} resto;

typedef struct array {
    address end;
    resto r[MAX];
} array;

void init_empty(array *a);
int is_empty(array a);
void print_info(array a);

void bubble_sort(array *a);

void merge_sort(array *a);
void add(array *a, resto x);
int length(array a);
array clone_array(array a);
void part_into2(array *a, array *a2);
void merge(array *a, array t);

void quick_sort(array *a, int start, int end);

int find_by_id(array arr, int id);
void cleanup(array *arr, int index);
