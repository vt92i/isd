#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[64];

typedef struct node *address;
typedef struct node *list;

typedef struct node {
    int data;
    address next;
} node;

int is_one_element(list l);
int is_empty(list l);

address find_node(list l, int data);
address allocate_data(int data);

void init_empty(list *l);
void print_list(list l);

void insert_first(list *l, address new_node);
void insert_after(list *l, address new_node, int prev);
void insert_last(list *l, address new_node);

void delete_first(list *l);
void delete_at(list *l, address target);
void delete_last(list *l);
