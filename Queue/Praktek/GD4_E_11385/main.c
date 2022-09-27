#include "header.h"

int main(void) {
    Queue Q;
    Mahasiswa M;

    int menu, index;

    init(&Q);

    do {
        system("cls");

        printf("\n==== GUIDED QUEUE (ARRAY IMPLEMENTATION) =====");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Print");
        printf("\n4. Cari Data");
        printf("\n------------------------------------------------");
        printf("\n0. Exit");

        printf("\n>>> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                if (!is_full(Q)) {
                    printf("\n[ Input Data ]\n");
                    printf("Nama : ");
                    fflush(stdin);
                    gets(M.nama);
                    printf("NPM : ");
                    fflush(stdin);
                    gets(M.npm);
                    printf("IPK : ");
                    scanf("%f", &M.ipk);

                    enqueue(&Q, make_mahasiswa(M.nama, M.npm, M.ipk));
                    printf("\nInput data berhasil!\n");
                } else {
                    printf("\nQueue sudah penuh!\n");
                }
                break;

            case 2:
                if (!is_empty(Q))
                    dequeue(&Q);
                else
                    printf("\nQueue masih kosong!\n");
                break;

            case 3:
                if (!is_empty(Q))
                    print(Q);
                else
                    printf("\nQueue masih kosong!\n");
                break;

            case 4:
                if (!is_empty(Q)) {
                    printf("\n[ Cari Data]\n");
                    printf("Input NPM : ");
                    fflush(stdin);
                    gets(M.npm);

                    index = find_data_by_npm(Q, M.npm);
                    if (index != -1) {
                        printf("\n[ Data Ditemukan ]\n");
                        printf("Nama : %s\n", Q.M[index].nama);
                        printf("NPM : %s\n", Q.M[index].npm);
                        printf("IPK : %.2f\n", Q.M[index].ipk);
                    } else
                        printf("\nData tidak ditemukan!\n");
                } else
                    printf("\nQueue masih kosong!\n");

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
