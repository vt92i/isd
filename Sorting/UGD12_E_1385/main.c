#include "header.h"

int main(void) {
    array a, b;
    int order_id, menu;

    init_empty(&a);
    init_empty(&b);

    int index;

    do {
        system("cls");

        printf("\n===== UNGUIDED SORTING =====");
        printf("\n[ Core ]");
        printf("\n[1]. Tambah Data");
        printf("\n[2]. Print Array");
        printf("\n[3]. Pembayaran");

        printf("\n\n[ Core ]");
        printf("\n[4]. Quick Sort Order ID");
        printf("\n[5]. Merge Sort Nama Makanan");
        printf("\n[6]. Bubble Sort Harga");

        printf("\n[0]. Exit");

        printf("\n>>> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\n[ Tambah Data ]\n");

                a.end++;
                printf("Nama Makanan : ");
                fflush(stdin);
                gets(a.r[a.end].nama_makanan);

                printf("Harga : ");
                scanf("%d", &a.r[a.end].harga);

                printf("Order ID : ");
                scanf("%d", &a.r[a.end].order_id);

                break;

            case 2:
                printf("\n[ Print Array ]\n");

                printf("\n[ Array A ]\n");
                print_info(a);

                printf("\n[ Array B ]\n");
                print_info(b);
                break;

            case 3:
                printf("\n[ Pembayaran ]\n");

                printf("Order ID : ");
                scanf("%d", &order_id);

                index = find_by_id(a, order_id);

                if (index != -1) {
                    b.end++;
                    b.r[b.end] = a.r[index];

                    cleanup(&a, index);

                    printf("\nOK!\n");
                } else {
                    printf("\nFailed!\n");
                }

                break;

            case 4:
                printf("\n[ Quick Sort Order ID ]\n");

                quick_sort(&a, 0, a.end);
                quick_sort(&b, 0, b.end);

                break;

            case 5:
                printf("\n[ Merge Sort Nama Makanan]\n");

                merge_sort(&a);
                merge_sort(&b);

                break;

            case 6:
                printf("\n[ Bubble Sort Harga]\n");

                bubble_sort(&a);
                bubble_sort(&b);

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
