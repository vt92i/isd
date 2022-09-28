#include "header.h"

void inisialisasi(List *L) {
    L->First = NULL;
}

address alokasiData(int databaru) {
    address P;
    P = (Node *)malloc(sizeof(Node));
    P->data = databaru;
    P->next = NULL;
    return P;
}

int isEmpty(List L) {
    return (L.First == NULL);
}

void insertFirst(List *L, int databaru) {
    address P;
    P = alokasiData(databaru);

    P->next = L->First;
    L->First = P;

    printf("Inserted");
}

void insertLast(List *L, int databaru) {
    address P, last;

    if (isEmpty(*L))
        insertFirst(&(*L), databaru);
    else {
        P = alokasiData(databaru);

        last = L->First;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = P;

        printf("Inserted");
    }
}

void deleteFirst(List *L) {
    address hapus;
    if (isEmpty(*L))
        printf("List Kosong...");
    else {
        hapus = L->First;
        L->First = L->First->next;
        free(hapus);

        printf("Deleted");
    }
}

void deleteLast(List *L) {
    address bantu, hapus;
    if (isEmpty(*L))
        printf("List Kosong...");
    else {
        if (L->First->next == NULL) {
            deleteFirst(&(*L));
        } else {
            bantu = L->First;
            while (bantu->next->next != NULL) {
                bantu = bantu->next;
            }
            hapus = bantu->next;
            bantu->next = NULL;
            free(hapus);
            printf("Deleted");
        }
    }
}

void deleteAll(List *L) {
    if (isEmpty(*L))
        printf("List Kosong...");
    else {
        while (!isEmpty(*L)) deleteFirst(L);
    }
}

void showList(List L) {
    if (isEmpty(L))
        printf("List Kosong...");
    else {
        while (L.First != NULL) {
            printf("%d ", L.First->data);
            L.First = L.First->next;
        }
    }
}

Node *cariData(List L, int data) {
    if (isEmpty(L))
        printf("List Kosong...");
    else {
        while (L.First != NULL) {
            if (L.First->data == data) return L.First;
            L.First = L.First->next;
        }
        return NULL;
    }
}
