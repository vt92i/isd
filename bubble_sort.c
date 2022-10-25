#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY 5

int generate_random_number(int min, int max) {
    return rand() % ((max + 1) - min) + min;
}

void print_array(int arr[MAX_ARRAY]) {
    for (int i = 0; i < MAX_ARRAY; i++) {
        printf("| %d ", arr[i]);
        if (i == MAX_ARRAY - 1)
            printf("|\n");
    }
}

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void bubble_sort(int arr[MAX_ARRAY]) {
    for (int i = 0; i < MAX_ARRAY; i++) {
        for (int j = 0; j < MAX_ARRAY - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

int main(void) {
    int arr[MAX_ARRAY] = {0};
    srand(time(0));

    for (int i = 0; i < MAX_ARRAY; i++) {
        arr[i] = generate_random_number(10, 100);
    }

    printf("\n[ Unsorted ]\n");
    print_array(arr);

    bubble_sort(arr);

    printf("\n[ Sorted ]\n");
    print_array(arr);

    return 0;
}
