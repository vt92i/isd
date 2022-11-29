#include "header.h"

typedef struct parent* address_parent;
typedef struct child* address_child;

typedef struct data_subchild {
    int id;
    string tanggal_periksa, diagnosa_penyakit, obat;
    bool is_done;
} data_subchild;

typedef struct data_child {
    int id;
    string nama, tanggal_lahir, jenis_hewan, jenis_kelamin;
    data_subchild dsc;
} data_child;

typedef struct data_parent {
    int id;
    string nama, tanggal_bergabung;
    struct {
        string username, password;
    } login;
} data_parent;

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

void init_multilist(multilist* l);

address_parent allocate_parent(data_parent data);
address_parent find_parent_by_id(multilist l, int id);
address_parent find_parent_by_name(multilist l, string nama);

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

bool is_multilist_empty(multilist l);
bool have_children(address_parent p);

address_child allocate_child(data_child data);

void insert_first_child(multilist l, int id_parent, data_child data);
void insert_last_child(multilist l, int id_parent, data_child data);

void delete_first_child(multilist l, int id_parent);
void delete_last_child(multilist l, int id_parent);

void print_child(address_child c);
void print_all_children(address_parent p);

data_parent make_data_parent(int id, string nama, string tanggal_bergabung, string username, string password);
data_child make_data_child(int id, string nama, string tanggal_lahir, string jenis_hewan, string jenis_kelamin, data_subchild dsc);
data_subchild make_data_subchild(int id, string tanggal_periksa, string obat, string diagnosa_penyakit, bool is_done);

bool is_parent_unique(multilist l, int id);
bool is_child_unique(multilist l, int id);
