#include "header_multilist.h"
#include "header_linkedlist.h"

// Utils
time_t init_date(int day, int month, int year);
address_parent check_login_dokter(multilist ml, string username, string password);
address_child find_child_by_id(address_parent ap, int id);
address_child find_child_by_id_periksa(address_parent ap, int id);
void update_child_by_id_periksa(address_parent ap, int id, data_child dc);
void delete_at_child(multilist ml, address_parent ap, int id_child);
void print_laporan(address_parent ap);
bool is_hewan_unique(linked_list l, int id);
bool is_riwayat_unique(linked_list l, int id);
void sort_asc(linked_list *l);
void cyan();
void red();
void green();
void reset();
void gotoxy(int x, int y);
void kotak(int i);
void kotakUbah(int i);
void kotakLogin(int i);
void kotakKecil(int i);
void kotakHewan(int i);
void print_list_by_id(linked_list l, int id);
bool is_username_unique(multilist l, string username);

int main(void) {
    struct auth {
        string current_user;
        bool is_auth;
    } auth = {"", false};

    string username, password;
    int menu, i;

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
    } p, q;

    while (1) {
        system("cls");
        while (1) {
        A:
            kotakLogin(i);
            gotoxy(61, 18);
            printf("Username : ");
            fflush(stdin);
            gets(username);

            if (strlen(username) > 0)
                break;
            else {
                red();
                gotoxy(61, 19);
                printf("Username tidak boleh kosong\n");
                reset();
                getch();
                system("cls");
                goto A;
            }
        }
        system("cls");
        while (1) {
        L:
            kotakLogin(i);
            gotoxy(61, 18);
            printf("Password : ");
            fflush(stdin);
            gets(password);

            if (strlen(password) > 0)
                break;
            else {
                red();
                gotoxy(61, 19);
                printf("Password tidak boleh kosong\n");
                reset();
                getch();
                system("cls");
                goto L;
            }
        }

        if (strcmp(username, "0") == 0 && strcmp(password, "0") == 0) {
            system("cls");
            kotakLogin(i);
            cyan();
            gotoxy(74, 18);
            printf("Sayonara!\n");
            reset();
            getch();
            break;
        }

        if (strcmp(username, "admin") == 0 && strcmp(password, "admincintasatwa") == 0) {
            strcpy(auth.current_user, username);
            auth.is_auth = true;
            cyan();
            gotoxy(70, 19);
            printf("Login berhasil!\n");
            reset();
            getch();

            system("cls");
            for (i = 60; i <= 97; i++) {
                gotoxy(i, 15);
                printf("=");
                gotoxy(i, 17);
                printf("=");
            }
            for (i = 15; i <= 17; i++) {
                gotoxy(60, i);
                printf("=");
                gotoxy(97, i);
                printf("=");
            }
            cyan();
            gotoxy(68, 16);
            printf("Selamat datang, %s!", auth.current_user);
            reset();
            getch();

            do {
                system("cls");
                for (i = 60; i <= 97; i++) {
                    gotoxy(i, 10);
                    printf("=");
                    gotoxy(i, 12);
                    printf("=");
                    gotoxy(i, 14);
                    printf("=");
                    gotoxy(i, 16);
                    printf("=");
                    gotoxy(i, 18);
                    printf("=");
                    gotoxy(i, 20);
                    printf("=");
                    gotoxy(i, 22);
                    printf("=");
                    gotoxy(i, 24);
                    printf("=");
                    gotoxy(i, 26);
                    printf("=");
                    gotoxy(i, 28);
                    printf("=");
                    gotoxy(i, 30);
                    printf("=");
                    gotoxy(i, 32);
                    printf("=");
                }
                for (i = 10; i <= 32; i++) {
                    gotoxy(60, i);
                    printf("=");
                    gotoxy(97, i);
                    printf("=");
                }
                gotoxy(72, 11);
                printf("[ Menu Admin ]\n");
                gotoxy(61, 13);
                printf("1. Tambah Dokter\n");
                gotoxy(61, 15);
                printf("2. Tampil Dokter\n");
                gotoxy(61, 17);
                printf("3. Ubah Dokter\n");
                gotoxy(61, 19);
                printf("4. Hapus Dokter\n\n");
                gotoxy(61, 21);
                printf("5. Cari Dokter\n");
                gotoxy(61, 23);
                printf("6. Pendaftaran Periksa Hewan\n");
                gotoxy(61, 25);
                printf("7. Tampil Hewan + Riwayat Periksa\n");
                gotoxy(61, 27);
                printf("8. Hapus Hewan\n");
                gotoxy(61, 29);
                printf("0. Logout\n");
                gotoxy(61, 31);
                printf(">>> ");
                scanf("%d", &menu);
                system("cls");
                switch (menu) {
                    case 1:

                        while (1) {
                        D:
                            kotak(i);
                            gotoxy(61, 13);
                            printf("ID : ");
                            scanf("%d", &dp.id);
                            if (is_parent_unique(dokter, dp.id))
                                break;
                            else {
                                red();
                                gotoxy(61, 14);
                                printf("Id harus unik\n");
                                reset();
                                getch();
                                system("cls");
                                goto D;
                            }
                        }
                        system("cls");

                        while (1) {
                        B:
                            kotak(i);
                            gotoxy(61, 13);
                            printf("Nama : ");
                            fflush(stdin);
                            gets(dp.nama);

                            if (strcmpi(dp.nama, "-") != 0 && strcmpi(dp.nama, " ") != 0 && strlen(dp.nama) > 0)
                                break;
                            else {
                                red();
                                gotoxy(61, 14);
                                printf("Nama tidak boleh kosong, -, dan ada spasi didepan nya\n");
                                reset();
                                getch();
                                system("cls");
                                goto B;
                            }
                        }
                    F:
                        system("cls");
                        while (1) {
                            kotak(i);
                            gotoxy(61, 13);
                            printf("Tanggal Bergabung (DD-MM-YYYY): ");
                            fflush(stdin);
                            gets(dp.tanggal_bergabung);

                            if (strlen(dp.tanggal_bergabung) != 10) {
                                system("cls");
                                continue;
                                goto F;
                            }
                            if (dp.tanggal_bergabung[2] != '-' && dp.tanggal_bergabung[5] != '-') {
                                system("cls");
                                continue;
                                goto F;
                            }
                            sscanf(dp.tanggal_bergabung, "%d-%d-%d", &p.day, &p.month, &p.year);
                            if (p.day < 1 || p.day > 31) {
                                system("cls");
                                continue;
                                goto F;
                            }
                            if (p.month < 1 || p.month > 12) {
                                system("cls");
                                continue;
                                goto F;
                            }
                            if (p.year < 1 || p.year > 9999) {
                                system("cls");
                                continue;
                                goto F;
                            }
                            break;
                        }
                        system("cls");
                        while (1) {
                        C:
                            kotak(i);
                            gotoxy(61, 13);
                            printf("Username : ");
                            fflush(stdin);
                            gets(dp.login.username);

                            if (strcmp(dp.login.username, "admin") != 0 && strcmp(dp.login.username, "0") != 0 && strcmp(dp.login.username, "") != 0 && is_username_unique(dokter, dp.login.username))
                                break;
                            else {
                                red();
                                gotoxy(61, 14);
                                printf("Username Invalid");
                                reset();
                                getch();
                                system("cls");
                                goto C;
                            }
                        }
                        system("cls");
                        while (1) {
                        E:
                            kotak(i);
                            gotoxy(61, 13);
                            printf("Password : ");
                            fflush(stdin);
                            gets(dp.login.password);

                            if (strcmp(dp.login.password, "admincintasatwa") != 0 && strcmp(dp.login.password, "0") != 0 && strcmp(dp.login.password, "") != 0)
                                break;
                            else {
                                red();
                                gotoxy(61, 14);
                                printf("Pasword Invalid");
                                reset();
                                getch();
                                system("cls");
                                goto E;
                            }
                        }
                        system("cls");
                        kotak(i);
                        insert_last_parent(&dokter, dp);
                        cyan();
                        gotoxy(78, 13);
                        printf("Berhasil menambahkan dokter\n");
                        reset();
                        break;

                    case 2:
                        printf("\n\t\t\t\t\t\t\t\t[ Tampil Dokter ]\n");
                        print_all_parent(dokter);
                        break;

                    case 3:

                        while (1) {
                        G:
                            kotakUbah(i);
                            gotoxy(61, 13);
                            printf("Input Nama Dokter : ");
                            fflush(stdin);
                            gets(dp.nama);
                            if (strcmpi(dp.nama, "-") != 0 && strcmpi(dp.nama, " ") != 0 && strlen(dp.nama) > 0)
                                break;
                            else {
                                red();
                                gotoxy(61, 14);
                                printf("Nama tidak boleh kosong, -, dan ada spasi didepan nya\n");
                                reset();
                                getch();
                                system("cls");
                                goto G;
                            }
                        }

                        ap = find_parent_by_name(dokter, dp.nama);
                        system("cls");
                        if (ap != NULL) {
                            while (1) {
                            H:
                                kotakUbah(i);
                                gotoxy(61, 13);
                                printf("Nama : ");
                                fflush(stdin);
                                gets(dp.nama);

                                if (strcmpi(dp.nama, "-") != 0 && strcmpi(dp.nama, " ") != 0 && strlen(dp.nama) > 0)
                                    break;
                                else {
                                    red();
                                    gotoxy(61, 14);
                                    printf("Nama tidak boleh kosong, -, dan ada spasi didepan nya\n");
                                    reset();
                                    getch();
                                    system("cls");
                                    goto H;
                                }
                            }
                            system("cls");
                            while (1) {
                            I:
                                kotakUbah(i);
                                gotoxy(61, 13);
                                printf("Tanggal Bergabung (DD-MM-YYYY): ");
                                fflush(stdin);
                                gets(dp.tanggal_bergabung);

                                if (strlen(dp.tanggal_bergabung) != 10) {
                                    system("cls");
                                    continue;
                                    goto I;
                                }
                                if (dp.tanggal_bergabung[2] != '-' && dp.tanggal_bergabung[5] != '-') {
                                    system("cls");
                                    continue;
                                    goto I;
                                }
                                sscanf(dp.tanggal_bergabung, "%d-%d-%d", &p.day, &p.month, &p.year);
                                if (p.day < 1 || p.day > 31) {
                                    system("cls");
                                    continue;
                                    goto I;
                                }
                                if (p.month < 1 || p.month > 12) {
                                    system("cls");
                                    continue;
                                    goto I;
                                }
                                if (p.year < 1 || p.year > 9999) {
                                    system("cls");
                                    continue;
                                    goto I;
                                }
                                break;
                            }
                            system("cls");
                            while (1) {
                            J:
                                kotakUbah(i);
                                gotoxy(61, 13);
                                printf("Username : ");
                                fflush(stdin);
                                gets(dp.login.username);

                                if (strcmp(dp.login.username, "0") != 0 && strcmp(dp.login.username, "") != 0)
                                    break;
                                else {
                                    red();
                                    gotoxy(61, 14);
                                    printf("Username Invalid");
                                    reset();
                                    getch();
                                    system("cls");
                                    goto J;
                                }
                            }
                            system("cls");
                            while (1) {
                            K:
                                kotakUbah(i);
                                gotoxy(61, 13);
                                printf("Password : ");
                                fflush(stdin);
                                gets(dp.login.password);

                                if (strcmp(dp.login.password, "0") != 0 && strcmp(dp.login.password, "") != 0)
                                    break;
                                else {
                                    red();
                                    gotoxy(61, 14);
                                    printf("Username Invalid");
                                    reset();
                                    getch();
                                    system("cls");
                                    goto K;
                                }
                            }
                            system("cls");
                            ap->dp = dp;
                            kotakUbah(i);
                            cyan();
                            gotoxy(78, 13);
                            printf("Data berhasil diubah!\n");
                            reset();

                        } else {
                            kotakUbah(i);
                            red();
                            gotoxy(78, 13);
                            printf("Dokter tidak ditemukan!\n");
                            reset();
                        }
                        break;

                    case 4:
                        kotakKecil(i);
                        gotoxy(70, 16);
                        printf("[ Hapus Dokter ]\n");
                        gotoxy(61, 18);
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

                            cyan();
                            gotoxy(61, 19);
                            printf("Dokter dengan nama %s berhasil dihapus!\n", dp.nama);
                            reset();
                        } else {
                            red();
                            gotoxy(65, 19);
                            printf("Dokter tidak ditemukan!\n");
                            reset();
                        }

                        break;

                    case 5:
                        kotakKecil(i);
                        gotoxy(70, 16);
                        printf("[ Cari Dokter ]\n");
                        gotoxy(61, 18);
                        printf("Input Nama Dokter : ");
                        fflush(stdin);
                        gets(dp.nama);

                        ap = find_parent_by_name(dokter, dp.nama);
                        if (ap != NULL)
                            print_parent(ap);
                        else {
                            red();
                            gotoxy(65, 19);
                            printf("Dokter tidak ditemukan!\n");
                            reset();
                        }

                        break;

                    case 6:
                        kotakHewan(i);
                        gotoxy(65, 16);
                        printf("[ Pendaftaran Periksa Hewan ]\n");

                        if (is_multilist_empty(dokter)) {
                            red();
                            gotoxy(72, 18);
                            printf("Belum ada Dokter!\n");
                            reset();
                            break;
                        }

                        while (1) {
                            kotakHewan(i);
                            gotoxy(61, 18);
                            printf("ID Hewan : ");
                            scanf("%d", &dh.id);

                            break;
                        }
                        system("cls");

                        if (is_hewan_unique(hewan, dh.id)) {
                            while (1) {
                            N:
                                kotakHewan(i);
                                gotoxy(61, 18);
                                printf("Nama Hewan : ");
                                fflush(stdin);
                                gets(dh.nama);

                                if (strlen(dh.nama) > 0 && strcmpi(dh.nama, "-") != 0 && strcmpi(dh.nama, " ") != 0)
                                    break;
                                else {
                                    red();
                                    gotoxy(70, 18);
                                    printf("Nama tidak boleh kosong, -, dan ada spasi didepan nya\n");
                                    reset();
                                    getch();
                                    system("cls");
                                    goto N;
                                }
                            }
                            system("cls");
                            while (1) {
                            O:
                                kotakHewan(i);
                                gotoxy(61, 18);
                                printf("Tanggal Lahir (DD-MM-YYYY): ");
                                fflush(stdin);
                                gets(dh.tanggal_lahir);

                                if (strlen(dh.tanggal_lahir) != 10) {
                                    system("cls");
                                    continue;
                                    goto O;
                                }
                                if (dh.tanggal_lahir[2] != '-' && dh.tanggal_lahir[5] != '-') {
                                    system("cls");
                                    continue;
                                    goto O;
                                }
                                sscanf(dh.tanggal_lahir, "%d-%d-%d", &p.day, &p.month, &p.year);
                                if (p.day < 1 || p.day > 31) {
                                    system("cls");
                                    continue;
                                    goto O;
                                }
                                if (p.month < 1 || p.month > 12) {
                                    system("cls");
                                    continue;
                                    goto O;
                                }
                                if (p.year < 1 || p.year > 9999) {
                                    system("cls");
                                    continue;
                                    goto O;
                                }
                                break;
                            }
                            while (1) {
                            P:
                                system("cls");
                                kotakHewan(i);
                                gotoxy(61, 18);
                                printf("Jenis Hewan (Anjing/Burung/Kucing): ");
                                fflush(stdin);
                                gets(dh.jenis_hewan);

                                if (strcmp(dh.jenis_hewan, "Anjing") == 0 || strcmp(dh.jenis_hewan, "Burung") == 0 || strcmp(dh.jenis_hewan, "Kucing") == 0)
                                    break;
                                else {
                                    red();
                                    gotoxy(68, 19);
                                    printf("Jenis hewan harus Anjing atau Burung Atau Kucing\n");
                                    reset();
                                    getch();
                                    goto P;
                                }
                            }

                            while (1) {
                            Q:
                                system("cls");
                                kotakHewan(i);
                                gotoxy(61, 18);
                                printf("Jenis Kelamin (L/P): ");
                                fflush(stdin);
                                gets(dh.jenis_kelamin);

                                if (strcmp(dh.jenis_kelamin, "L") == 0 || strcmp(dh.jenis_kelamin, "P") == 0)
                                    break;
                                else {
                                    red();
                                    gotoxy(68, 19);
                                    printf("Jenis kelamin harus L/P\n");
                                    reset();
                                    getch();
                                    goto Q;
                                }
                            }
                        }

                        while (1) {
                        M:
                            kotakHewan(i);
                            gotoxy(61, 18);
                            printf("ID Periksa : ");
                            scanf("%d", &dh.riwayat_periksa.id);

                            if (is_riwayat_unique(hewan, dh.riwayat_periksa.id))
                                break;
                            else {
                                red();
                                gotoxy(72, 18);
                                printf("Id periksa harus unik");
                                reset();
                                getch();
                                system("cls");
                                goto M;
                            }
                        }

                        while (1) {
                        R:
                            system("cls");
                            kotakHewan(i);
                            gotoxy(61, 18);
                            printf("ID Dokter : ");
                            scanf("%d", &dh.riwayat_periksa.id_dokter);

                            ap = find_parent_by_id(dokter, dh.riwayat_periksa.id_dokter);
                            if (ap != NULL)
                                break;
                            else {
                                red();
                                gotoxy(61, 19);
                                printf("Id dokter tidak ditemukan\n");
                                reset();
                                getch();
                                goto R;
                            }
                        }

                        while (1) {
                        S:
                            system("cls");
                            kotakHewan(i);
                            gotoxy(61, 18);
                            printf("Tanggal Periksa (DD-MM-YYYY): ");
                            fflush(stdin);
                            gets(dh.riwayat_periksa.tanggal_periksa);

                            if (strlen(dh.riwayat_periksa.tanggal_periksa) != 10) {
                                system("cls");
                                continue;
                                goto S;
                            }
                            if (dh.riwayat_periksa.tanggal_periksa[2] != '-' && dh.riwayat_periksa.tanggal_periksa[5] != '-') {
                                system("cls");
                                continue;
                                goto S;
                            }
                            sscanf(dh.riwayat_periksa.tanggal_periksa, "%d-%d-%d", &p.day, &p.month, &p.year);
                            if (p.day < 1 || p.day > 31) {
                                system("cls");
                                continue;
                                goto S;
                            }
                            if (p.month < 1 || p.month > 12) {
                                system("cls");
                                continue;
                                goto S;
                            }
                            if (p.year < 1 || p.year > 9999) {
                                system("cls");
                                continue;
                                goto S;
                            }

                            sscanf(dh.tanggal_lahir, "%d-%d-%d", &q.day, &q.month, &q.year);
                            int overdue = difftime(init_date(p.day, p.month, p.year), init_date(q.day, q.month, q.year)) / 86400;
                            if (overdue < 0) {
                                system("cls");
                                continue;
                                goto S;
                            }
                            break;
                        }

                        insert_last(&hewan, allocate_data(dh));
                        sort_asc(&hewan);
                        insert_last_child(dokter, dh.riwayat_periksa.id_dokter, make_data_child(dh.id, dh.nama, dh.tanggal_lahir, dh.jenis_hewan, dh.jenis_kelamin, make_data_subchild(dh.riwayat_periksa.id, dh.riwayat_periksa.tanggal_periksa, "-", "-", false)));
                        cyan();
                        gotoxy(67, 19);
                        printf("Berhasil input data");
                        reset();
                        break;

                    case 7:
                        printf("\n\t\t\t\t\t\t\t\t[ Tampil Hewan + Riwayat Periksa ]\n");

                        if (is_linkedlist_empty(hewan)) {
                            red();
                            printf("No Data Found!\n");
                            reset();
                            break;
                        }

                        print_list(hewan);
                        break;

                    case 8:
                        kotakKecil(i);
                        gotoxy(70, 16);
                        printf("[ Hapus Hewan ]\n");
                        gotoxy(70, 18);
                        printf("Input ID Hewan : ");
                        scanf("%d", &dh.id);

                        ah = find_node_by_id(hewan, dh.id);
                        if (ah != NULL) {
                            delete_at_child(dokter, find_parent_by_id(dokter, ah->d.riwayat_periksa.id_dokter), ah->d.id);
                            delete_at(&hewan, ah);
                            cyan();
                            gotoxy(70, 19);
                            printf("Berhasil Hapus Data!\n");
                            reset();
                        } else {
                            red();
                            gotoxy(70, 19);
                            printf("No Data Found!\n");
                            reset();
                        }

                        break;

                    case 0:
                        strcpy(auth.current_user, "");
                        auth.is_auth = false;
                        break;

                    default:
                        red();
                        kotakKecil(i);
                        gotoxy(70, 18);
                        printf("Menu tidak tersedia!\n");
                        reset();
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

            cyan();
            gotoxy(70, 19);
            printf("Login berhasil!\n");
            reset();
            getch();

            system("cls");
            for (i = 60; i <= 97; i++) {
                gotoxy(i, 15);
                printf("=");
                gotoxy(i, 17);
                printf("=");
            }
            for (i = 15; i <= 17; i++) {
                gotoxy(60, i);
                printf("=");
                gotoxy(97, i);
                printf("=");
            }
            cyan();
            gotoxy(68, 16);
            printf("Selamat datang, %s!\n", auth.current_user);
            reset();
            getch();

            do {
                system("cls");
                for (i = 60; i <= 97; i++) {
                    gotoxy(i, 10);
                    printf("=");
                    gotoxy(i, 12);
                    printf("=");
                    gotoxy(i, 14);
                    printf("=");
                    gotoxy(i, 16);
                    printf("=");
                    gotoxy(i, 18);
                    printf("=");
                    gotoxy(i, 20);
                    printf("=");
                    gotoxy(i, 22);
                    printf("=");
                }
                for (i = 10; i <= 22; i++) {
                    gotoxy(60, i);
                    printf("=");
                    gotoxy(97, i);
                    printf("=");
                }
                gotoxy(72, 11);
                printf("[ Menu Dokter ]\n");
                gotoxy(61, 13);
                printf("1. Cek Pendaftaran Periksa Hewan\n");
                gotoxy(61, 15);
                printf("2. Periksa Hewan\n");
                gotoxy(61, 17);
                printf("3. Laporan\n");
                gotoxy(61, 19);
                printf("0. Logout\n");
                gotoxy(61, 21);
                printf(">>> ");
                scanf("%d", &menu);
                system("cls");
                switch (menu) {
                    case 1:
                        printf("\n\t\t\t\t\t\t\t\t[ Cek Pendaftaran Periksa Hewan ]\n");
                        print_all_children(ap);
                        break;

                    case 2:
                        kotakKecil(i);
                        gotoxy(70, 16);
                        printf("[ Periksa Hewan ]\n");
                        gotoxy(61, 18);
                        printf("Input ID Hewan : ");
                        scanf("%d", &dh.riwayat_periksa.id);

                        ac = find_child_by_id_periksa(ap, dh.riwayat_periksa.id);

                        if (ac != NULL && ac->dc.dsc.is_done != true) {
                            while (1) {
                            T:
                                system("cls");
                                kotakKecil(i);
                                gotoxy(61, 18);
                                printf("Diagnosa Penyakit : ");
                                fflush(stdin);
                                gets(ac->dc.dsc.diagnosa_penyakit);

                                if (strlen(ac->dc.dsc.diagnosa_penyakit) > 0)
                                    break;
                                else {
                                    red();
                                    gotoxy(61, 19);
                                    printf("Diagnosa tidak boleh kosong\n");
                                    reset();
                                    getch();
                                    goto T;
                                }
                            }

                            while (1) {
                            U:
                                system("cls");
                                kotakKecil(i);
                                gotoxy(61, 18);
                                printf("Obat : ");
                                fflush(stdin);
                                gets(ac->dc.dsc.obat);

                                if (strlen(ac->dc.dsc.obat) > 0)
                                    break;
                                else {
                                    red();
                                    gotoxy(61, 19);
                                    printf("Obat tidak boleh kosong\n");
                                    reset();
                                    getch();
                                    goto U;
                                }
                            }

                            ac->dc.dsc.is_done = true;
                            update_child_by_id_periksa(ap, ac->dc.dsc.id, ac->dc);
                            cyan();
                            gotoxy(61, 19);
                            printf("Selesai memeriksa hewan\n");
                            reset();

                        } else {
                            red();
                            gotoxy(61, 19);
                            printf("No Data Found!\n");
                            reset();
                        }
                        break;

                    case 3:
                        printf("[ Laporan ]\n");
                        print_laporan(ap);
                        break;

                    case 0:
                        strcpy(auth.current_user, "");
                        auth.is_auth = false;
                        break;

                    default:
                        kotakKecil(i);
                        red();
                        gotoxy(70, 18);
                        printf("\nMenu tidak tersedia!\n");
                        reset();
                        break;
                }
                getch();
            } while (menu != 0);
            continue;
        }
        red();
        gotoxy(65, 19);
        printf("Username atau Password salah!\n");
        reset();
        getch();
    };

    return 0;
}
