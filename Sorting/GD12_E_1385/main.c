#include "header.h"

int main(void) {
    array a, temp;
    int jumlah_elemen, menu;

    init_empty(&a);

    do {
        system("cls");

        printf("\n===== GUIDED SORTING =====");
        printf("\n[ Core ]");
        printf("\n[1]. Set Array");
        printf("\n[2]. Print Array");
        printf("\n[3]. Bubble Sort");
        printf("\n[4]. Merge Sort");
        printf("\n[5]. Quick Sort");
        printf("\n[0]. Exit");

        printf("\n>>> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\n[ Set Array ]\n");

                printf("\nJumlah Elemen Yang Ingin Ditampung : ");
                scanf("%d", &jumlah_elemen);
                set_array(&a, jumlah_elemen);
                break;

            case 2:
                printf("\n[ Print Array ]\n");

                printf("\nTampil Array Unsorted : ");
                print_info(a);
                break;

            case 3:
                printf("\n[ Bubble Sort ]\n");

                temp = clone_array(a);
                printf("\nTampil Array Sebelum Sorting (Bubble Sort) : ");
                print_info(temp);
                printf("\nTampil Array Sesudah Sorting (Bubble Sort) : ");
                bubble_sort(&temp);
                print_info(temp);
                break;

            case 4:
                printf("\n[ Merge Sort ]\n");

                temp = clone_array(a);
                printf("\nTampil Array Sebelum Sorting (Merge Sort) : ");
                print_info(temp);
                printf("\nTampil Array Sesudah Sorting (Merge Sort) : ");
                merge_sort(&temp);
                print_info(temp);
                break;

            case 5:
                printf("\n[ Quick Sort ]\n");

                temp = clone_array(a);
                printf("\nTampil Array Sebelum Sorting (Quick Sort) : ");
                print_info(temp);
                printf("\nTampil Array Sesudah Sorting (Quick Sort) : ");
                quick_sort(&temp, 0, temp.end);
                print_info(temp);
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
