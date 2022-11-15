#include "header.h"

int main(void) {
    list l;
    init_empty(&l);

    address target_node;
    int menu, data, prev;

    do {
        system("cls");

        printf("\n==== GUIDED RECURSIVE LIST =====");
        printf("\n[ Core ]");
        printf("\n1. Insert First");
        printf("\n2. Insert After");
        printf("\n3. Insert Last");
        printf("\n4. Delete First");
        printf("\n5. Delete At");
        printf("\n6. Delete Last\n");

        printf("\n[ Utility]");
        printf("\n7. Find Node");
        printf("\n8. Print List\n");

        printf("\n------------------------------------------------");
        printf("\n0. Exit");

        printf("\n>>> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\n[ Insert First ]\n");
                printf("Input Data : ");
                scanf("%d", &data);
                insert_first(&l, allocate_data(data));
                break;

            case 2:
                printf("\n[ Insert After ]\n");

                printf("Input Data : ");
                scanf("%d", &data);

                printf("Input Prev : ");
                scanf("%d", &prev);

                insert_after(&l, allocate_data(data), prev);
                break;

            case 3:
                printf("\n[ Insert Last ]\n");
                printf("Input Data : ");
                scanf("%d", &data);
                insert_last(&l, allocate_data(data));
                break;

            case 4:
                printf("\n[ Delete First ]\n");
                delete_first(&l);
                break;

            case 5:
                printf("\n[ Delete At ]\n");
                printf("Input Data : ");
                scanf("%d", &data);

                target_node = find_node(l, data);
                if (target_node != NULL)
                    delete_at(&l, target_node);
                else
                    printf("\nNo Data!\n");

                break;

            case 6:
                printf("\n[ Delete Last ]\n");
                delete_last(&l);
                break;

            case 7:
                printf("\n[ Find Node ]\n");
                printf("Input Data : ");
                scanf("%d", &data);

                target_node = find_node(l, data);
                if (target_node != NULL)
                    printf("\nData Found!\n");
                else
                    printf("\nNo Data!\n");

                break;

            case 8:
                printf("\n[ Print List ]\n");
                print_list(l);
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
