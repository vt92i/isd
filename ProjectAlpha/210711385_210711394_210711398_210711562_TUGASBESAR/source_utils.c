#include "header_multilist.h"
#include "header_linkedlist.h"

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

address_parent check_login_dokter(multilist ml, string username, string password) {
    address_parent p = ml.first_parent;
    while (p != NULL) {
        if (strcmp(p->dp.login.username, username) == 0 && strcmp(p->dp.login.password, password) == 0) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

address_child find_child_by_id(address_parent ap, int id) {
    address_child c;
    for (c = ap->first_child; c != NULL; c = c->next) {
        if (c->dc.id == id) return c;
    }
    return NULL;
}

address_child find_child_by_id_periksa(address_parent ap, int id) {
    address_child c;
    for (c = ap->first_child; c != NULL; c = c->next) {
        if (c->dc.dsc.id == id) return c;
    }
    return NULL;
}

void update_child_by_id_periksa(address_parent ap, int id, data_child dc) {
    address_child c;
    for (c = ap->first_child; c != NULL; c = c->next) {
        if (c->dc.dsc.id == id)
            c->dc = dc;
    }
}

void delete_at_child(multilist ml, address_parent ap, int id_child) {
    if (ap->first_child->dc.id == id_child) {
        delete_first_child(ml, ap->dp.id);
    } else {
        address_child p = ap->first_child;
        while (p->next != NULL && p->next->dc.id != id_child) {
            p = p->next;
        }
        if (p->next != NULL) {
            address_child q = p->next;
            p->next = q->next;
            free(q);
        }
    }
}

void print_laporan(address_parent ap) {
    address_child c;
    for (c = ap->first_child; c != NULL; c = c->next) {
        if (c->dc.dsc.is_done) {
            printf("\t\t\t\t\t\t\t\tID : %d \n", c->dc.id);
            printf("\t\t\t\t\t\t\t\tNama : %s \n", c->dc.nama);
            printf("\t\t\t\t\t\t\t\tTanggal Lahir : %s \n", c->dc.tanggal_lahir);
            printf("\t\t\t\t\t\t\t\tJenis Hewan : %s \n", c->dc.jenis_hewan);
            printf("\t\t\t\t\t\t\t\tJenis Kelamin : %s \n", c->dc.jenis_kelamin);

            printf("\t\t\t\t\t\t\t\t\t[ Riwayat Periksa ]\n");
            printf("\t\t\t\t\t\t\t\t\tID Periksa : %d \n", c->dc.dsc.id);
            printf("\t\t\t\t\t\t\t\t\tTanggal Periksa : %s \n", c->dc.dsc.tanggal_periksa);
            printf("\t\t\t\t\t\t\t\t\tDiagnosa Penyakit : %s \n", c->dc.dsc.diagnosa_penyakit);
            printf("\t\t\t\t\t\t\t\t\tObat : %s \n", c->dc.dsc.obat);
            printf(c->dc.dsc.is_done ? "\t\t\t\t\t\t\t\t\tStatus : Selesai \n" : "\tStatus : Belum Selesai \n");
        }
        printf("\n");
    }
}

bool is_hewan_unique(linked_list l, int id) {
    address p;
    for (p = l; p != NULL; p = p->next)
        if (p->d.id == id) return false;
    return true;
}

bool is_riwayat_unique(linked_list l, int id) {
    address p;
    for (p = l; p != NULL; p = p->next)
        if (p->d.riwayat_periksa.id == id) return false;
    return true;
}

void sort_asc(linked_list *l) {
    address p, q;
    for (p = *l; p != NULL; p = p->next) {
        for (q = *l; q->next != NULL; q = q->next) {
            if (strcmp(q->d.jenis_hewan, q->next->d.jenis_hewan) > 0) {
                data_hewan dh_temp = q->d;
                q->d = q->next->d;
                q->next->d = dh_temp;
            }
        }
    }
}

void cyan() {
    printf("\033[0;36m");
}

void red() {
    printf("\033[0;31m");
}

void green() {
    printf("\033[0;32m");
}

void reset() {
    printf("\033[0;0m");
}

void gotoxy(int x, int y) {
    COORD coord = {0, 0};
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void kotak(int i) {
    for (i = 60; i <= 117; i++) {
        gotoxy(i, 10);
        printf("=");
        gotoxy(78, 11);
        printf("[ Tambah Dokter ]");
        gotoxy(i, 12);
        printf("=");
        gotoxy(i, 15);
        printf("=");
    }
    for (i = 10; i <= 15; i++) {
        gotoxy(60, i);
        printf("=");
        gotoxy(117, i);
        printf("=");
    }
}

void kotakUbah(int i) {
    for (i = 60; i <= 117; i++) {
        gotoxy(i, 10);
        printf("=");
        gotoxy(78, 11);
        printf("[ Ubah Dokter ]");
        gotoxy(i, 12);
        printf("=");
        gotoxy(i, 15);
        printf("=");
    }
    for (i = 10; i <= 15; i++) {
        gotoxy(60, i);
        printf("=");
        gotoxy(117, i);
        printf("=");
    }
}

void kotakLogin(int i) {
    for (i = 60; i <= 97; i++) {
        gotoxy(i, 15);
        printf("=");
        gotoxy(74, 16);
        printf("[ Login ]");
        gotoxy(i, 17);
        printf("=");
        gotoxy(i, 20);
        printf("=");
    }

    for (i = 15; i <= 20; i++) {
        gotoxy(60, i);
        printf("=");
        gotoxy(97, i);
        printf("=");
    }
}

void kotakKecil(int i) {
    for (i = 60; i <= 97; i++) {
        gotoxy(i, 15);
        printf("=");
        gotoxy(i, 17);
        printf("=");
        gotoxy(i, 20);
        printf("=");
    }

    for (i = 15; i <= 20; i++) {
        gotoxy(60, i);
        printf("=");
        gotoxy(97, i);
        printf("=");
    }
}

void kotakHewan(int i) {
    for (i = 60; i <= 117; i++) {
        gotoxy(i, 15);
        printf("=");
        gotoxy(i, 17);
        printf("=");
        gotoxy(i, 20);
        printf("=");
    }

    for (i = 15; i <= 20; i++) {
        gotoxy(60, i);
        printf("=");
        gotoxy(117, i);
        printf("=");
    }
}

void print_list_by_id(linked_list l, int id) {
    if (!is_linkedlist_empty(l)) {
        if (l->d.id == id) {
            printf("\n\t\t\t\t\t\t\t\t[ Data Hewan ]\n");
            printf("\t\t\t\t\t\t\t\tID Hewan : %d\n", l->d.id);
            printf("\t\t\t\t\t\t\t\tNama : %s\n", l->d.nama);
            printf("\t\t\t\t\t\t\t\tTanggal Lahir : %s\n", l->d.tanggal_lahir);
            printf("\t\t\t\t\t\t\t\tJenis Hewan : %s\n", l->d.jenis_hewan);
            printf("\t\t\t\t\t\t\t\tJenis Kelamin : %s\n", l->d.jenis_kelamin);

            printf("\t\t\t\t\t\t\t\t[ Riwayat Periksa ]\n");
            printf("\t\t\t\t\t\t\t\t\tID Periksa : %d \n", l->d.riwayat_periksa.id);
            printf("\t\t\t\t\t\t\t\t\tTanggal Periksa : %s \n", l->d.riwayat_periksa.tanggal_periksa);
            printf("\t\t\t\t\t\t\t\t\tID Dokter : %d \n", l->d.riwayat_periksa.id_dokter);
        }

        print_list_by_id(l->next, id);
    }
}

bool is_username_unique(multilist l, string username) {
    address_parent p = l.first_parent;
    for (p = l.first_parent; p != NULL; p = p->next)
        if (strcmp(p->dp.login.username, username) == 0) return false;
    return true;
}
