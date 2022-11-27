#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
typedef char string[64];
typedef int infotype;
typedef int address;

typedef struct array {
    address end;
    infotype t[MAX];
} array;

void init_empty(array *a);
int is_empty(array a);
void set_array(array *a, int n);
void print_info(array a);

void bubble_sort(array *a);
void swap(int *a, int *b);

void merge_sort(array *a);
void add(array *a, int x);
int length(array a);
array clone_array(array a);
void part_into2(array *a, array *a2);
void merge(array *a, array t);

void quick_sort(array *a, int start, int end);
