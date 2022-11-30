#include "header.h"

void sort_array(mobil m[], int n) {
    if (n == 1) return;
    int count = 0;

    void for_recursion(int i) {
        if (i > ARRAY_LENGTH - 1) return;

        if (strcmp(m[i].jenis_mobil, m[i + 1].jenis_mobil) > 0) {
            mobil temp = m[i];
            m[i] = m[i + 1];
            m[i + 1] = temp;
            count++;
        }

        for_recursion(i + 1);
    }
    for_recursion(0);

    if (count == 0) return;
    sort_array(m, n - 1);
}

void print_array(mobil m[], int index) {
    if (index > ARRAY_LENGTH - 1) return;

    if (strcmp(m[index].jenis_mobil, "") == 0)
        print_array(m, index + 1);
    else {
        printf("Jenis Mobil : %s \n", m[index].jenis_mobil);
        printf("Merk Mobil : %s \n", m[index].merk_mobil);
        printf("Warna Mobil : %s \n\n", m[index].warna_mobil);
        print_array(m, index + 1);
    }
}

int main(void) {
    binary_tree bt;
    init_empty(&bt);

    int menu;
    string jenis_mobil, merk_mobil, warna_mobil;
    // address pp, qq;

    mobil m[ARRAY_LENGTH];
    int index = 0;

    init_mobil(m, 0);

    do {
        system("cls");

        printf("\n===== UNGUIDED BINARY TREE =====");
        printf("\n[ Core ]");
        printf("\n1. Input Mobil");
        printf("\n2. Input BST");
        printf("\n3. Read");
        printf("\n4. Delete");

        printf("\n------------------------------------------------");
        printf("\n0. Exit");

        printf("\n>>> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\n[ Input Mobil ]\n");

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
                insert_tree_bst(&bt, m, 0);
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

                printf("\nPre Order : ");
                preoder(bt);

                printf("\nIn Order : ");
                inorder(bt);

                printf("\nPost Order : ");
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
