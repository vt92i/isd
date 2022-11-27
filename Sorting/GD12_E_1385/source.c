#include "header.h"

void init_empty(array *a) {
    a->end = -1;
}

int is_empty(array a) {
    return a.end == -1;
}

void set_array(array *a, int n) {
    int i;
    init_empty(a);
    for (i = 0; i < n; i++) {
        printf("Masukkan data ke %d : ", i + 1);
        scanf("%d", &a->t[i]);
    }
    a->end = n - 1;
}

void print_info(array a) {
    int i;
    for (i = 0; i <= a.end; i++)
        printf("%d ", a.t[i]);
}

void bubble_sort(array *a) {
    int i, j;
    for (i = 0; i <= (*a).end - 1; i++)
        for (j = i + 1; j <= (*a).end; j++)
            if ((*a).t[i] > (*a).t[j])
                swap(&(*a).t[i], &(*a).t[j]);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
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

void add(array *a, int x) {
    a->end++;
    a->t[a->end] = x;
}

int length(array a) {
    return (a.end + 1);
}

array clone_array(array a) {
    int i;
    array temp;
    for (i = 0; i <= a.end; i++)
        temp.t[i] = a.t[i];

    temp.end = a.end;
    return temp;
}

void part_into2(array *a, array *a2) {
    int i, len = length(*a);
    (*a).end = len / 2 + len % 2 - 1;
    (*a2).end = len - length(*a) - 1;
    for (i = 0; i <= (*a2).end; i++) {
        (*a2).t[i] = (*a).t[i + length(*a)];
    }
}

void merge(array *a, array t) {
    array temp;
    init_empty(&temp);
    int i = 0, j = 0, k;
    while (i <= (*a).end && j <= t.end) {
        if ((*a).t[i] < t.t[j]) {
            add(&temp, (*a).t[i]);
            i++;
        } else {
            add(&temp, t.t[j]);
            j++;
        }
    }
    if (i > (*a).end) {
        for (k = j; k <= t.end; k++) {
            add(&temp, t.t[k]);
        }
    } else {
        for (k = i; k <= (*a).end; k++) {
            add(&temp, (*a).t[k]);
        }
    }
    (*a) = clone_array(temp);
}

void quick_sort(array *a, int start, int end) {
    int i = start, j = end;
    int pivot = (*a).t[(start + end) / 2];
    while (i <= j) {
        while ((*a).t[i] < pivot)
            i++;
        while ((*a).t[j] > pivot)
            j--;
        if (i <= j) {
            swap(&(*a).t[i], &(*a).t[j]);
            i++;
            j--;
        }
    }
    if (start < j)
        quick_sort(&(*a), start, j);
    if (i < end)
        quick_sort(&(*a), i, end);
}
