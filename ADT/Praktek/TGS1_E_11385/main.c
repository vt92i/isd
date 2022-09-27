#include "header.h"

int main(void) {
    Customer C[5];
    init(C);

    int menu, submenu;
    int index, index_tmp, i;

    string nama, nik, pekerjaan, nama_bank, no_rekening, temp;
    int umur;

    uint64_t total_pembayaran, total_diskon, uang_customer;

    do {
        system("cls");
        printf("==== UNGUIDED 1 - ADT ==== \n");
        printf("1. Create data\n");
        printf("2. Read data \n");
        printf("3. Update data \n");
        printf("4. Calculate \n");
        printf("5. Delete data \n");
        printf("0. Exit \n");
        printf(">> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("==== Create Data ====\n");
                index = find_empty(C);
                if (index != -1) {
                    while (true) {
                        printf("\nInput Nama \t\t: ");
                        fflush(stdin);
                        gets(nama);
                        if (strlen(nama) != 0) break;
                    }

                    while (true) {
                        printf("Input NIK \t\t: ");
                        fflush(stdin);
                        gets(temp);

                        if (strlen(temp) != 0) {
                            index_tmp = find_data(C, temp);
                            if (index_tmp == -1) {
                                strcpy(nik, temp);
                                break;
                            }
                        }
                    }

                    while (true) {
                        printf("Input Pekerjaan \t: ");
                        fflush(stdin);
                        gets(pekerjaan);
                        if (strlen(pekerjaan) != 0) break;
                    }

                    printf("Input Umur \t\t: ");
                    scanf("%d", &umur);

                    C[index] = make_customer(nama, nik, pekerjaan, umur);

                    for (i = 0; i < 2; i++) {
                        printf("\tInput Nama Bank %d \t: ", i + 1);
                        fflush(stdin);
                        gets(nama_bank);

                        printf("\tInput No. Rekening %d \t: ", i + 1);
                        fflush(stdin);
                        gets(no_rekening);

                        C[index].bank[i] = make_bank(nama_bank, no_rekening);
                    }

                    printf("\nInput data berhasil! \n");
                } else {
                    printf("\nData penuh! \n");
                }
                break;

            case 2:
                printf("==== Read Data ====\n");
                print_data(C);
                break;

            case 3:
                printf("==== Update Data ====\n");
                printf("\nInput NIK \t\t: ");
                fflush(stdin);
                gets(nik);
                index = find_data(C, nik);

                if (index != -1) {
                    while (true) {
                        printf("\nInput Nama \t\t: ");
                        fflush(stdin);
                        gets(nama);
                        if (strlen(nama) != 0) break;
                    }

                    while (true) {
                        printf("Input Pekerjaan \t: ");
                        fflush(stdin);
                        gets(pekerjaan);
                        if (strlen(pekerjaan) != 0) break;
                    }

                    printf("Input Umur \t\t: ");
                    scanf("%d", &umur);

                    C[index] = edit_customer(nama, nik, pekerjaan, umur);

                    for (i = 0; i < 2; i++) {
                        printf("\tInput Nama Bank %d \t: ", i + 1);
                        fflush(stdin);
                        gets(nama_bank);

                        printf("\tInput No. Rekening %d \t: ", i + 1);
                        fflush(stdin);
                        gets(no_rekening);

                        C[index].bank[i] = edit_bank(nama_bank, no_rekening);
                    }

                    printf("\nUpdate data berhasil! \n");
                } else {
                    printf("\nData tidak ditemukan! \n");
                }
                break;

            case 4:
                printf("==== Calculate ====\n");
                printf("\nInput NIK : ");
                fflush(stdin);
                gets(nik);
                index = find_data(C, nik);

                if (index == -1) {
                    printf("\nData tidak ditemukan! \n");
                    break;
                }

                total_pembayaran = 0;
                total_diskon = 0;
                uang_customer = 0;

                do {
                    system("cls");
                    printf("1. Mobil SUV - 600,000,000 IDR\n");
                    printf("2. Mobil Family - 300,000,000 IDR\n");
                    printf("3. Mobil Sporty - 1,500,000,000 IDR\n");
                    printf("0. Pembayaran \n");
                    printf(">> ");
                    scanf("%d", &submenu);

                    switch (submenu) {
                        case 1:
                            total_pembayaran += 600000000;

                            for (i = 0; i < 2; i++) {
                                if (strcmp(C[index].bank[i].nama, "ATMA") == 0) {
                                    total_diskon += 600000000 * 0.1;
                                    break;
                                }
                            }

                            printf("\nBerhasil pilih Mobil SUV! \n");
                            break;
                        case 2:
                            total_pembayaran += 300000000;

                            for (i = 0; i < 2; i++) {
                                if (strcmp(C[index].bank[i].nama, "JOGJA") == 0) {
                                    total_diskon += 300000000 * 0.15;
                                    break;
                                }
                            }

                            printf("\nBerhasil pilih Mobil Family! \n");
                            break;
                        case 3:
                            if (umur <= 50) {
                                total_pembayaran += 1500000000;
                                printf("\nBerhasil pilih Mobil Sporty! \n");
                            } else {
                                printf("\nUmur harus kurang dari sama dengan 50! \n");
                            }

                            break;
                        case 0:
                            printf("\nTotal pembayaran (without discount) : %lld IDR", total_pembayaran);
                            printf("\nTotal diskon : %lld IDR", total_diskon);
                            printf("\nTotal pembayaran (with discount) : %lld IDR", total_pembayaran - total_diskon);
                            while (true) {
                                printf("\nCash : ");
                                scanf("%lld", &uang_customer);

                                if (uang_customer >= total_pembayaran - total_diskon) {
                                    printf("\nPembayaran berhasil!");
                                    printf("\nKembalian : %lld IDR", uang_customer - total_pembayaran + total_diskon);
                                    total_pembayaran = 0;
                                    uang_customer = 0;
                                    break;
                                } else {
                                    printf("\nUang tidak cukup! \n");
                                }
                            }
                            break;
                    }
                    getch();
                } while (submenu != 0);

                break;

            case 5:
                printf("==== Delete Data ====\n");
                printf("\nInput NIK : ");
                fflush(stdin);
                gets(nik);
                index = find_data(C, nik);

                if (index == -1) {
                    printf("\nData tidak ditemukan! \n");
                    break;
                }

                C[index] = delete_customer();

                for (i = 0; i < 2; i++) {
                    C[index].bank[i] = delete_bank();
                }

                printf("\nDelete data berhasil! \n");

                break;

            case 0:
                printf("\n==== Keluar dari Program ====\n");
                break;

            default:
                printf("\nMenu tidak tersedia! \n");
        }
        getch();
    } while (menu != 0);

    return 0;
}
