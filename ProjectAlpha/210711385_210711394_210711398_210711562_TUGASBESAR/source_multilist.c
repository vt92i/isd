#include "header_multilist.h"

// Parent
void init_multilist(multilist* l) {
    l->first_parent = NULL;
}

address_parent allocate_parent(data_parent data) {
    address_parent p = (address_parent)malloc(sizeof(parent));
    p->dp = data;
    p->next = NULL;
    p->first_child = NULL;
    return p;
}

address_parent find_parent_by_id(multilist l, int id) {
    address_parent p = l.first_parent;
    while (p != NULL && p->dp.id != id) {
        p = p->next;
    }
    return p;
}

address_parent find_parent_by_name(multilist l, string nama) {
    address_parent p = l.first_parent;
    while (p != NULL && strcmp(p->dp.nama, nama) != 0) {
        p = p->next;
    }
    return p;
}

void insert_first_parent(multilist* l, data_parent data) {
    address_parent p = allocate_parent(data);
    p->next = l->first_parent;
    l->first_parent = p;
}

void insert_after_parent(multilist* l, int id_parent, data_parent data) {
    address_parent p = find_parent_by_id(*l, id_parent);
    if (p != NULL) {
        address_parent q = allocate_parent(data);
        q->next = p->next;
        p->next = q;
    }
}

void insert_last_parent(multilist* l, data_parent data) {
    address_parent p = allocate_parent(data);
    if (is_multilist_empty(*l)) {
        insert_first_parent(l, data);
    } else {
        address_parent q = l->first_parent;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }
}

void delete_first_parent(multilist* l) {
    if (!is_multilist_empty(*l)) {
        address_parent p = l->first_parent;
        delete_all_children(p);
        l->first_parent = l->first_parent->next;
        free(p);
    }
}

void delete_at_parent(multilist* l, int id_parent) {
    if (!is_multilist_empty(*l)) {
        if (l->first_parent->dp.id == id_parent) {
            delete_first_parent(l);
        } else {
            address_parent p = l->first_parent;
            while (p->next != NULL && p->next->dp.id != id_parent) {
                p = p->next;
            }
            if (p->next != NULL) {
                address_parent q = p->next;
                delete_all_children(q);
                p->next = q->next;
                free(q);
            }
        }
    }
}

void delete_last_parent(multilist* l) {
    if (!is_multilist_empty(*l)) {
        if (l->first_parent->next == NULL) {
            delete_first_parent(l);
        } else {
            address_parent p = l->first_parent;
            while (p->next->next != NULL) {
                p = p->next;
            }
            delete_all_children(p->next);
            free(p->next);
            p->next = NULL;
        }
    }
}

void delete_all_children(address_parent p) {
    address_child q;
    while (have_children(p)) {
        q = p->first_child;
        p->first_child = p->first_child->next;
        free(q);
    }
}

void print_parent(address_parent p) {
    printf("\t\t\t\t\t\t\t\tID : %d \n", p->dp.id);
    printf("\t\t\t\t\t\t\t\tNama : %s \n", p->dp.nama);
    printf("\t\t\t\t\t\t\t\tTanggal Bergabung : %s \n", p->dp.tanggal_bergabung);
    printf("\t\t\t\t\t\t\t\tLogin Username : %s \n", p->dp.login.username);
    printf("\t\t\t\t\t\t\t\tLogin Password : %s \n", p->dp.login.password);
}

void print_all(multilist l) {
    address_parent p = l.first_parent;
    while (p != NULL) {
        print_parent(p);
        print_all_children(p);
        printf("\n");
        p = p->next;
    }
}

void print_all_parent(multilist l) {
    address_parent p;
    for (p = l.first_parent; p != NULL; p = p->next) {
        print_parent(p);
        printf("\t\t\t\t\t\t\t\t===========================");
        printf("\n");
    }
}

bool is_multilist_empty(multilist l) {
    return l.first_parent == NULL;
}

bool have_children(address_parent p) {
    return p->first_child != NULL;
}

// Child
address_child allocate_child(data_child data) {
    address_child c = (address_child)malloc(sizeof(child));
    c->dc = data;
    c->next = NULL;
    return c;
}

void insert_first_child(multilist l, int id_parent, data_child data) {
    address_parent p = find_parent_by_id(l, id_parent);
    if (p != NULL) {
        address_child c = allocate_child(data);
        c->next = p->first_child;
        p->first_child = c;
    }
}

void insert_last_child(multilist l, int id_parent, data_child data) {
    address_parent p = find_parent_by_id(l, id_parent);
    if (p != NULL) {
        if (!have_children(p)) {
            insert_first_child(l, id_parent, data);
        } else {
            address_child c = allocate_child(data);
            address_child q = p->first_child;
            while (q->next != NULL) {
                q = q->next;
            }
            q->next = c;
        }
    }
}

void delete_first_child(multilist l, int id_parent) {
    address_parent p = find_parent_by_id(l, id_parent);
    if (p != NULL) {
        if (have_children(p)) {
            address_child c = p->first_child;
            p->first_child = p->first_child->next;
            free(c);
        }
    }
}

void delete_last_child(multilist l, int id_parent) {
    address_parent p = find_parent_by_id(l, id_parent);
    if (p != NULL) {
        if (have_children(p)) {
            if (p->first_child->next == NULL) {
                delete_first_child(l, id_parent);
            } else {
                address_child q = p->first_child;
                while (q->next->next != NULL) {
                    q = q->next;
                }
                free(q->next);
                q->next = NULL;
            }
        }
    }
}

void print_child(address_child c) {
    if (!c->dc.dsc.is_done) {
        printf("\t\t\t\t\t\t\t\tID : %d \n", c->dc.id);
        printf("\t\t\t\t\t\t\t\tNama : %s \n", c->dc.nama);
        printf("\t\t\t\t\t\t\t\tTanggal Lahir : %s \n", c->dc.tanggal_lahir);
        printf("\t\t\t\t\t\t\t\tJenis Hewan : %s \n", c->dc.jenis_hewan);
        printf("\t\t\t\t\t\t\t\tJenis Kelamin : %s \n", c->dc.jenis_kelamin);

        printf("\t\t\t\t\t\t\t\t\t[ Riwayat Periksa ]\n");
        printf("\t\t\t\t\t\t\t\t\tTanggal Periksa : %s \n", c->dc.dsc.tanggal_periksa);
        printf(c->dc.dsc.is_done ? "\t\t\t\t\t\t\t\t\t\tStatus : Selesai \n" : "\tStatus : Belum Selesai \n");
    }
}

void print_all_children(address_parent p) {
    address_child c;
    for (c = p->first_child; c != NULL; c = c->next) {
        print_child(c);
        printf("\n");
    }
}

// Utility
data_parent make_data_parent(int id, string nama, string tanggal_bergabung, string username, string password) {
    data_parent dp;
    dp.id = id;
    strcpy(dp.nama, nama);
    strcpy(dp.tanggal_bergabung, tanggal_bergabung);
    strcpy(dp.login.username, username);
    strcpy(dp.login.password, password);
    return dp;
}

data_child make_data_child(int id, string nama, string tanggal_lahir, string jenis_hewan, string jenis_kelamin, data_subchild dsc) {
    data_child dc;
    dc.id = id;
    strcpy(dc.nama, nama);
    strcpy(dc.tanggal_lahir, tanggal_lahir);
    strcpy(dc.jenis_hewan, jenis_hewan);
    strcpy(dc.jenis_kelamin, jenis_kelamin);
    dc.dsc = dsc;

    return dc;
}

data_subchild make_data_subchild(int id, string tanggal_periksa, string obat, string diagnosa_penyakit, bool is_done) {
    data_subchild dsc;
    dsc.id = id;
    strcpy(dsc.tanggal_periksa, tanggal_periksa);
    strcpy(dsc.obat, obat);
    strcpy(dsc.diagnosa_penyakit, diagnosa_penyakit);
    dsc.is_done = is_done;

    return dsc;
}

bool is_parent_unique(multilist l, int id) {
    address_parent p = l.first_parent;
    for (p = l.first_parent; p != NULL; p = p->next)
        if (p->dp.id == id) return false;
    return true;
}

bool is_child_unique(multilist l, int id) {
    address_parent p;
    address_child q;
    for (p = l.first_parent; p != NULL; p = p->next) {
        for (q = p->first_child; q != NULL; q = q->next) {
            if (q->dc.id == id) return false;
        }
    }
    return true;
}
