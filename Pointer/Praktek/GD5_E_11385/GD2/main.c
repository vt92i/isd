#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int arr[5], i;
    int *arr_ptr;

    for (i = 0; i < 5; i++)
        arr[i] = i + 3;

    arr_ptr = arr;

    for (i = 0; i < 5; i++) {
        printf("\nAlamat dari elemen ke-%d adalah %x dan valuenya adalah %d", i + 1, arr_ptr, *arr_ptr);
        arr_ptr++;
    }

    printf("\n\n");
    while (1) {
        printf("Masukan index yang ingin diubah (0-4) : ");
        scanf("%d", &i);

        if (!(i >= 0 && i <= 4)) continue;

        arr_ptr = &arr[i];
        break;
    }

    printf("Masukan value baru : ");
    scanf("%d", arr_ptr);
    printf("\nAlamat dari elemen yang diubah adalah [ %x ] dan valenya adalah [ %d ]\n", arr_ptr, *arr_ptr);

    return 0;
}
