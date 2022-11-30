#include "header.h"

int main(void) {
    binary_tree bt;
    init_empty(&bt);

    int menu, p;
    string jenis_mobil, merk_mobil, warna_mobil;

    int index = 0;
    mobil m[ARRAY_LENGTH];
    init_mobil(m, 0);

    binary_tree bt_bin;
    init_empty(&bt_bin);
    int bin;

    do {
        system("cls");

        printf("\n===== UNGUIDED BINARY TREE =====");
        printf("\n[ Core ]");
        printf("\n1. Input Mobil");
        printf("\n2. Input BST");
        printf("\n3. Read");
        printf("\n4. Delete\n");

        printf("\n[ Utility ]");
        printf("\n5. Input Binary");
        printf("\n6. Print Tree");

        printf("\n------------------------------------------------");
        printf("\n0. Exit");

        printf("\n>>> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\n[ Input Mobil ]\n");

                m[index].key = index;

                while (1) {
                    printf("Input Jenis Mobil : ");
                    fflush(stdin);
                    gets(jenis_mobil);

                    if (is_unique(m, jenis_mobil, 0)) {
                        strcpy(m[index].jenis_mobil, jenis_mobil);
                        break;
                    }
                }

                while (1) {
                    printf("Input Merk Mobil : ");
                    fflush(stdin);
                    gets(m[index].merk_mobil);

                    if (strlen(m[index].merk_mobil) > 0) break;
                }

                while (1) {
                    printf("Input Warna Mobil : ");
                    fflush(stdin);
                    gets(m[index].warna_mobil);

                    if (strlen(m[index].warna_mobil) > 0) break;
                }

                index++;
                sort_array(m, ARRAY_LENGTH);

                break;

            case 2:
                printf("\n[ Input BST ]\n");

                while (1) {
                    printf("Input Jenis Mobil : ");
                    fflush(stdin);
                    gets(jenis_mobil);

                    if (strlen(jenis_mobil) > 0) break;
                }

                p = find_car(m, 0, jenis_mobil);
                if (p != -1) {
                    insert_tree_bst(&bt, allocate_data(m[p].key, m[p].jenis_mobil, m[p].merk_mobil, m[p].warna_mobil));
                    printf("\nOK!\n");
                } else
                    printf("\nError!\n");

                break;

            case 3:
                printf("\n[ Read ]\n");

                printf("\n[ Data Array ]\n");
                print_array(m, 0);

                printf("\n[ Data BST ]\n");
                if (is_empty(bt)) {
                    printf("\nEmpty Binary Tree\n");
                    break;
                }

                printf("\n[ Pre Order ]\n");
                preoder(bt);

                printf("\n[ In Order ]\n");
                inorder(bt);

                printf("\n[ Post Order ]\n");
                postorder(bt);

                break;

            case 4:
                printf("\n[ Delete ]\n");

                if (is_empty(bt)) {
                    printf("\nEmpty Binary Tree\n");
                    break;
                }

                printf("Input Jenis Mobil : ");
                fflush(stdin);
                gets(jenis_mobil);

                if (!is_found(bt, jenis_mobil)) {
                    printf("\nNo Data Found!\n");
                    break;
                }

                delete_tree_at(&bt, jenis_mobil);

                break;

            case 5:
                printf("\n[ Input Binary ]\n");

                while (1) {
                    printf("Input Binary : ");
                    scanf("%d", &bin);

                    if (bin > 0) break;
                }

                printf("Decimal : %d \n", bin2dec(bin));
                insert_tree_bst(&bt_bin, allocate_data(bin2dec(bin), "", "", ""));
                break;

            case 6:
                printf("\n[ Print Tree ]\n");
                print_tree(bt_bin, 0);
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
