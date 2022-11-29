#include "header_multilist.h"
#include "header_linkedlist.h"

// Utils
address_parent check_login_dokter(multilist ml, string username, string password);
address_child find_child_by_id(address_parent ap, int id);
void update_child_by_id(address_parent ap, int id, data_child dc);
void delete_at_child(multilist ml, address_parent ap, int id_child);
void print_laporan(address_parent ap);
bool is_hewan_unique(linked_list l, int id);
bool is_riwayat_unique(linked_list l, int id);
void sort_asc(linked_list *l);

int main(void) {
    struct auth {
        string current_user;
        bool is_auth;
    } auth = {"", false};

    string username, password;
    int menu;

    multilist dokter;
    init_multilist(&dokter);

    data_parent dp;
    address_parent ap;
    address_child ac;

    linked_list hewan;
    init_linkedlist(&hewan);

    data_hewan dh;
    address ah;

    struct date {
        int day, month, year;
    } p;

    while (1) {
        system("cls");

        printf("\n[ Login ]\n");

        while (1) {
            printf("Username : ");
            fflush(stdin);
            gets(username);

            if (strlen(username) > 0) break;
        }

        while (1) {
            printf("Password : ");
            fflush(stdin);
            gets(password);

            if (strlen(password) > 0) break;
        }

        if (strcmp(username, "0") == 0 && strcmp(password, "0") == 0) {
            printf("\nSayonara!\n");
            getch();
            break;
        }

        if (strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0) {
            strcpy(auth.current_user, username);
            auth.is_auth = true;

            printf("\nLogin berhasil!\n");
            getch();

            system("cls");
            printf("\nSelamat datang, %s!\n", auth.current_user);
            getch();

            do {
                system("cls");

                printf("\n[ Menu Admin ]\n");
                printf("[ Core ]\n");
                printf("1. Tambah Dokter\n");
                printf("2. Tampil Dokter\n");
                printf("3. Ubah Dokter\n");
                printf("4. Hapus Dokter\n\n");

                printf("[ Utility ]\n");
                printf("5. Cari Dokter\n");
                printf("6. Pendaftaran Periksa Hewan\n");
                printf("7. Tampil Hewan + Riwayat Periksa\n");
                printf("8. Hapus Hewan\n");

                printf("--------------------------------\n");
                printf("0. Logout\n");

                printf(">>> ");
                scanf("%d", &menu);
                switch (menu) {
                    case 1:
                        printf("\n[ Tambah Dokter ]\n");

                        while (1) {
                            printf("ID : ");
                            scanf("%d", &dp.id);

                            if (is_parent_unique(dokter, dp.id)) break;
                        }

                        while (1) {
                            printf("Nama : ");
                            fflush(stdin);
                            gets(dp.nama);

                            if (strlen(dp.nama) > 0) break;
                        }

                        while (1) {
                            printf("Tanggal Bergabung (DD-MM-YYYY): ");
                            fflush(stdin);
                            gets(dp.tanggal_bergabung);

                            if (strlen(dp.tanggal_bergabung) != 10) continue;
                            if (dp.tanggal_bergabung[2] != '-' && dp.tanggal_bergabung[5] != '-') continue;
                            sscanf(dp.tanggal_bergabung, "%d/%d/%d", &p.day, &p.month, &p.year);
                            if (p.day < 1 || p.day > 31) continue;
                            if (p.month < 1 || p.month > 12) continue;
                            if (p.year < 1 || p.year > 9999) continue;
                            break;
                        }

                        while (1) {
                            printf("Username : ");
                            fflush(stdin);
                            gets(dp.login.username);

                            if (strcmp(dp.login.username, "admin") != 0 && strcmp(dp.login.username, "0") != 0 && strcmp(dp.login.username, "") != 0) break;
                        }

                        while (1) {
                            printf("Password : ");
                            fflush(stdin);
                            gets(dp.login.password);

                            if (strcmp(dp.login.password, "admin") != 0 && strcmp(dp.login.password, "0") != 0 && strcmp(dp.login.password, "") != 0) break;
                        }

                        insert_last_parent(&dokter, dp);
                        break;

                    case 2:
                        printf("\n[ Tampil Dokter ]\n");
                        print_all_parent(dokter);
                        break;

                    case 3:
                        printf("\n[ Ubah Dokter ]\n");

                        printf("Input Nama Dokter : ");
                        fflush(stdin);
                        gets(dp.nama);

                        printf("\n");
                        ap = find_parent_by_name(dokter, dp.nama);

                        if (ap != NULL) {
                            while (1) {
                                printf("Nama : ");
                                fflush(stdin);
                                gets(dp.nama);

                                if (strlen(dp.nama) > 0) break;
                            }

                            while (1) {
                                printf("Tanggal Bergabung (DD-MM-YYYY): ");
                                fflush(stdin);
                                gets(dp.tanggal_bergabung);

                                if (strlen(dp.tanggal_bergabung) != 10) continue;
                                if (dp.tanggal_bergabung[2] != '-' && dp.tanggal_bergabung[5] != '-') continue;
                                sscanf(dp.tanggal_bergabung, "%d/%d/%d", &p.day, &p.month, &p.year);
                                if (p.day < 1 || p.day > 31) continue;
                                if (p.month < 1 || p.month > 12) continue;
                                if (p.year < 1 || p.year > 9999) continue;
                                break;
                            }

                            while (1) {
                                printf("Username : ");
                                fflush(stdin);
                                gets(dp.login.username);

                                if (strcmp(dp.login.username, "0") != 0 && strcmp(dp.login.username, "") != 0) break;
                            }

                            while (1) {
                                printf("Password : ");
                                fflush(stdin);
                                gets(dp.login.password);

                                if (strcmp(dp.login.password, "0") != 0 && strcmp(dp.login.password, "") != 0) break;
                            }

                            ap->dp = dp;
                            printf("\nData berhasil diubah!\n");

                        } else {
                            printf("Dokter tidak ditemukan!\n");
                        }
                        break;

                    case 4:
                        printf("\n[ Hapus Dokter ]\n");

                        printf("Input Nama Dokter : ");
                        fflush(stdin);
                        gets(dp.nama);

                        ap = find_parent_by_name(dokter, dp.nama);
                        if (ap != NULL) {
                            linked_list ttmp;
                            for (ttmp = hewan; ttmp != NULL; ttmp = ttmp->next)
                                if (ttmp->d.riwayat_periksa.id_dokter == ap->dp.id)
                                    delete_at(&hewan, find_node_by_id(hewan, ttmp->d.id));
                            delete_at_parent(&dokter, ap->dp.id);

                            printf("\nDokter dengan nama %s berhasil dihapus!\n", dp.nama);
                        } else
                            printf("\nDokter tidak ditemukan!\n");

                        break;

                    case 5:
                        printf("\n[ Cari Dokter ]\n");

                        printf("Input Nama Dokter : ");
                        fflush(stdin);
                        gets(dp.nama);

                        printf("\n");
                        ap = find_parent_by_name(dokter, dp.nama);
                        if (ap != NULL)
                            print_parent(ap);
                        else
                            printf("\nDokter tidak ditemukan!\n");

                        break;

                    case 6:
                        printf("\n[ Pendaftaran Periksa Hewan ]\n");

                        if (is_multilist_empty(dokter)) {
                            printf("\nBelum ada Dokter!\n");
                            break;
                        };

                        while (1) {
                            printf("ID Hewan : ");
                            scanf("%d", &dh.id);

                            if (is_hewan_unique(hewan, dh.id)) break;
                        }

                        while (1) {
                            printf("ID Periksa : ");
                            scanf("%d", &dh.riwayat_periksa.id);

                            if (is_riwayat_unique(hewan, dh.riwayat_periksa.id)) break;
                        }

                        while (1) {
                            printf("Tanggal Periksa (DD-MM-YYYY): ");
                            fflush(stdin);
                            gets(dh.riwayat_periksa.tanggal_periksa);

                            if (strlen(dh.riwayat_periksa.tanggal_periksa) != 10) continue;
                            if (dh.riwayat_periksa.tanggal_periksa[2] != '-' && dh.riwayat_periksa.tanggal_periksa[5] != '-') continue;
                            sscanf(dh.riwayat_periksa.tanggal_periksa, "%d/%d/%d", &p.day, &p.month, &p.year);
                            if (p.day < 1 || p.day > 31) continue;
                            if (p.month < 1 || p.month > 12) continue;
                            if (p.year < 1 || p.year > 9999) continue;
                            break;
                        }

                        while (1) {
                            printf("ID Dokter : ");
                            scanf("%d", &dh.riwayat_periksa.id_dokter);

                            ap = find_parent_by_id(dokter, dh.riwayat_periksa.id_dokter);
                            if (ap != NULL) break;
                        }

                        while (1) {
                            printf("Nama Hewan : ");
                            fflush(stdin);
                            gets(dh.nama);

                            if (strlen(dh.nama) > 0) break;
                        }

                        while (1) {
                            printf("Tanggal Lahir (DD-MM-YYYY): ");
                            fflush(stdin);
                            gets(dh.tanggal_lahir);

                            if (strlen(dh.tanggal_lahir) != 10) continue;
                            if (dh.tanggal_lahir[2] != '-' && dh.tanggal_lahir[5] != '-') continue;
                            sscanf(dh.tanggal_lahir, "%d/%d/%d", &p.day, &p.month, &p.year);
                            if (p.day < 1 || p.day > 31) continue;
                            if (p.month < 1 || p.month > 12) continue;
                            if (p.year < 1 || p.year > 9999) continue;
                            break;
                        }

                        while (1) {
                            printf("Jenis Hewan (Anjing/Burung/Kucing): ");
                            fflush(stdin);
                            gets(dh.jenis_hewan);

                            if (strcmp(dh.jenis_hewan, "Anjing") == 0 || strcmp(dh.jenis_hewan, "Burung") == 0 || strcmp(dh.jenis_hewan, "Kucing") == 0) break;
                        }

                        while (1) {
                            printf("Jenis Kelamin (L/P): ");
                            fflush(stdin);
                            gets(dh.jenis_kelamin);

                            if (strcmp(dh.jenis_kelamin, "L") == 0 || strcmp(dh.jenis_kelamin, "P") == 0) break;
                        }

                        insert_last(&hewan, allocate_data(dh));
                        sort_asc(&hewan);
                        insert_last_child(dokter, dh.riwayat_periksa.id_dokter, make_data_child(dh.id, dh.nama, dh.tanggal_lahir, dh.jenis_hewan, dh.jenis_kelamin, make_data_subchild(dh.riwayat_periksa.id, dh.riwayat_periksa.tanggal_periksa, "-", "-", false)));

                        break;

                    case 7:
                        printf("\n[ Tampil Hewan + Riwayat Periksa ]\n");

                        if (is_linkedlist_empty(hewan)) {
                            printf("\nNo Data Found!\n");
                            break;
                        }

                        print_list(hewan);
                        break;

                    case 8:
                        printf("\n[ Hapus Hewan ]\n");

                        printf("Input ID Hewan : ");
                        scanf("%d", &dh.id);

                        ah = find_node_by_id(hewan, dh.id);
                        if (ah != NULL) {
                            delete_at_child(dokter, find_parent_by_id(dokter, ah->d.riwayat_periksa.id_dokter), ah->d.id);
                            delete_at(&hewan, ah);
                            printf("\nBerhasil Hapus Data!\n");
                        } else {
                            printf("\nNo Data Found!\n");
                        }

                        break;

                    case 0:
                        strcpy(auth.current_user, "");
                        auth.is_auth = false;
                        break;

                    default:
                        printf("\nMenu tidak tersedia!\n");
                        break;
                }
                getch();
            } while (menu != 0);
            continue;
        }

        ap = check_login_dokter(dokter, username, password);
        if (ap != NULL) {
            strcpy(auth.current_user, username);
            auth.is_auth = true;

            printf("\nLogin berhasil!\n");
            getch();

            system("cls");
            printf("\nSelamat datang, %s!\n", auth.current_user);
            getch();

            do {
                system("cls");

                printf("\n[ Menu Dokter ]\n");
                printf("[ Core ]\n");
                printf("1. Cek Pendaftaran Periksa Hewan\n");
                printf("2. Periksa Hewan\n");
                printf("3. Laporan\n");

                printf("--------------------------------\n");
                printf("0. Logout\n");

                printf(">>> ");
                scanf("%d", &menu);

                switch (menu) {
                    case 1:
                        printf("\n[ Cek Pendaftaran Periksa Hewan ]\n");
                        print_all_children(ap);
                        break;

                    case 2:
                        printf("\n[ Periksa Hewan ]\n");

                        printf("Input ID Hewan : ");
                        scanf("%d", &dh.id);

                        ac = find_child_by_id(ap, dh.id);

                        if (ac != NULL && ac->dc.dsc.is_done != true) {
                            while (1) {
                                printf("Diagnosa Penyakit : ");
                                fflush(stdin);
                                gets(ac->dc.dsc.diagnosa_penyakit);

                                if (strlen(ac->dc.dsc.diagnosa_penyakit) > 0) break;
                            }

                            while (1) {
                                printf("Obat : ");
                                fflush(stdin);
                                gets(ac->dc.dsc.obat);

                                if (strlen(ac->dc.dsc.obat) > 0) break;
                            }

                            ac->dc.dsc.is_done = true;
                            update_child_by_id(ap, ac->dc.id, ac->dc);

                        } else {
                            printf("\nNo Data Found!\n");
                        }
                        break;

                    case 3:
                        printf("\n[ Laporan ]\n");
                        print_laporan(ap);
                        break;

                    case 0:
                        strcpy(auth.current_user, "");
                        auth.is_auth = false;
                        break;

                    default:
                        printf("\nMenu tidak tersedia!\n");
                        break;
                }
                getch();
            } while (menu != 0);
            continue;
        }

        printf("\nUsername atau Password salah!\n");
        getch();
    };

    return 0;
}
