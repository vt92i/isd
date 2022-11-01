#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[64];

typedef struct parent* address_parent;
typedef struct child* address_child;

typedef struct data_parent {
    int id_tim;
    string nama_tim;
} data_parent;

typedef struct data_child {
    string nama_pemain;
    int umur;
} data_child;

typedef struct parent {
    data_parent dp;
    address_parent next;
    address_child first_child;
} parent;

typedef struct child {
    data_child dc;
    address_child next;
} child;

typedef struct multilist {
    address_parent first_parent;
} multilist;

void init_empty(multilist* l);

address_parent allocate_parent(data_parent data);
address_parent find_parent(multilist l, int id_parent);

void insert_first_parent(multilist* l, data_parent data);
void insert_after_parent(multilist* l, int id_parent, data_parent data);
void insert_last_parent(multilist* l, data_parent data);

void delete_first_parent(multilist* l);
void delete_at_parent(multilist* l, int id_parent);
void delete_last_parent(multilist* l);

void delete_all_children(address_parent p);

void print_parent(address_parent p);
void print_all(multilist l);
void print_all_parent(multilist l);

bool is_empty(multilist l);
bool have_children(address_parent p);

address_child allocate_child(data_child data);

void insert_first_child(multilist l, int id_parent, data_child data);
void insert_last_child(multilist l, int id_parent, data_child data);

void delete_first_child(multilist l, int id_parent);
void delete_last_child(multilist l, int id_parent);

void print_child(address_child c);
void print_all_children(address_parent p);

data_parent make_data_parent(int id, string nama);
data_child make_data_child(string nama, int umur);
bool is_unique_id(multilist l, int id);
