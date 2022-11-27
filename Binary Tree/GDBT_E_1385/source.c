#include "header.h"

void init_empty(binary_tree *bt) {
    *bt = NULL;
}

bool is_empty(binary_tree bt) {
    return bt == NULL;
}

bool is_leaf(binary_tree bt) {
    return is_empty(bt->left) && is_empty(bt->right);
}

bool is_found(binary_tree bt, string jenis_pokemon) {
    if (is_empty(bt))
        return false;
    else
        return strcmp(bt->pokemon.jenis_pokemon, jenis_pokemon) == 0 ||
               is_found(bt->left, jenis_pokemon) ||
               is_found(bt->right, jenis_pokemon);
}

address allocate_data(int hp, string jenis_pokemon) {
    address p = (node *)malloc(sizeof(node));
    if (p == NULL)
        return NULL;
    else {
        strcpy(p->pokemon.jenis_pokemon, jenis_pokemon);
        p->pokemon.hp = hp;
        p->left = p->right = NULL;
        return p;
    }
}

void insert_tree_bst(binary_tree *bt, address p) {
    if (is_empty(*bt))
        *bt = p;
    else {
        if (p->pokemon.hp < (*bt)->pokemon.hp)
            insert_tree_bst(&(*bt)->left, p);
        else
            insert_tree_bst(&(*bt)->right, p);
    }
}

void delete_tree_at(binary_tree *bt, string jenis_pokemon) {
    if (strcmp((*bt)->pokemon.jenis_pokemon, jenis_pokemon) == 0) {
        delete_tree(&(*bt));
    } else {
        if (is_found((*bt)->left, jenis_pokemon))
            delete_tree_at(&(*bt)->left, jenis_pokemon);
        else
            delete_tree_at(&(*bt)->right, jenis_pokemon);
    }
}

void delete_tree(binary_tree *bt) {
    if (is_empty(*bt))
        return;
    else {
        delete_tree(&(*bt)->left);
        delete_tree(&(*bt)->right);
        delete_leaf(&(*bt));
    }
}

void delete_leaf(address *p) {
    if (is_leaf(*p)) {
        address a = *p;
        *p = NULL;
        free(a);
    }
}

void preoder(binary_tree bt) {
    if (!is_empty(bt)) {
        printf("%d - ", bt->pokemon.hp);
        preoder(bt->left);
        preoder(bt->right);
    }
}

void inorder(binary_tree bt) {
    if (!is_empty(bt)) {
        inorder(bt->left);
        printf("%d - ", bt->pokemon.hp);
        inorder(bt->right);
    }
}

void postorder(binary_tree bt) {
    if (!is_empty(bt)) {
        postorder(bt->left);
        postorder(bt->right);
        printf("%d - ", bt->pokemon.hp);
    }
}

void update_tree(binary_tree *bt, string jenis_pokemon, string new_data) {
    if (strcmp((*bt)->pokemon.jenis_pokemon, jenis_pokemon) == 0) {
        strcpy((*bt)->pokemon.jenis_pokemon, new_data);
        return;
    } else {
        if (is_found((*bt)->left, new_data))
            update_tree(&(*bt)->left, jenis_pokemon, new_data);
        else
            update_tree(&(*bt)->right, jenis_pokemon, new_data);
    }
}
