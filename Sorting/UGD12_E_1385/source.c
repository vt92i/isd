#include "header.h"

void init_empty(array *a) {
    a->end = -1;
}

int is_empty(array a) {
    return a.end == -1;
}

void print_info(array a) {
    int i;
    for (i = 0; i <= a.end; i++) {
        printf("Nama Makanan : %s \n", a.r[i].nama_makanan);
        printf("Harga : %d \n", a.r[i].harga);
        printf("Order ID : %d \n", a.r[i].order_id);
        printf("\n");
    }
}

void bubble_sort(array *a) {
    int i, j;
    for (i = 0; i <= (*a).end - 1; i++)
        for (j = i + 1; j <= (*a).end; j++)
            if ((*a).r[i].harga < (*a).r[j].harga) {
                resto r_tmp = a->r[i];
                a->r[i] = a->r[j];
                a->r[j] = r_tmp;
            }
}

void merge_sort(array *a) {
    array t;
    if (length(*a) > 1) {
        part_into2(&(*a), &t);
        merge_sort(&(*a));
        merge_sort(&t);
        merge(&(*a), t);
    }
}

void add(array *a, resto x) {
    a->end++;
    a->r[a->end] = x;
}

int length(array a) {
    return (a.end + 1);
}

array clone_array(array a) {
    int i;
    array temp;
    for (i = 0; i <= a.end; i++)
        temp.r[i] = a.r[i];

    temp.end = a.end;
    return temp;
}

void part_into2(array *a, array *a2) {
    int i, len = length(*a);
    (*a).end = len / 2 + len % 2 - 1;
    (*a2).end = len - length(*a) - 1;
    for (i = 0; i <= (*a2).end; i++) {
        (*a2).r[i] = (*a).r[i + length(*a)];
    }
}

void merge(array *a, array t) {
    array temp;
    init_empty(&temp);
    int i = 0, j = 0, k;
    while (i <= (*a).end && j <= t.end) {
        if (strcmp(a->r[i].nama_makanan, t.r[j].nama_makanan) < 0) {
            add(&temp, (*a).r[i]);
            i++;
        } else {
            add(&temp, t.r[j]);
            j++;
        }
    }
    if (i > (*a).end) {
        for (k = j; k <= t.end; k++) {
            add(&temp, t.r[k]);
        }
    } else {
        for (k = i; k <= (*a).end; k++) {
            add(&temp, (*a).r[k]);
        }
    }
    (*a) = temp;
}

void quick_sort(array *a, int start, int end) {
    int i = start, j = end;
    int pivot = (*a).r[(start + end) / 2].order_id;
    while (i <= j) {
        while ((*a).r[i].order_id < pivot)
            i++;
        while ((*a).r[j].order_id > pivot)
            j--;
        if (i <= j) {
            resto r_tmp = a->r[i];
            a->r[i] = a->r[j];
            a->r[j] = r_tmp;
            i++;
            j--;
        }
    }
    if (start < j)
        quick_sort(&(*a), start, j);
    if (i < end)
        quick_sort(&(*a), i, end);
}

int find_by_id(array arr, int id) {
    int i;
    for (i = 0; i <= arr.end; i++) {
        if (arr.r[i].order_id == id) return i;
    }
    return -1;
}

void cleanup(array *arr, int index) {
    int i;

    array x;
    init_empty(&x);

    for (i = 0; i <= arr->end; i++) {
        if (i != index) {
            x.end++;
            x.r[x.end] = arr->r[i];
        }
    }
    *arr = x;
}
