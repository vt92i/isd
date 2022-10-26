#include "header.h"

void init_empty(List *L) {
    L->first = NULL;
}

bool is_empty(List L) {
    return L.first == NULL;
}

bool is_one_element(List L) {
    return !is_empty(L) && L.first->next == NULL;
}

address allocate_data(Data D) {
    address P = (Node *)malloc(sizeof(Node));
    P->data = D;
    P->next = NULL;
    return P;
}

// address find_node(List L, Data D) {
//     address P;
//     for (P = L.first; P != NULL && P->data != D; P = P->next)
//         ;
//     return P;
// }

void insert_first(List *L, address new_node) {
    new_node->next = L->first;
    L->first = new_node;
}

void insert_after(address prev_node, address new_node) {
    if (prev_node != NULL) {
        new_node->next = prev_node->next;
        prev_node->next = new_node;
    }
}

void insert_last(List *L, address new_node) {
    address P;
    if (is_empty(*L)) {
        insert_first(L, new_node);
    } else {
        for (P = L->first; P->next != NULL; P = P->next)
            ;
        P->next = new_node;
    }
}

void delete_first(List *L) {
    if (!is_empty(*L)) {
        address del_node = L->first;
        L->first = L->first->next;
        free(del_node);
    }
}

void delete_at(List *L, address del_node) {
    address P;
    if (!is_empty(*L)) {
        if (L->first == del_node) {
            delete_first(L);
        } else {
            for (P = L->first; P->next != del_node; P = P->next)
                ;
            P->next = del_node->next;
            free(del_node);
        }
    }
}

void delete_last(List *L) {
    address P;
    if (!is_empty(*L)) {
        if (is_one_element(*L))
            delete_first(L);
        else {
            for (P = L->first; P->next->next != NULL; P = P->next)
                ;
            free(P->next);
            P->next = NULL;
        }
    }
}

void print_list(List L) {
    address P;
    int counter = 1;
    for (P = L.first; P != NULL; P = P->next) {
        printf("[%d] %s : %d Minutes - %.0f Km \n", counter, P->data.stop, P->data.minutes, P->data.distance);
        counter++;
    }
}

void sort_time(List *L) {
    address P, Q;
    for (P = L->first; P != NULL; P = P->next) {
        for (Q = L->first; Q->next != NULL; Q = Q->next) {
            if (Q->data.minutes > Q->next->data.minutes) {
                Data c = Q->data;
                Q->data = Q->next->data;
                Q->next->data = c;
            }
        }
    }
}

void sort_distance(List *L) {
    address P, Q;
    for (P = L->first; P != NULL; P = P->next) {
        for (Q = L->first; Q->next != NULL; Q = Q->next) {
            if (Q->data.distance > Q->next->data.distance) {
                Data c = Q->data;
                Q->data = Q->next->data;
                Q->next->data = c;
            }
        }
    }
}
