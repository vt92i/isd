#include "header.h"

int is_one_element(list l) {
    return l->next == NULL;
}

int is_empty(list l) {
    return l == NULL;
}

address find_node_by_id(list l, int id) {
    if (is_empty(l))
        return NULL;
    else {
        if (l->d.id != id)
            return find_node_by_id(l->next, id);
        return l;
    }
}

address find_node_by_name(list l, string nama_peminjam) {
    if (is_empty(l))
        return NULL;
    else {
        if (strcmp(l->d.nama_peminjam, nama_peminjam) != 0)
            return find_node_by_name(l->next, nama_peminjam);
        return l;
    }
}

address allocate_data(data d) {
    address new_node = (address)malloc(sizeof(node));
    new_node->d = d;
    new_node->next = NULL;
    return new_node;
}

void init_empty(list *l) {
    *l = NULL;
}

void print_list(list l) {
    if (!is_empty(l)) {
        printf("\n[ Data %d | ID %d ]\n", l->d.id, l->d.id);
        printf("Nama Peminjam : %s \n", l->d.nama_peminjam);
        printf("Jenis Buku : %s \n", l->d.jenis_buku);
        printf("Tanggal Pinjam : %s \n", l->d.tanggal_pinjam);
        printf("Tanggal Kembali : %s \n", l->d.tanggal_kembali);
        printf("Status : %s \n", l->d.status);
        printf("Harga Pinjam : Rp %.0f \n", l->d.harga_pinjam);

        print_list(l->next);
    }
}

void insert_first(list *l, address new_node) {
    new_node->next = *l;
    *l = new_node;
}

void insert_after(list *l, address new_node, int id) {
    address target = find_node_by_id(*l, id);
    if (target != NULL) {
        new_node->next = target->next;
        target->next = new_node;
    }
}

void insert_last(list *l, address new_node) {
    if (is_empty(*l))
        insert_first(l, new_node);
    else {
        insert_last(&(*l)->next, new_node);
    }
}

void delete_first(list *l) {
    address temp = *l;
    *l = (*l)->next;
    free(temp);
}

void delete_at(list *l, address target) {
    if (*l != target)
        delete_at(&(*l)->next, target);
    else
        delete_first(l);
}

void delete_last(list *l) {
    if (!is_one_element(*l))
        delete_last(&(*l)->next);
    else
        delete_first(l);
}
