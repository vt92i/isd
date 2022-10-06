#include "header.h"

Mahasiswa initMahasiswa(int nimbaru, string namabaru, float ipkbaru) {
    Mahasiswa M;
    M.nim = nimbaru;
    strcpy(M.nama, namabaru);
    M.ipk = ipkbaru;
    return M;
}

void inisialisasi(List *L) {
    (*L).First = NULL;
}

address alokasiData(Mahasiswa databaru) {
    address P;
    P = (Node *)malloc(sizeof(Node));
    P->data = databaru;
    P->next = NULL;
    return P;
}

int isEmpty(List L) {
    return (L.First == NULL);
}
void insertFirst(List *L, Mahasiswa databaru) {
    address P;
    P = alokasiData(databaru);

    P->next = (*L).First;
    (*L).First = P;

    printf("Inserted");
}
void insertLast(List *L, Mahasiswa databaru) {
    address P, last;

    if (isEmpty(*L))
        insertFirst(&(*L), databaru);
    else {
        P = alokasiData(databaru);

        last = (*L).First;
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
        hapus = (*L).First;
        (*L).First = (*L).First->next;
        free(hapus);

        printf("Deleted");
    }
}
void deleteLast(List *L) {
    address bantu, hapus;
    if (isEmpty(*L))
        printf("List Kosong...");
    else {
        if ((*L).First->next == NULL) {
            deleteFirst(&(*L));
        } else {
            bantu = (*L).First;
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
void showList(List L) {
    if (isEmpty(L))
        printf("List Kosong...");
    else {
        while (L.First != NULL) {
            printf("\n%d %s %0.2f", L.First->data.nim, L.First->data.nama, L.First->data.ipk);
            L.First = L.First->next;
        }
    }
}

address findNode(List L, int nim) {
    address bantu = L.First;

    while (bantu != NULL && bantu->data.nim != nim) {
        bantu = bantu->next;
    }
    return bantu;
}

void showListHighestIPK(List L) {
    //
}

void deleteIPK(List *L) {
    if (isEmpty(*L))
        printf("List Kosong...");
    else {
        int to_be_deleted[14];
        int count = 0;
        while (L->First != NULL) {
            if (L->First->data.ipk < 2.0) {
                printf("IPK %f", L->First->data.ipk);
                to_be_deleted[count] = L->First->data.nim;
                count++;

                deleteAt(L, L->First->data.nim);
            }
            L->First = L->First->next;
        }
        int i;
        for (i = 0; i <= count; i++) {
            printf("%d \n", to_be_deleted[i]);
            getch();
            // deleteAt(L, to_be_deleted[i]);
        }
    }
}

void deleteAt(List *L, int nim) {
    address hapus, cari;

    hapus = findNode((*L), nim);

    if (hapus == NULL)
        printf("Data tidak ditemukan...");
    else {
        if (hapus == (*L).First)
            deleteFirst(&(*L));
        else {
            cari = (*L).First;
            while (cari->next != hapus) {
                cari = cari->next;
            }
            cari->next = hapus->next;
            free(hapus);

            printf("Deleted");
        }
    }
}
