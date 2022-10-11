#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[64];

typedef struct Node *address;

typedef struct Data {
    int id_barang, harga;
    string nama_barang;
} Data;

typedef struct Node {
    Data D;
    address next;
} tNode;

typedef struct List {
    address first;
} List;

int is_empty(List L) {
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

Data make_data(int id, string nama, int harga) {
    Data D;

    D.id_barang = id;
    strcpy(D.nama_barang, nama);
    D.harga = harga;

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
            printf("ID Barang  : %d\n", P->D.id_barang);
            printf("Nama Barang : %s\n", P->D.nama_barang);
            printf("Harga : %d IDR\n", P->D.harga);
            P = P->next;
        }
    }
}

address findNode(List L, int id) {
    address P = L.first;

    while (P != NULL && P->D.id_barang != id) {
        P = P->next;
    }
    return P;
}

void deleteAt(List *L, int id) {
    address toBeDeleted, P;
    toBeDeleted = findNode(*L, id);

    if (toBeDeleted == NULL)
        printf("\nData tidak ditemukan!\n");
    else {
        if (toBeDeleted == (*L).first)
            delete_first(L);
        else {
            P = (*L).first;
            while (P->next != toBeDeleted) {
                P = P->next;
            }
            P->next = toBeDeleted->next;
            free(toBeDeleted);

            printf("\nDeleted!\n");
        }
    }
}

address findHighestPrice(List L) {
    address P, highestPriceNode;

    if (is_empty(L))
        return NULL;
    else {
        P = L.first;
        highestPriceNode = P;

        while (P != NULL) {
            if (P->D.harga > highestPriceNode->D.harga)
                highestPriceNode = P;
            P = P->next;
        }

        return highestPriceNode;
    }
}

void moveMaxPrice(List *L) {
    address highestPriceNode, P;

    if (is_empty(*L))
        printf("\nList kosong!\n");
    else {
        P = (*L).first;
        highestPriceNode = findHighestPrice(*L);

        if (highestPriceNode != NULL) {
            insert_last(L, highestPriceNode->D);
            deleteAt(L, highestPriceNode->D.id_barang);
        }
    }
}

int main(void) {
    List L1, L2;
    Data D;

    init_list(&L1);
    init_list(&L2);

    insert_last(&L1, make_data(1, "Sabun", 25000));
    insert_last(&L1, make_data(2, "Pensil", 5000));
    insert_last(&L1, make_data(30, "Shampo", 55000));
    insert_last(&L1, make_data(4, "Sikat Gigi", 10000));

    print_list(L1);
    moveMaxPrice(&L1);
    print_list(L1);

    // insert_last(&L2, make_data(1, "Shampo", 55000));
    // insert_last(&L2, make_data(2, "Pensil", 5000));
    // insert_last(&L2, make_data(3, "Sabun", 25000));
    // insert_last(&L2, make_data(4, "Sikat Gigi", 10000));

    // print_list(L2);
    // moveMaxPrice(&L2);
    // print_list(L2);

    return 0;
}
