#include "header_multilist.h"
#include "header_linkedlist.h"

int main(void) {
    // Multilist
    multilist ml;
    init_multilist(&ml);

    address_parent p_tmp;
    address_child c_tmp;

    string nama, tipe, status, confirm;
    int menu, counter, f, c;
    float berat;

    int arr[1024];

    // Linked List
    list l, l_history;
    init_linkedlist(&l);
    init_linkedlist(&l_history);

    data d;
    address target_node;

    int submenu, id_data;
    int id = 1;

    float total_pendapatan = 0, uang;

    struct date {
        int day, month, year;
    } p, q;

    int choice;

    printf("1. Multilist\n");
    printf("2. Linked List\n");
    printf("Choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            do {
                system("cls");

                printf("\n\n==== UNGUIDED MULTILIST=====");
                printf("\n[ Parent ]");
                printf("\n1. Input Mesin Cuci");
                printf("\n2. Edit Status Mesin Cuci");
                printf("\n3. Hapus Data Mesin Cuci\n");

                printf("\n[ Child ]");
                printf("\n4. Input Paket Cucian\n");

                printf("\n[ Utility ]");
                printf("\n5. Hitung Jumlah Mesin Cuci");
                printf("\n6. Tampil Seluruh Data");
                printf("\n7. Distribusi Paket Cucian");

                printf("\n------------------------------------------------");
                printf("\n0. Exit");

                printf("\n>>> ");
                scanf("%d", &menu);

                switch (menu) {
                    case 1:
                        printf("\n[ Input Mesin Cuci ]\n");
                        while (true) {
                            printf("ID : ");
                            scanf("%d", &id);
                            if (id < 1) continue;
                            if (is_parent_unique(ml, id)) {
                                break;
                            } else {
                                printf("\nID sudah ada, silahkan masukkan ID yang lain!\n");
                            }
                        }

                        while (true) {
                            printf("Tipe : ");
                            fflush(stdin);
                            gets(tipe);
                            if (strlen(tipe) != 0) {
                                break;
                            } else {
                                printf("\nTipe tidak boleh kosong!\n");
                            }
                        }

                        while (true) {
                            printf("Status : ");
                            fflush(stdin);
                            gets(status);
                            if (strlen(status) != 0) {
                                if (strcmp(status, "Aktif") == 0 || strcmp(status, "Tidak Aktif") == 0) {
                                    break;
                                } else {
                                    printf("\nHarus Aktif atau Tidak Aktif!\n");
                                }
                            } else {
                                printf("\nTipe tidak boleh kosong!\n");
                            }
                        }

                        if (id % 2 == 0)
                            insert_last_parent(&ml, make_data_parent(id, tipe, status));
                        else
                            insert_first_parent(&ml, make_data_parent(id, tipe, status));
                        printf("\nData berhasil dimasukkan!\n");
                        break;

                    case 2:
                        printf("\n[ Edit Status Mesin Cuci ]\n");

                        printf("ID Parent : ");
                        scanf("%d", &id);

                        p_tmp = find_parent(ml, id);
                        if (p_tmp == NULL) {
                            printf("\nID Parent tidak ditemukan!\n");
                        } else {
                            print_parent(p_tmp);

                            if (strcmp(p_tmp->dp.status, "Aktif") == 0) {
                                printf("\nYakin ingin mengubah data (Aktif -> Tidak Aktif)? (y/n)");
                                fflush(stdin);
                                gets(confirm);
                                if (strcmp(confirm, "y") == 0) {
                                    strcpy(p_tmp->dp.status, "Tidak Aktif");
                                    printf("\nData berhasil diubah!\n");
                                } else {
                                    printf("\nData tidak jadi diubah!\n");
                                }
                            } else {
                                printf("\nYakin ingin mengubah data (Tidak Aktif -> Aktif)? (y/n)");
                                fflush(stdin);
                                gets(confirm);
                                if (strcmp(confirm, "y") == 0) {
                                    strcpy(p_tmp->dp.status, "Aktif");
                                    printf("\nData berhasil diubah!\n");
                                } else {
                                    printf("\nData tidak jadi diubah!\n");
                                }
                            }
                        }
                        break;

                    case 3:
                        printf("\n[ Hapus Data Mesin Cuci ]\n");
                        counter = 0;
                        for (p_tmp = ml.first_parent; p_tmp != NULL; p_tmp = p_tmp->next) {
                            if (strcmp(p_tmp->dp.status, "Tidak Aktif") == 0) {
                                arr[counter] = p_tmp->dp.id;
                                counter++;
                            }
                        }
                        if (counter == 0) {
                            printf("\nTidak ada Mesin Cuci yang tidak aktif!\n");
                            break;
                        }
                        printf("\nJumlah Mesin Cuci yang akan dihapus : %d \n", counter);
                        printf("\nYakin ingin hapus? (y/n)");
                        fflush(stdin);
                        gets(confirm);
                        if (strcmp(confirm, "y") == 0) {
                            for (f = 0; f < counter; f++)
                                delete_at_parent(&ml, arr[f]);
                            printf("\nData berhasil dihapus!\n");
                        } else {
                            printf("\nData tidak jadi dihapus!\n");
                        }
                        break;

                    case 4:
                        printf("\n[ Input Paket Cucian ]\n");

                        printf("ID Parent : ");
                        scanf("%d", &id);

                        p_tmp = find_parent(ml, id);
                        if (p_tmp == NULL) {
                            printf("\nID Parent tidak ditemukan!\n");
                        } else {
                            if (strcmp(p_tmp->dp.status, "Tidak Aktif") == 0) {
                                printf("\nMesin Cuci tidak aktif!\n");
                                break;
                            }

                            while (true) {
                                printf("ID : ");
                                scanf("%d", &c);
                                if (c < 1) continue;
                                if (is_child_unique(ml, c))
                                    break;
                                else
                                    printf("\nChild dengan ID %d sudah ada!\n", c);
                            }

                            while (true) {
                                printf("Status : ");
                                fflush(stdin);
                                gets(status);
                                if (strlen(status) != 0) {
                                    if (strcmp(status, "Selesai") == 0 || strcmp(status, "Proses") == 0) {
                                        break;
                                    } else {
                                        printf("\nHarus Selesai atau Proses!\n");
                                    }
                                } else {
                                    printf("\nStatus tidak boleh kosong!\n");
                                }
                            }

                            while (true) {
                                printf("Berat : ");
                                scanf("%f", &berat);
                                if (berat < 1) continue;
                                break;
                            }

                            insert_last_child(ml, id, make_data_child(c, status, berat));
                            printf("\nData berhasil dimasukkan!\n");
                        }
                        break;

                    case 5:
                        printf("\n[ Hitung Jumlah Mesin Cuci ]\n");
                        counter = 0;
                        for (p_tmp = ml.first_parent; p_tmp != NULL; p_tmp = p_tmp->next) counter++;
                        printf("\nJumlah Mesin Cuci : %d \n", counter);
                        break;

                    case 6:
                        printf("\n[ Tampil Seluruh Data ]\n");
                        if (!is_multilist_empty(ml))
                            print_all(ml);
                        else
                            printf("\nList kosong!\n");
                        break;

                    case 7:
                        printf("\n[ Distribusi Paket Cucian ]\n");
                        distribute(&ml);
                        printf("\nOK!\n");
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
            break;

        case 2:
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
                                    d.denda = 0;
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
                                    d.denda = 0;
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
                            printf("Harga Pinjam : Rp %.0f \n", target_node->d.harga_pinjam);
                            printf("Denda : Rp %.0f \n\n", target_node->d.denda);

                            float overdue = 0;
                            float denda = 0;

                            if (strcmp(target_node->d.status, "Dipinjam") == 0) {
                                while (1) {
                                    q.day = -1;
                                    q.month = -1;
                                    q.year = -1;

                                    printf("Tanggal Kembali : ");
                                    fflush(stdin);
                                    gets(target_node->d.tanggal_kembali);

                                    if (strlen(target_node->d.tanggal_kembali) != 10) continue;
                                    if (target_node->d.tanggal_kembali[2] != '/' && target_node->d.tanggal_kembali[5] != '/') continue;
                                    sscanf(target_node->d.tanggal_kembali, "%d/%d/%d", &q.day, &q.month, &q.year);
                                    if (q.day < 1 || q.day > 31) continue;
                                    if (q.month < 1 || q.month > 12) continue;
                                    if (q.year < 1 || q.year > 9999) continue;

                                    sscanf(target_node->d.tanggal_pinjam, "%d/%d/%d", &p.day, &p.month, &p.year);
                                    sscanf(target_node->d.tanggal_kembali, "%d/%d/%d", &q.day, &q.month, &q.year);
                                    overdue = difftime(init_date(q.day, q.month, q.year), init_date(p.day, p.month, p.year)) / 86400;
                                    if (overdue < 0) continue;
                                    break;
                                }

                                if (overdue > 5)
                                    denda = (overdue - 5) * 6000;
                                d.denda = denda;
                                target_node->d.denda = d.denda;

                                printf("\nOverdue : %.0f hari", overdue);
                                printf("\nDenda : Rp %.0f", denda);
                                printf("\nTotal : Rp %.0f \n", target_node->d.harga_pinjam + d.denda);
                            }

                            printf("\nInput Uang : ");
                            scanf("%f", &uang);

                            if (uang - target_node->d.harga_pinjam - target_node->d.denda >= 0) {
                                printf("\nOK! Kembalian : Rp %.0f \n", uang - target_node->d.harga_pinjam - target_node->d.denda);

                                total_pendapatan += target_node->d.harga_pinjam + target_node->d.denda;
                                target_node->d.harga_pinjam = strcmp(target_node->d.jenis_buku, "Ensiklopedia") == 0 ? 5000 : 10000;

                                sscanf(target_node->d.tanggal_pinjam, "%d/%d/%d", &p.day, &p.month, &p.year);
                                sscanf(target_node->d.tanggal_kembali, "%d/%d/%d", &q.day, &q.month, &q.year);
                                overdue = difftime(init_date(q.day, q.month, q.year), init_date(p.day, p.month, p.year)) / 86400;
                                if (overdue > 5)
                                    denda = (overdue - 5) * 6000;
                                d.denda = denda;
                                target_node->d.denda = d.denda;

                                strcpy(target_node->d.status, "Dikembalikan");
                                insert_last(&l_history, allocate_data(target_node->d));
                                delete_at(&l, find_node_by_name(l, d.nama_peminjam));

                            } else {
                                printf("\nUang Kurang!");
                                printf("\nPembayaran Diterima : Rp %.0f", uang);
                                printf("\nPembayaran Kurang : Rp %.0f", uang - target_node->d.harga_pinjam - target_node->d.denda);

                                strcpy(target_node->d.status, "Pembayaran Kurang");
                                if (target_node->d.denda > 0) {
                                    if (target_node->d.denda - uang > 0)
                                        target_node->d.denda -= uang;
                                    else {
                                        target_node->d.harga_pinjam -= uang - target_node->d.denda;
                                        target_node->d.denda = 0;
                                    }
                                } else
                                    target_node->d.harga_pinjam -= uang;

                                total_pendapatan += uang;
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
            break;
    }

    return 0;
}
