#include "header.h"

void init(pesawat p[]) {
    int i;
    for (i = 0; i < N; i++) {
        strcpy(p[i].kode_pesawat, "0");
        p[i].jumlah_penumpang = 0;
    }
}

void print(pesawat p[]) {
    int i;
    for (i = 0; i < N; i++)
        printf("%s - %d \n", p[i].kode_pesawat, p[i].jumlah_penumpang);
    printf("\n");
}

int is_empty(pesawat p[]) {
    int i;
    for (i = 0; i < N; i++) {
        if (p[i].jumlah_penumpang != 0) return 0;
    }
    return 1;
}

int is_jumlah_penumpang_unique(pesawat p[], int key) {
    int i;
    for (i = 0; i < N; i++)
        if (p[i].jumlah_penumpang == key)
            return 0;
    return 1;
}

void bubble_sort_desc_int(pesawat p[]) {
    int i, j;
    for (i = 0; i < N; i++)
        for (j = i + 1; j < N; j++)
            if (p[i].jumlah_penumpang < p[j].jumlah_penumpang) {
                pesawat q = p[i];
                p[i] = p[j];
                p[j] = q;
            }
}

void bubble_sort_desc_str(pesawat p[]) {
    int i, j;
    for (i = 0; i < N; i++)
        for (j = i + 1; j < N; j++)
            if (strcmp(p[i].kode_pesawat, p[j].kode_pesawat) < 0) {
                pesawat q = p[i];
                p[i] = p[j];
                p[j] = q;
            }
}

int binary_search_int(pesawat p[], int left, int right, int data) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (p[mid].jumlah_penumpang == data)
            return mid;
        if (p[mid].jumlah_penumpang < data)
            return binary_search_int(p, left, mid - 1, data);
        return binary_search_int(p, mid + 1, right, data);
    }
    return -1;
}

int binary_search_str(pesawat p[], int left, int right, string data) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (strcmp(p[mid].kode_pesawat, data) == 0)
            return mid;
        if (strcmp(p[mid].kode_pesawat, data) < 0)
            return binary_search_str(p, left, mid - 1, data);
        return binary_search_str(p, mid + 1, right, data);
    }
    return -1;
}

int sequential_search(pesawat p[], int data) {
    int i;
    for (i = 0; i < N; i++)
        if (p[i].jumlah_penumpang == data)
            return i;
    return -1;
}

void generate_characters(char c[]) {
    int i;
    char characters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    for (i = 0; i < 10; i++) {
        char ctmp = characters[rand() % 26];
        if (ctmp == 'g' || ctmp == 'm' || ctmp == 'j' || ctmp == 'o' || ctmp == 'x' || !is_char_unique(c, ctmp))
            i--;
        else
            c[i] = ctmp;
    }
}

bool is_char_unique(char c[], char key) {
    int i;
    for (i = 0; i < 10; i++)
        if (c[i] == key)
            return 0;
    return 1;
}

int find_char(char c[], char key) {
    int i;
    for (i = 0; i < 10; i++)
        if (c[i] == key)
            return i;
    return -1;
}
