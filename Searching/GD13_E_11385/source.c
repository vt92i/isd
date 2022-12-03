#include "header.h"

int is_empty(array_type arr) {
    return arr[0] == 0;
}

int is_full(array_type arr) {
    return arr[N - 1] != 0;
}

int is_unique(array_type arr, key_type key) {
    int i;
    for (i = 0; i < N; i++)
        if (arr[i] == key)
            return 0;
    return 1;
}

void init_array(array_type arr) {
    int i;
    for (i = 0; i < N; i++)
        arr[i] = 0;
}

void print_array(array_type arr) {
    int i;
    for (i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void copy_array(array_type arr1, array_type arr2) {
    int i;
    for (i = 0; i < N; i++)
        arr2[i] = arr1[i];
}

void bubble_sort(array_type arr) {
    int i, j;
    for (i = 0; i < N; i++)
        for (j = i + 1; j < N; j++)
            if (arr[i] > arr[j])
                swap(&arr[i], &arr[j]);
}

void swap(key_type *a, key_type *b) {
    key_type temp = *a;
    *a = *b;
    *b = temp;
}

int binary_search(array_type arr, int left, int right, info_type data) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == data)
            return mid;
        if (arr[mid] > data)
            return binary_search(arr, left, mid - 1, data);
        return binary_search(arr, mid + 1, right, data);
    }
    return -1;
}

int sequential_search(array_type arr, info_type data) {
    int i;
    for (i = 0; i < N; i++)
        if (arr[i] == data)
            return i;
    return -1;
}

void insert_random(array_type arr) {
    int i, num;
    srand(time(NULL));
    for (i = 0; i < N; i++) {
        num = rand() % 70 + 1;
        arr[i] = is_unique(arr, num) ? num : i--;
    }
}
