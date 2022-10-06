#include "header.h"

bool is_empty(List L) {
    return L.first == NULL;
}

void init_list(List *L) {
    L->first = NULL;
}

address allocate_data(Data D) {
    address P = (tNode *)malloc(sizeof(tNode));

    P->D = D;
    P->next = NULL;

    return P;
}

void deallocate_data(address P) {
    free(P);
}

Data make_data(string nama, int npp) {
    Data D;

    strcpy(D.nama, nama);
    D.npp = npp;

    return D;
}

void insert_first(List *L, Data D) {
    address P = allocate_data(D);
    P->next = L->first;
    L->first = P;

    printf("\nBerhasil Insert First!\n");
}

void insert_last(List *L, Data D) {
    address P, last_node;

    if (is_empty(*L))
        insert_first(L, D);
    else {
        last_node = L->first;
        P = allocate_data(D);

        while (last_node->next != NULL)
            last_node = last_node->next;

        last_node->next = P;

        printf("\nBerhasil Insert Last!\n");
    }
}

void delete_first(List *L) {
    address target_node;

    if (is_empty(*L))
        printf("\nList kosong!\n");
    else {
        target_node = L->first;
        L->first = target_node->next;
        free(target_node);

        printf("\nBerhasil Delete First!\n");
    }
}

void delete_last(List *L) {
    address last_node, target_node;

    if (is_empty(*L))
        printf("\nList kosong!\n");
    else {
        if (L->first->next == NULL)
            delete_first(L);
        else {
            last_node = L->first;
            while (last_node->next->next != NULL)
                last_node = last_node->next;

            target_node = last_node->next;
            last_node->next = NULL;
            free(target_node);

            printf("\nBerhasil Delete Last!\n");
        }
    }
}

void print_list(List L) {
    address P;

    if (is_empty(L))
        printf("\nList kosong!\n");
    else {
        P = L.first;
        while (P != NULL) {
            printf("\n");
            printf("Nama Dosen : %s\n", P->D.nama);
            printf("NPP : %d\n", P->D.npp);
            P = P->next;
        }
    }
}

Data *find_dosen_by_npp(List L, int npp) {
    address P;

    if (is_empty(L))
        return NULL;
    else {
        P = L.first;
        while (P != NULL) {
            if (P->D.npp == npp)
                return &P->D;
            P = P->next;
        }
        return NULL;
    }
}
