#include "header.h"

int main(void) {
    array_type arr_a, arr_b;
    init_array(arr_a);

    int menu, data, index;

    do {
        system("cls");

        printf("\n===== GUIDED SEARCHING =====");
        printf("\n[ Core ]");
        printf("\n[1]. Generate Number");
        printf("\n[2]. Sequential Search");
        printf("\n[3]. Binary Search");
        printf("\n[0]. Exit");

        printf("\n>>> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\n[ Generate Number ]\n");
                if (is_full(arr_a)) init_array(arr_a);
                insert_random(arr_a);
                print_array(arr_a);
                break;

            case 2:
                printf("\n[ Sequential Search ]\n");

                if (is_empty(arr_a)) {
                    printf("\nArray is empty!");
                    break;
                }

                print_array(arr_a);
                printf("\nInput Data: ");
                scanf("%d", &data);

                index = sequential_search(arr_a, data);
                if (index == -1)
                    printf("\nData not found!");
                else
                    printf("\nData found at index %d", index);
                break;

            case 3:
                printf("\n[ Binary Search ]\n");

                if (is_empty(arr_a)) {
                    printf("\nArray is empty!");
                    break;
                }

                print_array(arr_a);
                copy_array(arr_a, arr_b);
                bubble_sort(arr_b);
                print_array(arr_b);
                printf("\nInput Data: ");
                scanf("%d", &data);

                index = binary_search(arr_b, 0, N - 1, data);
                if (index == -1)
                    printf("\nData not found!");
                else
                    printf("\nData found at index %d", index);
                break;

            case 0:
                printf("\nNama  : Benidiktus Violaz Morello Anjolie");
                printf("\nNPM   : 210711385");
                printf("\nKelas : ISD E");
                printf("\nGood Luck!\n");
                break;

            default:
                printf("\nMenu tidak tersedia!\n");
                break;
        }

        getch();
    } while (menu != 0);

    return 0;
}
