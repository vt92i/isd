#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef char string[64];

typedef struct node *address;
typedef struct node *list;

typedef struct data {
    int id;
    string jenis_buku, nama_peminjam, tanggal_pinjam, tanggal_kembali, status;
    float harga_pinjam;
} data;

typedef struct node {
    data d;
    address next;
} node;

int is_one_element(list l);
int is_empty(list l);

address find_node_by_id(list l, int id);
address find_node_by_name(list l, string nama_peminjam);
address allocate_data(data d);

void init_empty(list *l);
void print_list(list l);

void insert_first(list *l, address new_node);
void insert_after(list *l, address new_node, int id);
void insert_last(list *l, address new_node);

void delete_first(list *l);
void delete_at(list *l, address target);
void delete_last(list *l);
