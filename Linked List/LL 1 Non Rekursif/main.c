#include "header.h"

int main(int argc, char *argv[]) {
    int data;
    int menu = -1;
    List myList;
    address cari;
    inisialisasi(&myList);

    do {
        system("cls");
        printf("\n---=== Menu ===---\n");
        printf("1. Insert First\n");
        printf("2. Insert Last\n");
        printf("3. Delete First\n");
        printf("4. Delete Last\n");
        printf("5. Delete All Data\n");
        printf("6. Show List\n");
        printf("7. Cari Data\n");
        printf("0. Exit\n");

        printf(">>> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\nMasukan Data : ");
                scanf("%d", &data);
                insertFirst(&myList, data);
                break;

            case 2:
                printf("\nMasukan Data : ");
                scanf("%d", &data);
                insertLast(&myList, data);
                break;

            case 3:
                deleteFirst(&myList);
                break;

            case 4:
                deleteLast(&myList);
                break;

            case 5:
                deleteAll(&myList);
                break;

            case 6:
                showList(myList);
                break;

            case 7:
                printf("\nMasukan Data : ");
                scanf("%d", &data);
                Node *d = cariData(myList, data);

                if (d == NULL) {
                    printf("\nNULL, data tidak ditemukan!\n");
                    break;
                }

                printf("\nAddress : %x \n", d);
                printf("Value : %d \n", d->data);
                break;

            case 0:
                printf("\nExit...\n");
                break;

            default:
                printf("\nMenu tidak tersedia!\n");
                break;
        }
        getch();
    } while (menu != 0);
    return 0;
}
