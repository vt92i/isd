#include "header.h"

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
