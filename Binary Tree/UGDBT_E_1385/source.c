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

address allocate_data(int key, string jenis_mobil, string merk_mobil, string warna_mobil) {
    address p = (node *)malloc(sizeof(node));
    if (p == NULL)
        return NULL;
    else {
        p->mobil.key = key;
        strcpy(p->mobil.jenis_mobil, jenis_mobil);
        strcpy(p->mobil.merk_mobil, merk_mobil);
        strcpy(p->mobil.warna_mobil, warna_mobil);
        p->left = p->right = NULL;
        return p;
    }
}

void insert_tree_bst(binary_tree *bt, address p) {
    if (is_empty(*bt))
        *bt = p;
    else {
        if (p->mobil.key < (*bt)->mobil.key)
            insert_tree_bst(&(*bt)->left, p);
        else
            insert_tree_bst(&(*bt)->right, p);
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

void sort_array(mobil m[], int n) {
    if (n == 1) return;
    int count = 0;

    void for_recursion(int i) {
        if (i > ARRAY_LENGTH - 1) return;

        if (strcmp(m[i].jenis_mobil, m[i + 1].jenis_mobil) > 0) {
            mobil temp = m[i];
            m[i] = m[i + 1];
            m[i + 1] = temp;
            count++;
        }

        for_recursion(i + 1);
    }
    for_recursion(0);

    if (count == 0) return;
    sort_array(m, n - 1);
}

void print_array(mobil m[], int index) {
    if (index > ARRAY_LENGTH - 1) return;

    if (strcmp(m[index].jenis_mobil, "") == 0)
        print_array(m, index + 1);
    else {
        printf("Jenis Mobil : %s \n", m[index].jenis_mobil);
        printf("Merk Mobil : %s \n", m[index].merk_mobil);
        printf("Warna Mobil : %s \n\n", m[index].warna_mobil);
        print_array(m, index + 1);
    }
}

int find_car(mobil m[], int index, string jenis_mobil) {
    if (index > ARRAY_LENGTH - 1) return -1;
    if (strcmp(m[index].jenis_mobil, jenis_mobil) == 0) return index;
    find_car(m, index + 1, jenis_mobil);
}

void print_tree(binary_tree bt, int space) {
    if (is_empty(bt)) return;

    space += 5;
    print_tree(bt->right, space);
    printf("\n");

    void print_space(int space) {
        if (space > 5) {
            printf(" ");
            print_space(space - 1);
        }
    }
    print_space(space);

    printf("%d \n", dec2bin(bt->mobil.key));
    print_tree(bt->left, space);
}

int bin2dec(int bin) {
    int dec = 0, i = 0, rem;

    void while_recursive() {
        if (bin == 0) return;
        rem = bin % 10;
        bin /= 10;
        dec += rem * pow(2, i);
        ++i;
        while_recursive();
    }
    while_recursive();

    return dec;
}

int dec2bin(int dec) {
    if (dec == 0)
        return 0;
    else
        return (dec % 2 + 10 * dec2bin(dec / 2));
}
