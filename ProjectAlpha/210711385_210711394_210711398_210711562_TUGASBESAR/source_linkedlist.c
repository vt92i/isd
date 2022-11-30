#include "header_linkedlist.h"

int is_one_element(linked_list l) {
    return l->next == NULL;
}

int is_linkedlist_empty(linked_list l) {
    return l == NULL;
}

address find_node_by_id(linked_list l, int id) {
    if (is_linkedlist_empty(l))
        return NULL;
    else {
        if (l->d.id != id)
            return find_node_by_id(l->next, id);
        return l;
    }
}

address find_node_by_name(linked_list l, string nama_hewan) {
    if (is_linkedlist_empty(l))
        return NULL;
    else {
        if (strcmp(l->d.nama, nama_hewan) != 0)
            return find_node_by_name(l->next, nama_hewan);
        return l;
    }
}

address allocate_data(data d) {
    address new_node = (address)malloc(sizeof(node));
    new_node->d = d;
    new_node->next = NULL;
    return new_node;
}

void init_linkedlist(linked_list *l) {
    *l = NULL;
}

void print_list(linked_list l) {
    if (!is_linkedlist_empty(l)) {
        printf("\n[ Data Hewan ]\n");
        printf("ID Hewan : %d\n", l->d.id);
        printf("Nama : %s\n", l->d.nama);
        printf("Tanggal Lahir : %s\n", l->d.tanggal_lahir);
        printf("Jenis Hewan : %s\n", l->d.jenis_hewan);
        printf("Jenis Kelamin : %s\n", l->d.jenis_kelamin);

        printf("[ Riwayat Periksa ]\n");
        printf("\tID Periksa : %d \n", l->d.riwayat_periksa.id);
        printf("\tTanggal Periksa : %s \n", l->d.riwayat_periksa.tanggal_periksa);
        printf("\tID Dokter : %d \n", l->d.riwayat_periksa.id_dokter);

        print_list(l->next);
    }
}

void insert_first(linked_list *l, address new_node) {
    new_node->next = *l;
    *l = new_node;
}

void insert_after(linked_list *l, address new_node, int id) {
    address target = find_node_by_id(*l, id);
    if (target != NULL) {
        new_node->next = target->next;
        target->next = new_node;
    }
}

void insert_last(linked_list *l, address new_node) {
    if (is_linkedlist_empty(*l))
        insert_first(l, new_node);
    else {
        insert_last(&(*l)->next, new_node);
    }
}

void delete_first(linked_list *l) {
    address temp = *l;
    *l = (*l)->next;
    free(temp);
}

void delete_at(linked_list *l, address target) {
    if (*l != target)
        delete_at(&(*l)->next, target);
    else
        delete_first(l);
}

void delete_last(linked_list *l) {
    if (!is_one_element(*l))
        delete_last(&(*l)->next);
    else
        delete_first(l);
}
