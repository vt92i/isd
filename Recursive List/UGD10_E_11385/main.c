#include "header.h"

time_t init_date(int day, int month, int year) {
    struct tm date = {0};

    date.tm_mday = day;
    date.tm_mon = month - 1;
    date.tm_year = year - 1900;

    date.tm_hour = 0;
    date.tm_min = 0;
    date.tm_sec = 0;
    date.tm_wday = 0;
    date.tm_yday = 0;
    date.tm_isdst = 0;

    return mktime(&date);
}

int main(void) {
    // struct tm {
    //     int tm_sec, tm_min, tm_hour;
    //     int tm_mday, tm_mon, tm_year;
    //     int tm_wday, tm_yday, tm_isdst;
    // };

    // time_t t = init_date(10, 11, 2022);
    // time_t now = time(NULL);
    // printf("Date : %s \n", ctime(&t));
    // printf("Time Difference : %.2f days \n", difftime(now, t) / 60 / 60 / 24);

    // return 0;

    list l, l_history;
    init_empty(&l);
    init_empty(&l_history);

    data d;
    address target_node;

    int menu, submenu, id_data;
    int id = 1;

    float total_pendapatan = 0, uang;

    struct date {
        int day, month, year;
    } p, q;

    do {
        system("cls");

        printf("\n==== Peminjaman Buku =====");
        printf("\n[ Core ]");
        printf("\n1. Input Data Buku");
        printf("\n2. Tampil Data");
        printf("\n3. Cari Data");
        printf("\n4. Pengembalian\n");

        printf("\n[ Utility]");
        printf("\n5. Riwayat");

        printf("\n------------------------------------------------");
        printf("\n0. Exit");

        printf("\n>>> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                do {
                    system("cls");

                    printf("\n==== Peminjaman Buku =====");
                    printf("\n[ Core ]");
                    printf("\n1. Input Baru");
                    printf("\n2. Input After ID");
                    printf("\n0. Menu Utama");
                    printf("\n>>> ");
                    scanf("%d", &submenu);

                    if (submenu == 0) break;
                    switch (submenu) {
                        case 1:
                            printf("\n[ Input Baru ]\n");

                            d.id = id;
                            id++;
                            while (1) {
                                printf("Nama Peminjam : ");
                                fflush(stdin);
                                gets(d.nama_peminjam);
                                if (strlen(d.nama_peminjam) != 0) break;
                            }

                            while (1) {
                                printf("Jenis Buku : ");
                                fflush(stdin);
                                gets(d.jenis_buku);
                                if (strcmp(d.jenis_buku, "Ensiklopedia") == 0 || strcmp(d.jenis_buku, "Biografi") == 0) break;
                            }

                            while (1) {
                                p.day = -1;
                                p.month = -1;
                                p.year = -1;

                                printf("Tanggal Pinjam : ");
                                fflush(stdin);
                                gets(d.tanggal_pinjam);

                                if (strlen(d.tanggal_pinjam) != 10) continue;
                                if (d.tanggal_pinjam[2] != '/' && d.tanggal_pinjam[5] != '/') continue;
                                sscanf(d.tanggal_pinjam, "%d/%d/%d", &p.day, &p.month, &p.year);
                                if (p.day < 1 || p.day > 31) continue;
                                if (p.month < 1 || p.month > 12) continue;
                                if (p.year < 1 || p.year > 9999) continue;
                                break;
                            }

                            strcpy(d.tanggal_kembali, "N/A");
                            strcpy(d.status, "Dipinjam");

                            d.harga_pinjam = strcmp(d.jenis_buku, "Ensiklopedia") == 0 ? 5000 : 10000;
                            insert_last(&l, allocate_data(d));

                            break;

                        case 2:
                            printf("\n[ Input After ID ]\n");

                            printf("Input ID : ");
                            scanf("%d", &id_data);

                            target_node = find_node_by_id(l, id_data);

                            if (target_node == NULL) {
                                printf("\nNo Data Found!\n");
                                break;
                            }

                            printf("\n");
                            d.id = id;
                            id++;
                            while (1) {
                                printf("Nama Peminjam : ");
                                fflush(stdin);
                                gets(d.nama_peminjam);
                                if (strlen(d.nama_peminjam) != 0) break;
                            }

                            while (1) {
                                printf("Jenis Buku : ");
                                fflush(stdin);
                                gets(d.jenis_buku);
                                if (strcmp(d.jenis_buku, "Ensiklopedia") == 0 || strcmp(d.jenis_buku, "Biografi") == 0) break;
                            }

                            while (1) {
                                p.day = -1;
                                p.month = -1;
                                p.year = -1;

                                printf("Tanggal Pinjam : ");
                                fflush(stdin);
                                gets(d.tanggal_pinjam);

                                if (strlen(d.tanggal_pinjam) != 10) continue;
                                if (d.tanggal_pinjam[2] != '/' && d.tanggal_pinjam[5] != '/') continue;
                                sscanf(d.tanggal_pinjam, "%d/%d/%d", &p.day, &p.month, &p.year);
                                if (p.day < 1 || p.day > 31) continue;
                                if (p.month < 1 || p.month > 12) continue;
                                if (p.year < 1 || p.year > 9999) continue;
                                break;
                            }

                            strcpy(d.tanggal_kembali, "N/A");
                            strcpy(d.status, "Dipinjam");

                            d.harga_pinjam = strcmp(d.jenis_buku, "Ensiklopedia") == 0 ? 5000 : 10000;
                            insert_after(&l, allocate_data(d), id_data);

                            break;

                        case 0:
                            break;

                        default:
                            break;
                    }
                    getch();
                } while (submenu != 0);
                break;

            case 2:
                printf("\n[ Tampil Data ]\n");
                print_list(l);
                break;

            case 3:
                printf("\n[ Cari Data ]\n");
                printf("Nama Peminjam : ");
                fflush(stdin);
                gets(d.nama_peminjam);

                target_node = find_node_by_name(l, d.nama_peminjam);
                if (target_node != NULL) {
                    printf("\n[ ID %d ]\n", target_node->d.id);
                    printf("Nama Peminjam : %s \n", target_node->d.nama_peminjam);
                    printf("Jenis Buku : %s \n", target_node->d.jenis_buku);
                    printf("Tanggal Pinjam : %s \n", target_node->d.tanggal_pinjam);
                    printf("Status : %s \n", target_node->d.status);
                    printf("Harga Pinjam : Rp %.0f \n", target_node->d.harga_pinjam);
                } else
                    printf("\nNo Data Found!\n");

                break;

            case 4:
                printf("\n[ Pengembalian ]\n");
                printf("Nama Peminjam : ");
                fflush(stdin);
                gets(d.nama_peminjam);

                target_node = find_node_by_name(l, d.nama_peminjam);
                if (target_node != NULL) {
                    printf("\n[ ID %d ]\n", target_node->d.id);
                    printf("Nama Peminjam : %s \n", target_node->d.nama_peminjam);
                    printf("Jenis Buku : %s \n", target_node->d.jenis_buku);
                    printf("Tanggal Pinjam : %s \n", target_node->d.tanggal_pinjam);
                    printf("Status : %s \n", target_node->d.status);
                    printf("Harga Pinjam : Rp %.0f \n\n", target_node->d.harga_pinjam);

                    float overdue = 0;
                    float denda = 0;

                    if (strcmp(target_node->d.status, "Dipinjam") == 0) {
                        while (1) {
                            q.day = -1;
                            q.month = -1;
                            q.year = -1;

                            printf("Tanggal Kembali : ");
                            fflush(stdin);
                            gets(d.tanggal_kembali);

                            if (strlen(d.tanggal_kembali) != 10) continue;
                            if (d.tanggal_kembali[2] != '/' && d.tanggal_kembali[5] != '/') continue;
                            sscanf(d.tanggal_kembali, "%d/%d/%d", &q.day, &q.month, &q.year);
                            if (q.day < 1 || q.day > 31) continue;
                            if (q.month < 1 || q.month > 12) continue;
                            if (q.year < 1 || q.year > 9999) continue;

                            sscanf(d.tanggal_pinjam, "%d/%d/%d", &p.day, &p.month, &p.year);
                            sscanf(d.tanggal_kembali, "%d/%d/%d", &q.day, &q.month, &q.year);
                            overdue = difftime(init_date(q.day, q.month, q.year), init_date(p.day, p.month, p.year)) / 86400;
                            if (overdue < 0) continue;
                            strcpy(target_node->d.tanggal_kembali, d.tanggal_kembali);
                            break;
                        }

                        if (overdue > 5)
                            denda = (overdue - 5) * 6000;
                        target_node->d.harga_pinjam += denda;

                        printf("\nOverdue : %.0f hari", overdue);
                        printf("\nDenda : Rp %.0f", denda);
                        printf("\nTotal : Rp %.0f \n", target_node->d.harga_pinjam);
                    }

                    printf("\nInput Uang : ");
                    scanf("%f", &uang);

                    if (uang - target_node->d.harga_pinjam >= 0) {
                        printf("\nOK! Kembalian : Rp %.0f \n", uang - target_node->d.harga_pinjam);

                        target_node->d.harga_pinjam = strcmp(target_node->d.jenis_buku, "Ensiklopedia") == 0 ? 5000 : 10000;
                        total_pendapatan += target_node->d.harga_pinjam;

                        strcpy(target_node->d.status, "Dikembalikan");
                        insert_last(&l_history, allocate_data(target_node->d));
                        delete_at(&l, find_node_by_name(l, d.nama_peminjam));

                    } else {
                        printf("\nUang Kurang!");
                        printf("\nPembayaran Diterima : Rp %.0f", uang);
                        printf("\nPembayaran Kurang : Rp %.0f", uang - target_node->d.harga_pinjam);

                        strcpy(target_node->d.status, "Pembayaran Kurang");
                        target_node->d.harga_pinjam -= uang;
                    }
                } else
                    printf("\nNo Data Found!\n");
                break;

            case 5:
                printf("\n[ Riwayat ]\n");
                printf("Total Pendapatan : Rp %.0f \n", total_pendapatan);
                print_list(l_history);
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
