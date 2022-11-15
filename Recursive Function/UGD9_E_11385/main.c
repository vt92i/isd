#include "header.h"

int main(void) {
    srand(time(NULL));

    perusahaan p[MAX_ARRAY], q[MAX_ARRAY], tmp;
    perusahaan pq[MAX_ARRAY], pk[MAX_ARRAY];
    init(p, 0);
    int menu, index, day, f;

    do {
        system("cls");

        printf("\n==== ASX =====");
        printf("\n[ Core ]");
        printf("\n1. Input Perusahaan");
        printf("\n2. Tampil Perusahaan");
        printf("\n3. Edit Harga Saham");
        printf("\n4. Statistik Saham Satu Hari");

        printf("\n[ Utility]");
        printf("\n5. Simulasi Harga Saham");
        printf("\n6. Hari Terbaik & Terburuk Satu Perusahaan");
        printf("\n7. Sorting Perusahaan\n");

        printf("\n------------------------------------------------");
        printf("\n0. Exit");

        printf("\n>>> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\n[ Input Perusahaan ]\n");

                index = get_empty_index(p, 0);
                if (index == -1) {
                    printf("\nData sudah penuh!\n");
                    break;
                }

                while (true) {
                    printf("Kode : ");
                    fflush(stdin);
                    gets(tmp.kode);
                    if (strlen(tmp.kode) != 0) break;
                }

                while (true) {
                    printf("Status (Umum/Swasta) : ");
                    fflush(stdin);
                    gets(tmp.status);
                    if (strcmp(tmp.status, "Umum") == 0 || strcmp(tmp.status, "Swasta") == 0) break;
                }

                while (true) {
                    printf("Nama : ");
                    fflush(stdin);
                    gets(tmp.nama);
                    if (strlen(tmp.nama) != 0) break;
                }

                input_stockprice(&tmp, 0);

                p[index] = tmp;
                printf("\nData berhasil disimpan!\n");
                break;

            case 2:
                printf("\n[ Tampil Perusahaan ]\n");
                if (is_empty(p, 0)) {
                    printf("\nData masih kosong!\n");
                    break;
                }
                print_all(p, 0);
                break;

            case 3:
                printf("\n[ Edit Harga Saham ]\n");
                if (is_empty(p, 0)) {
                    printf("\nData masih kosong!\n");
                    break;
                }

                while (true) {
                    printf("Kode : ");
                    fflush(stdin);
                    gets(tmp.kode);
                    if (strlen(tmp.kode) != 0) break;
                }

                index = find(p, 0, tmp.kode);
                if (index == -1) break;

                printf("History Stock Price : \n");

                tmp = p[index];
                input_stockprice(&tmp, 0);
                p[index] = tmp;

                printf("\nData berhasil disimpan!\n");
                break;

            case 4:
                printf("\n[ Statistik Saham Satu Hari ]\n");
                if (is_empty(p, 0)) {
                    printf("\nData masih kosong!\n");
                    break;
                }

                while (true) {
                    printf("Hari : ");
                    scanf("%d", &day);
                    if (day >= 1 && 7 >= day) break;
                }

                init(q, 0);
                statistik_satu_hari(p, 0, day, q);
                break;

            case 5:
                printf("\n[ Simulasi Harga Saham ]\n");

                while (true) {
                    printf("Harga Saham Awal : ");
                    scanf("%d", &f);
                    if (f > 0) break;
                }

                simulasi(f, 1, (rand() % (15 - 7)) + 7);
                break;

            case 6:
                printf("\n[ Hari Terbaik & Terburuk Satu Perusahaan ]\n");
                if (is_empty(p, 0)) {
                    printf("\nData masih kosong!\n");
                    break;
                }

                while (true) {
                    printf("Kode : ");
                    fflush(stdin);
                    gets(tmp.kode);
                    if (strlen(tmp.kode) != 0) break;
                }

                index = find(p, 0, tmp.kode);
                if (index == -1) break;

                best_worst(p[index]);

                break;

            case 7:
                printf("\n[ Sorting Perusahaan ]\n");
                if (is_empty(p, 0)) {
                    printf("\nData masih kosong!\n");
                    break;
                }

                sort_by_status(p, pq, pk, 0);

                printf("\n[ Perusahaan Umum ]");
                if (is_empty(pq, 0))
                    printf("\nNo Data!\n");
                else
                    print_all(pq, 0);

                printf("\n[ Perusahaan Swasta ]");
                if (is_empty(pk, 0))
                    printf("\nNo Data!\n");
                else
                    print_all(pk, 0);
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
