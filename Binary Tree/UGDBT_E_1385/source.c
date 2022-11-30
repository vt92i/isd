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

bool is_found(binary_tree bt, string jenis_mobil) {
    if (is_empty(bt))
        return false;
    else
        return strcmp(bt->mobil.jenis_mobil, jenis_mobil) == 0 ||
               is_found(bt->left, jenis_mobil) ||
               is_found(bt->right, jenis_mobil);
}

address allocate_data(string jenis_mobil, string merk_mobil, string warna_mobil) {
    address p = (node *)malloc(sizeof(node));
    if (p == NULL)
        return NULL;
    else {
        strcpy(p->mobil.jenis_mobil, jenis_mobil);
        strcpy(p->mobil.merk_mobil, merk_mobil);
        strcpy(p->mobil.warna_mobil, warna_mobil);

        p->left = p->right = NULL;
        return p;
    }
}

void insert_tree_bst(binary_tree *bt, mobil m[], int index) {
    if (index > 64 - 1) return;

    if (strcmp(m[index].jenis_mobil, "") == 0)
        insert_tree_bst(bt, m, index + 1);

    else {
        if (is_empty(*bt)) {
            *bt = allocate_data(m[index].jenis_mobil, m[index].merk_mobil, m[index].warna_mobil);
            insert_tree_bst(bt, m, index + 1);
        } else {
            if (index < 5)
                insert_tree_bst(&(*bt)->left, m, index);
            else
                insert_tree_bst(&(*bt)->right, m, index);
        }
    }
}

void delete_tree_at(binary_tree *bt, string jenis_mobil) {
    if (strcmp((*bt)->mobil.jenis_mobil, jenis_mobil) == 0) {
        delete_tree(&(*bt));
    } else {
        if (is_found((*bt)->left, jenis_mobil))
            delete_tree_at(&(*bt)->left, jenis_mobil);
        else
            delete_tree_at(&(*bt)->right, jenis_mobil);
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
        printf("%s - %s - %s \n", bt->mobil.jenis_mobil, bt->mobil.merk_mobil, bt->mobil.warna_mobil);
        preoder(bt->left);
        preoder(bt->right);
    }
}
//
void inorder(binary_tree bt) {
    if (!is_empty(bt)) {
        inorder(bt->left);
        printf("%s - %s - %s \n", bt->mobil.jenis_mobil, bt->mobil.merk_mobil, bt->mobil.warna_mobil);
        inorder(bt->right);
    }
}

void postorder(binary_tree bt) {
    if (!is_empty(bt)) {
        postorder(bt->left);
        postorder(bt->right);
        printf("%s - %s - %s \n", bt->mobil.jenis_mobil, bt->mobil.merk_mobil, bt->mobil.warna_mobil);
    }
}

// void update_tree(binary_tree *bt, string jenis_mobil, string new_data) {
//     if (strcmp((*bt)->mobil.jenis_mobil, jenis_mobil) == 0) {
//         strcpy((*bt)->mobil.jenis_mobil, new_data);
//         return;
//     } else {
//         if (is_found((*bt)->left, jenis_mobil))
//             update_tree(&(*bt)->left, jenis_mobil, new_data);
//         else
//             update_tree(&(*bt)->right, jenis_mobil, new_data);
//     }
// }

void init_mobil(mobil m[], int index) {
    if (index > ARRAY_LENGTH - 1) return;
    strcpy(m[index].jenis_mobil, "");
    strcpy(m[index].merk_mobil, "");
    strcpy(m[index].warna_mobil, "");
    init_mobil(m, index + 1);
}

bool is_unique(mobil m[], string jenis_mobil, int index) {
    if (index > ARRAY_LENGTH - 1) return true;

    if (strcmp(m[index].jenis_mobil, jenis_mobil) == 0)
        return false;

    is_unique(m, jenis_mobil, index + 1);
}
