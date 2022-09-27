#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"

int main(void) {
    Customer C[5];
    init(C);

    int menu, submenu;
    int index, index_tmp;

    string nama, nik, pekerjaan;
    int umur;

    int total_pembayaran, uang_customer;
    total_pembayaran = 0;
    uang_customer = 0;

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
                index = find_empty(C);
                if (index != -1) {
                    while (true) {
                        printf("\nInput Nama : ");
                        fflush(stdin);
                        gets(C[index].nama);
                        if (strlen(C[index].nama) != 0) break;
                    }

                    while (true) {
                        printf("Input NIK : ");
                        fflush(stdin);
                        gets(nik);

                        if (strlen(nik) != 0) {
                            index_tmp = find_data(C, nik);
                            if (index_tmp == -1) {
                                strcpy(C[index].nik, nik);
                                break;
                            }
                        }
                    }

                    while (true) {
                        printf("Input Pekerjaan : ");
                        fflush(stdin);
                        gets(C[index].pekerjaan);
                        if (strlen(C[index].pekerjaan) != 0) break;
                    }

                    printf("Input Umur : ");
                    scanf("%d", &C[index].umur);

                    printf("\nInput data berhasil! \n");
                } else {
                    printf("\nData penuh! \n");
                }
                break;

            case 2:
                print_data(C);
                break;

            case 3:
                printf("\nInput NIK : ");
                fflush(stdin);
                gets(nik);
                index = find_data(C, nik);

                if (index != -1) {
                    while (true) {
                        printf("\nInput Nama : ");
                        fflush(stdin);
                        gets(C[index].nama);
                        if (strlen(C[index].nama) != 0) break;
                    }

                    while (true) {
                        printf("Input Pekerjaan : ");
                        fflush(stdin);
                        gets(C[index].pekerjaan);
                        if (strlen(C[index].pekerjaan) != 0) break;
                    }

                    printf("Input Umur : ");
                    scanf("%d", &C[index].umur);

                    printf("\nUpdate data berhasil! \n");
                } else {
                    printf("\nData tidak ditemukan! \n");
                }
                break;

            case 4:
                printf("\nInput NIK : ");
                fflush(stdin);
                gets(nik);
                index = find_data(C, nik);

                if (index == -1) {
                    printf("\nData tidak ditemukan! \n");
                    break;
                }
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
                            printf("\nBerhasil pilih Mobil SUV! \n");
                            break;
                        case 2:
                            total_pembayaran += 300000000;
                            printf("\nBerhasil pilih Mobil Family! \n");
                            break;
                        case 3:
                            if (C[index].umur <= 50) {
                                total_pembayaran += 1500000000;
                                printf("\nBerhasil pilih Mobil Sporty! \n");
                            } else {
                                printf("\nUmur harus kurang dari sama dengan 50! \n");
                            }

                            break;
                        case 0:
                            printf("\nTotal pembayaran : %d IDR", total_pembayaran);
                            while (true) {
                                printf("\nCash : ");
                                scanf("%d", &uang_customer);

                                if (uang_customer >= total_pembayaran) {
                                    printf("\nPembayaran berhasil!");
                                    printf("\nKembalian : %d IDR", uang_customer - total_pembayaran);
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
                printf("\nInput NIK : ");
                fflush(stdin);
                gets(nik);
                index = find_data(C, nik);

                if (index == -1) {
                    printf("\nData tidak ditemukan! \n");
                    break;
                }

                strcpy(C[index].nama, "-");
                strcpy(C[index].nik, "-");
                strcpy(C[index].pekerjaan, "-");
                C[index].umur = 0;

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
