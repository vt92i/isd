#include "header.h"

int main(void) {
    List L;
    Data D;

    int menu;

    string nama_dosen;
    int npp;

    init_list(&L);

    do {
        system("cls");

        printf("\n\n==== GUIDED LINKED LIST =====");
        printf("\n1. Insert First");
        printf("\n2. Insert Last");
        printf("\n3. Delete First");
        printf("\n4. Delete Last");
        printf("\n5. Print List");
        printf("\n6. Find Dosen by NPP");
        printf("\n------------------------------------------------");
        printf("\n0. Exit");

        printf("\n>>> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\n[ Input Data ]\n");

                while (true) {
                    printf("Nama Dosen : ");
                    fflush(stdin);
                    gets(nama_dosen);

                    if (strlen(nama_dosen) != 0) break;
                }

                while (true) {
                    printf("NPP Dosen : ");
                    scanf("%d", &npp);

                    if (npp > 0) break;
                }

                D = make_data(nama_dosen, npp);
                insert_first(&L, D);

                break;

            case 2:
                printf("\n[ Input Data ]\n");

                while (true) {
                    printf("Nama Dosen : ");
                    fflush(stdin);
                    gets(nama_dosen);

                    if (strlen(nama_dosen) != 0) break;
                }

                while (true) {
                    printf("NPP Dosen : ");
                    scanf("%d", &npp);

                    if (npp > 0) break;
                }

                D = make_data(nama_dosen, npp);
                insert_last(&L, D);

                break;

            case 3:
                delete_first(&L);
                break;

            case 4:
                delete_last(&L);
                break;

            case 5:
                print_list(L);
                break;

            case 6:
                if (is_empty(L)) {
                    printf("\nList kosong!\n");
                    break;
                }

                printf("\n[ Input Data ]\n");

                printf("NPP Dosen : ");
                scanf("%d", &npp);

                Data *d = find_dosen_by_npp(L, npp);
                if (d == NULL)
                    printf("\nData tidak ditemukan!\n");
                else {
                    printf("\n");
                    printf("Nama Dosen : %s\n", d->nama);
                    printf("NPP : %d\n", d->npp);
                }
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
