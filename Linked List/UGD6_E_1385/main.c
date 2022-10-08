#include "header.h"

int main(void) {
    List L, L_riwayat;
    Data D;

    int menu;

    string nama, jenis;
    int berat, harga, uang;

    init_list(&L);
    init_list(&L_riwayat);

    do {
        system("cls");

        printf("\n\n==== GUIDED LINKED LIST =====");
        printf("\n1. Input Laundry");
        printf("\n2. Bayar Laundry");
        printf("\n3. Tampil Laundry");
        printf("\n4. Tampil Laundry Satuan");
        printf("\n------------------------------------------------");
        printf("\n5. Bayar Modifikasi");
        printf("\n6. Riwayat Laundry");
        printf("\n------------------------------------------------");
        printf("\n0. Exit");

        printf("\n>>> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\n[ Input Data ]\n");

                while (true) {
                    printf("Nama : ");
                    fflush(stdin);
                    gets(nama);

                    if (strlen(nama) != 0) break;
                }

                while (true) {
                    printf("Jenis (Kilat/Biasa): ");
                    fflush(stdin);
                    gets(jenis);

                    if (strcmp(jenis, "Kilat") == 0 || strcmp(jenis, "Biasa") == 0) break;
                }

                while (true) {
                    printf("Berat : ");
                    scanf("%d", &berat);

                    if (berat > 0) break;
                }

                if (strcmp(jenis, "Kilat") == 0)
                    harga = 7000 * berat;

                if (strcmp(jenis, "Biasa") == 0)
                    harga = 6000 * berat;

                printf("Harga : %d IDR \n", harga);
                D = make_data(nama, jenis, berat, harga);

                if (strcmp(jenis, "Kilat") == 0)
                    insert_first(&L, D);

                if (strcmp(jenis, "Biasa") == 0)
                    insert_last(&L, D);
                break;

            case 2:
                printf("\nPindah ke Bayar Modifikasi!\n");
                break;

            case 3:
                print_list(L);
                break;

            case 4:
                printf("\n[ Input Data ]\n");
                printf("Nama : ");
                fflush(stdin);
                gets(nama);

                Data *d = find_laundry_by_name(L, nama);
                if (d == NULL)
                    printf("\nData tidak ditemukan!\n");
                else {
                    printf("\n");
                    printf("Nama  : %s\n", d->nama);
                    printf("Jenis : %s\n", d->jenis);
                    printf("Berat : %d\n", d->berat);
                    printf("Harga : %d IDR\n", d->harga);
                }
                break;

            case 5:
                printf("\n[ Input Data ]\n");
                printf("Jenis : ");
                fflush(stdin);
                gets(jenis);

                if (strcmp(jenis, "Kilat") == 0) {
                    address P = L.first;
                    while (P != NULL) {
                        if (strcmp(P->D.jenis, "Kilat") == 0)
                            break;
                        P = P->next;
                    }

                    if (P == NULL) {
                        printf("\nTidak ada Laundry berjenis Kilat!\n");
                        break;
                    }

                    printf("\n");
                    printf("Nama  : %s\n", P->D.nama);
                    printf("Jenis : %s\n", P->D.jenis);
                    printf("Berat : %d\n", P->D.berat);
                    printf("Harga : %d IDR\n", P->D.harga);

                    while (true) {
                        printf("Uang : ");
                        scanf("%d", &uang);
                        if (uang >= P->D.harga) {
                            printf("\nPembayaran berhasil!\n");
                            insert_last(&L_riwayat, P->D);
                            delete_first(&L);
                            break;
                        } else {
                            printf("\nUang tidak cukup!\n");
                        }
                    }
                } else if (strcmp(jenis, "Biasa") == 0) {
                    address P = L.first;
                    while (P != NULL) {
                        if (P->next == NULL && strcmp(P->D.jenis, "Biasa") == 0)
                            break;
                        P = P->next;
                    }

                    if (P == NULL) {
                        printf("\nTidak ada Laundry berjenis Biasa!\n");
                        break;
                    }

                    printf("\n");
                    printf("Nama  : %s\n", P->D.nama);
                    printf("Jenis : %s\n", P->D.jenis);
                    printf("Berat : %d\n", P->D.berat);
                    printf("Harga : %d IDR\n", P->D.harga);

                    while (true) {
                        printf("Uang : ");
                        scanf("%d", &uang);
                        if (uang >= P->D.harga) {
                            printf("\nPembayaran berhasil!\n");
                            insert_last(&L_riwayat, P->D);
                            delete_last(&L);
                            break;
                        } else {
                            printf("\nUang tidak cukup!\n");
                        }
                    }
                } else {
                    printf("\nInput tidak valid!\n");
                }

                break;

            case 6:
                if (is_empty(L_riwayat))
                    printf("\nBelum ada riwayat laundry!\n");
                else
                    print_list(L_riwayat);
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
