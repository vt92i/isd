#include "header.h"

int main(void) {
    List L;
    address D, prev_node;

    infotype number;
    int menu;

    init_empty(&L);

    do {
        system("cls");

        printf("\n\n==== GUIDED LINKED LIST 2=====");
        printf("\n1. Insert First");
        printf("\n2. Insert After");
        printf("\n3. Insert Last");
        printf("\n4. Delete First");
        printf("\n5. Delete At");
        printf("\n6. Delete Last");
        printf("\n7. Print List");
        printf("\n------------------------------------------------");
        printf("\n0. Exit");

        printf("\n>>> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\n[ Input Data ]\n");

                printf("Input Number : ");
                scanf("%d", &number);

                D = allocate_data(number);
                insert_first(&L, D);
                printf("\n[ Insert First ]\n");
                break;

            case 2:
                printf("\n[ Input Data ]\n");

                printf("Input Number After : ");
                scanf("%d", &number);

                prev_node = find_node(L, number);
                if (prev_node == NULL) {
                    printf("Data tidak ditemukan!\n");
                    break;
                }

                printf("Input Number : ");
                scanf("%d", &number);

                D = allocate_data(number);
                insert_after(prev_node, D);

                printf("\n[ Insert After ]\n");
                break;

            case 3:
                printf("\n[ Input Data ]\n");

                printf("Input Number : ");
                scanf("%d", &number);

                D = allocate_data(number);
                insert_last(&L, D);
                printf("\n[ Insert Last ]\n");
                break;

            case 4:
                if (is_empty(L)) {
                    printf("List kosong!\n");
                    break;
                }

                delete_first(&L);
                printf("\n[ Delete First ]\n");
                break;

            case 5:
                if (is_empty(L)) {
                    printf("List kosong!\n");
                    break;
                }

                printf("Input Number to be deleted : ");
                scanf("%d", &number);

                D = find_node(L, number);
                if (D == NULL) {
                    printf("Data tidak ditemukan!\n");
                    break;
                }

                delete_at(&L, D);
                printf("\n[ Delete At ]\n");
                break;

            case 6:
                if (is_empty(L)) {
                    printf("List kosong!\n");
                    break;
                }

                delete_last(&L);
                printf("\n[ Delete Last ]\n");
                break;

            case 7:
                if (is_empty(L)) {
                    printf("List kosong!\n");
                    break;
                }

                print_list(L);
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
