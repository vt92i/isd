#include "header.h"

void init(Stack *s) {
    s->top = -1;
}

void push(Stack *s, Kamar kamar) {
    s->top++;
    s->kamar[s->top] = kamar;
}

Kamar pop(Stack *s) {
    Kamar k;

    k = s->kamar[s->top];
    s->top--;

    return k;
}

void pop_all(Stack *s) {
    while (s->top != -1) pop(s);
}

void show(Stack s) {
    int i;
    for (i = 0; i != s.top + 1; i++) {
        printf("\n");
        printf("[ Data ke %d ] \n", i + 1);
        printf("Nama Penghuni : %s \n", s.kamar[i].nama_penghuni);
        printf("Kode Kamar : %s \n", s.kamar[i].kode_kamar);
        printf("Kelas Kamar : %s \n", s.kamar[i].kelas_kamar);
        printf("Lama Penyewaan : %d hari \n", s.kamar[i].lama_penyewaan);
        printf("\n");
    }
}

int is_empty(Stack s) {
    return s.top == -1;
}

int is_full(Stack s) {
    return s.top == MAX_STACK - 1;
}

int find_kamar_by_kode_kamar(Stack s, string kode_kamar) {
    int i;
    for (i = 0; i != s.top + 1; i++) {
        if (strcmp(s.kamar[i].kode_kamar, kode_kamar) == 0) return i;
    }
    return -1;
}

void kk_init(Kamar kk[]) {
    int i;
    for (i = 0; i != MAX_STACK; i++) {
        strcpy(kk[i].nama_penghuni, "-");
        strcpy(kk[i].kode_kamar, "-");
        strcpy(kk[i].kelas_kamar, "-");
        kk[i].lama_penyewaan = 0;
    }
}

void kk_sort_asc(Kamar kk[], int size) {
    int i, j;
    for (i = 0; i < size - 1; ++i) {
        for (j = 0; j < size - i - 1; ++j) {
            if (kk[j].lama_penyewaan < kk[j + 1].lama_penyewaan) {
                Kamar k_temp = kk[j];
                kk[j] = kk[j + 1];
                kk[j + 1] = k_temp;
            }
        }
    }

    Kamar kk_sorted[size];
    for (i = 0; i < size; i++) kk_sorted[size - i - 1] = kk[i];
    for (i = 0; i < size; i++) kk[i] = kk_sorted[i];
}

void kk_sort_desc(Kamar kk[], int size) {
    int i, j;
    for (i = 0; i < size - 1; ++i) {
        for (j = 0; j < size - i - 1; ++j) {
            if (kk[j].lama_penyewaan < kk[j + 1].lama_penyewaan) {
                Kamar k_temp = kk[j];
                kk[j] = kk[j + 1];
                kk[j + 1] = k_temp;
            }
        }
    }
}

void kk_clear(Kamar *kk) {
    strcpy(kk->nama_penghuni, "-");
    strcpy(kk->kode_kamar, "-");
    strcpy(kk->kelas_kamar, "-");
    kk->lama_penyewaan = 0;
}

int kk_find_empty(Kamar kk[]) {
    int i;
    for (i = 0; i != MAX_STACK; i++)
        if (strcmp(kk[i].nama_penghuni, "-") == 0) return i;

    return -1;
}
