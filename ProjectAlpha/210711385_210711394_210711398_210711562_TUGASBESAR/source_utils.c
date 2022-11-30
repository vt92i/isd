#include "header_multilist.h"
#include "header_linkedlist.h"

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

void update_child_by_id(address_parent ap, int id, data_child dc) {
    address_child c;
    for (c = ap->first_child; c != NULL; c = c->next) {
        if (c->dc.id == id)
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
            printf("ID : %d \n", c->dc.id);
            printf("Nama : %s \n", c->dc.nama);
            printf("Tanggal Lahir : %s \n", c->dc.tanggal_lahir);
            printf("Jenis Hewan : %s \n", c->dc.jenis_hewan);
            printf("Jenis Kelamin : %s \n", c->dc.jenis_kelamin);

            printf("\t[ Riwayat Periksa ]\n");
            printf("\tID Periksa : %d \n", c->dc.dsc.id);
            printf("\tTanggal Periksa : %s \n", c->dc.dsc.tanggal_periksa);
            printf("\tDiagnosa Penyakit : %s \n", c->dc.dsc.diagnosa_penyakit);
            printf("\tObat : %s \n", c->dc.dsc.obat);
            printf(c->dc.dsc.is_done ? "\tStatus : Selesai \n" : "\tStatus : Belum Selesai \n");
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
