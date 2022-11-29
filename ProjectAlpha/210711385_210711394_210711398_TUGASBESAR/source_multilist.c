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

address_parent find_parent(multilist l, int id_parent) {
    address_parent p = l.first_parent;
    while (p != NULL && p->dp.id != id_parent) {
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
    address_parent p = find_parent(*l, id_parent);
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
    printf("[ Parent ] \n");
    printf("ID : %d \n", p->dp.id);
    printf("Tipe : %s \n", p->dp.tipe);
    printf("Status : %s \n", p->dp.status);
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
    address_parent p = find_parent(l, id_parent);
    if (p != NULL) {
        address_child c = allocate_child(data);
        c->next = p->first_child;
        p->first_child = c;
    }
}

void insert_last_child(multilist l, int id_parent, data_child data) {
    address_parent p = find_parent(l, id_parent);
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
    address_parent p = find_parent(l, id_parent);
    if (p != NULL) {
        if (have_children(p)) {
            address_child c = p->first_child;
            p->first_child = p->first_child->next;
            free(c);
        }
    }
}

void delete_last_child(multilist l, int id_parent) {
    address_parent p = find_parent(l, id_parent);
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
    printf("\t[ Child ] \n");
    printf("\tID : %d \n", c->dc.id);
    printf("\tStatus Cucian : %s \n", c->dc.status_cucian);
    printf("\tBerat : %.2f KG\n", c->dc.berat);
}

void print_all_children(address_parent p) {
    address_child c;
    for (c = p->first_child; c != NULL; c = c->next) {
        print_child(c);
        printf("\n");
    }
}

// Utility
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

void distribute(multilist* l) {
    address_parent p, pq = NULL;
    address_child q;

    multilist f;
    init_multilist(&f);
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
