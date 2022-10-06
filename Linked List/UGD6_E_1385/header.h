#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[64];

typedef struct Node *address;

typedef struct Data {
    string nama, jenis;
    int berat, harga;
} Data;

typedef struct Node {
    Data D;
    address next;
} tNode;

typedef struct List {
    address first;
} List;

bool is_empty(List L);
void init_list(List *L);

address allocate_data(Data D);
void deallocate_data(address P);

Data make_data(string nama, string jenis, int berat, int harga);

void insert_first(List *L, Data D);
void insert_last(List *L, Data D);

void delete_first(List *L);
void delete_last(List *L);

void print_list(List L);

Data *find_laundry_by_name(List L, string name);
