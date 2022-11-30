#include "header.h"

typedef struct node *address;
typedef struct node *linked_list;
typedef struct data data_hewan;

typedef struct data {
    int id;
    string nama, tanggal_lahir, jenis_hewan, jenis_kelamin;
    struct riwayat_periksa {
        int id, id_dokter;
        string tanggal_periksa;
    } riwayat_periksa;
} data;

typedef struct node {
    data d;
    address next;
} node;

int is_one_element(linked_list l);
int is_linkedlist_empty(linked_list l);

address find_node_by_id(linked_list l, int id);
address find_node_by_name(linked_list l, string nama_hewan);
address allocate_data(data d);

void init_linkedlist(linked_list *l);
void print_list(linked_list l);

void insert_first(linked_list *l, address new_node);
void insert_after(linked_list *l, address new_node, int id);
void insert_last(linked_list *l, address new_node);

void delete_first(linked_list *l);
void delete_at(linked_list *l, address target);
void delete_last(linked_list *l);
