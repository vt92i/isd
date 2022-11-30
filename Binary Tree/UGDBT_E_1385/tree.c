#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};

struct node *newNode(int key) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insert(struct node *node, int key) {
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return node;
}

void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d -> ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void print2DUtil(struct node *root, int space) {
    if (root == NULL)
        return;

    space += 5;

    print2DUtil(root->right, space);

    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);

    print2DUtil(root->left, space);
}

void print2D(struct node *root) {
    print2DUtil(root, 0);
}

int main() {
    struct node *root = NULL;

    for (int i = 0; i < 5; i++) {
        int key;
        scanf("%d", &key);
        root = insert(root, key);
    }

    preorder(root);
    print2D(root);
}
