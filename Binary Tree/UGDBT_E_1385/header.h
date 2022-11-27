#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef char string[128];
typedef struct node *address;
typedef struct node *binary_tree;

typedef struct pokemon {
    string jenis_pokemon;
    int hp;
} pokemon;

typedef struct node {
    pokemon pokemon;
    address left;
    address right;
} node;

void init_empty(binary_tree *bt);

bool is_empty(binary_tree bt);
bool is_leaf(binary_tree bt);
bool is_found(binary_tree bt, string jenis_pokemon);

address allocate_data(int hp, string jenis_pokemon);

void insert_tree_bst(binary_tree *bt, address p);
void delete_tree_at(binary_tree *bt, string jenis_pokemon);
void delete_tree(binary_tree *bt);
void delete_leaf(address *p);

void preoder(binary_tree bt);
void inorder(binary_tree bt);
void postorder(binary_tree bt);

void update_tree(binary_tree *bt, string jenis_pokemon, string new_data);
