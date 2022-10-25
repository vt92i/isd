#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[64];

typedef int infotype;
typedef struct Node *address;

typedef struct Node {
    infotype data;
    address next;
} Node;

typedef struct List {
    address first;
} List;

void init_empty(List *L);

bool is_empty(List L);
bool is_one_element(List L);

address allocate_data(infotype D);
address find_node(List L, infotype D);

void insert_first(List *L, address new_node);
void insert_after(address prev_node, address new_node);
void insert_last(List *L, address new_node);

void delete_first(List *L);
void delete_at(List *L, address del_node);
void delete_last(List *L);

void print_list(List L);
