#include "header.h"

int is_one_element(list l) {
    return l->next == NULL;
}

int is_empty(list l) {
    return l == NULL;
}

address find_node(list l, int data) {
    if (is_empty(l))
        return NULL;
    else {
        if (l->data != data)
            return find_node(l->next, data);
        return l;
    }
}

address allocate_data(int data) {
    address new_node = (address)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void init_empty(list *l) {
    *l = NULL;
}

void print_list(list l) {
    if (!is_empty(l)) {
        printf("%d \n", l->data);
        print_list(l->next);
    }
}

void insert_first(list *l, address new_node) {
    new_node->next = *l;
    *l = new_node;
}

void insert_after(list *l, address new_node, int prev) {
    address target = find_node(*l, prev);
    if (target != NULL) {
        new_node->next = target->next;
        target->next = new_node;
    }
}

void insert_last(list *l, address new_node) {
    if (is_empty(*l))
        insert_first(l, new_node);
    else {
        insert_last(&(*l)->next, new_node);
    }
}

void delete_first(list *l) {
    address temp = *l;
    *l = (*l)->next;
    free(temp);
}

void delete_at(list *l, address target) {
    if (*l != target)
        delete_at(&(*l)->next, target);
    else
        delete_first(l);
}

void delete_last(list *l) {
    if (!is_one_element(*l))
        delete_last(&(*l)->next);
    else
        delete_first(l);
}
