#include "header.h"

void init_empty(multilist* l) {
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
    while (p != NULL && p->dp.id_tim != id_parent) {
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
    if (is_empty(*l)) {
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
    if (!is_empty(*l)) {
        address_parent p = l->first_parent;
        delete_all_children(p);
        l->first_parent = l->first_parent->next;
        free(p);
    }
}

void delete_at_parent(multilist* l, int id_parent) {
    if (!is_empty(*l)) {
        if (l->first_parent->dp.id_tim == id_parent) {
            delete_first_parent(l);
        } else {
            address_parent p = l->first_parent;
            while (p->next != NULL && p->next->dp.id_tim != id_parent) {
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
    if (!is_empty(*l)) {
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
    printf("ID Tim : %d \n", p->dp.id_tim);
    printf("Nama Tim : %s \n", p->dp.nama_tim);
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
    address_parent p = l.first_parent;
    while (p != NULL) {
        print_parent(p);
        printf("\n");
        p = p->next;
    }
}

bool is_empty(multilist l) {
    return l.first_parent == NULL;
}

bool have_children(address_parent p) {
    return p->first_child != NULL;
}
