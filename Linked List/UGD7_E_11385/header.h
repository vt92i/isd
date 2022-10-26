#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[64];

typedef struct Data {
    float distance;
    int minutes;
    string stop;
} Data;

typedef struct Node *address;

typedef struct Node {
    Data data;
    address next;
} Node;

typedef struct List {
    address first;
} List;

void init_empty(List *L);

bool is_empty(List L);
bool is_one_element(List L);

address allocate_data(Data D);
address find_node(List L, Data D);

void insert_first(List *L, address new_node);
void insert_after(address prev_node, address new_node);
void insert_last(List *L, address new_node);

void delete_first(List *L);
void delete_at(List *L, address del_node);
void delete_last(List *L);

void print_list(List L);

void sort_time(List *L);
void sort_distance(List *L);
