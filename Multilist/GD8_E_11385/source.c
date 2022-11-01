#include "header.h"

data_parent make_data_parent(int id, string nama) {
    data_parent dp;
    dp.id_tim = id;
    strcpy(dp.nama_tim, nama);
    return dp;
}

data_child make_data_child(string nama, int umur) {
    data_child dc;
    strcpy(dc.nama_pemain, nama);
    dc.umur = umur;
    return dc;
}

bool is_unique_id(multilist l, int id) {
    address_parent p = l.first_parent;
    while (p != NULL) {
        if (p->dp.id_tim == id) {
            return false;
        }
        p = p->next;
    }
    return true;
}
