#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define STRING_LENGTH 128
#define ARRAY_LENGTH 64

typedef char string[STRING_LENGTH];
typedef struct node *address;
typedef struct node *binary_tree;

typedef struct mobil {
    string jenis_mobil, merk_mobil, warna_mobil;
} mobil;

typedef struct node {
    mobil mobil;
    address left;
    address right;
} node;

void init_empty(binary_tree *bt);

bool is_empty(binary_tree bt);
bool is_leaf(binary_tree bt);
bool is_found(binary_tree bt, string jenis_pokemon);

address allocate_data(string jenis_mobil, string merk_mobil, string warna_mobil);

void insert_tree_bst(binary_tree *bt, mobil m[], int index);
void delete_tree_at(binary_tree *bt, string jenis_mobil);
void delete_tree(binary_tree *bt);
void delete_leaf(address *p);

void preoder(binary_tree bt);
void inorder(binary_tree bt);
void postorder(binary_tree bt);

// void update_tree(binary_tree *bt, string jenis_mobil, string new_data);

void init_mobil(mobil m[], int index);
bool is_unique(mobil m[], string jenis_mobil, int index);
