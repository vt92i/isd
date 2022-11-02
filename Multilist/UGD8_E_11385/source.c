#include "header.h"

data_parent make_data_parent(int id, string tipe, string status) {
    data_parent dp;
    dp.id = id;
    strcpy(dp.tipe, tipe);
    strcpy(dp.status, status);
    return dp;
}

data_child make_data_child(int id, string status_cucian, float berat) {
    data_child dc;
    dc.id = id;
    strcpy(dc.status_cucian, status_cucian);
    dc.berat = berat;
    return dc;
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

void distribute(multilist *l) {
    address_parent p, pq = NULL;
    address_child q;

    multilist f;
    init_empty(&f);
    for (p = l->first_parent; p != NULL; p = p->next)
        insert_last_parent(&f, p->dp);

    int counter = 0;
    for (p = l->first_parent; p != NULL; p = p->next) {
        if (!have_children(p)) continue;
        for (q = p->first_child; q != NULL; q = q->next) {
            if (pq == NULL)
                pq = f.first_parent;
            insert_last_child(f, pq->dp.id, q->dc);
            pq = pq->next;
        }
    }

    *l = f;
}
