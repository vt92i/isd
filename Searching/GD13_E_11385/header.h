#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 12
typedef char string[64];

typedef int info_type;
typedef info_type key_type;
typedef info_type array_type[N];

int is_empty(array_type arr);
int is_full(array_type arr);
int is_unique(array_type arr, key_type key);

void init_array(array_type arr);
void print_array(array_type arr);
void copy_array(array_type arr1, array_type arr2);

void bubble_sort(array_type arr);
void swap(key_type *a, key_type *b);

int binary_search(array_type arr, int left, int right, info_type data);
int sequential_search(array_type arr, info_type data);

void insert_random(array_type arr);
