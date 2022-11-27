#include "header.h"

int main(void) {
    binary_tree bt;
    init_empty(&bt);

    int menu, hp;
    string jenis_pokemon, p, q;
    address pp, qq;

    do {
        system("cls");

        printf("\n===== GUIDED BINARY TREE =====");
        printf("\n[ Core ]");
        printf("\n1. Insert");
        printf("\n2. Print");
        printf("\n3. Update");
        printf("\n4. Delete");

        printf("\n------------------------------------------------");
        printf("\n0. Exit");

        printf("\n>>> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\n[ Insert ]\n");

                printf("Input Jenis Pokemon : ");
                fflush(stdin);
                gets(jenis_pokemon);

                printf("Input HP Pokemon : ");
                scanf("%d", &hp);

                pp = allocate_data(hp, jenis_pokemon);
                insert_tree_bst(&bt, pp);

                break;

            case 2:
                printf("\n[ Print ]\n");

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

            case 3:
                printf("\n[ Update ]\n");

                if (is_empty(bt)) {
                    printf("\nEmpty Binary Tree\n");
                    break;
                }

                printf("Input Old Jenis Pokemon : ");
                fflush(stdin);
                gets(p);

                if (!is_found(bt, p)) {
                    printf("\nNo Data Found!\n");
                    break;
                }

                printf("\nInput New Jenis Pokemon : ");
                fflush(stdin);
                gets(q);

                update_tree(&bt, p, q);

                break;

            case 4:
                printf("\n[ Delete ]\n");

                if (is_empty(bt)) {
                    printf("\nEmpty Binary Tree\n");
                    break;
                }

                printf("Input Jenis Pokemon : ");
                fflush(stdin);
                gets(p);

                if (!is_found(bt, p)) {
                    printf("\nNo Data Found!\n");
                    break;
                }

                delete_tree_at(&bt, p);

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
