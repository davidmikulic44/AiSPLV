#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    char x;
    struct node* left, * right;
}NODE;

NODE* parent;
NODE* root;
int found = 0;

void preOrder(NODE* root) {
    if (root == NULL) return;
    else {
    printf("%c", root->x);
    preOrder(root->left);
    preOrder(root->right);
    }
}

void inOrder(NODE* root) {
    if (root == NULL) return;
    else {
    inOrder(root->left);
    printf("%c", root->x);
    inOrder(root->right);
    }
}

void postOrder(NODE* root) {
    if (root == NULL) return;
    else {
    postOrder(root->left);
    postOrder(root->right);
    printf("%c", root->x);
    }
}

void find(char p, NODE* node) {
    if (node == NULL) {
    return;
    }
    if (node->x == p) {
    found = 1;
    
    return;
    }
    parent = node;
    if (node->x > p) {
    find(p, node->left);
    }
    else {
    find(p, node->right);
    }
}

void add(char p, struct node* node) {
    found = -1;
    parent = NULL;
    find(p, node);
    if (found == 1) {
        return;
    }
    else {
        NODE* n = (NODE*)malloc(sizeof(NODE));
        n->x = p;
        n->left = NULL;
        n->right = NULL;
        if (parent == NULL) {
        root = n;
    }
    else {
        if (p < parent->x) {
            parent->left = n;
        }
        else {
        parent->right = n;
        }
    }
    }
}

int main() {
    char arr[] = "davidmikulic";
    for (int i = 0; i < sizeof(arr) / sizeof(char); i++) {
    
    add(arr[i], root);
    }
    printf("\nPREORDER: ");
    preOrder(root);
    printf("\nINORDER: ");
    inOrder(root);
    printf("\nPOSTORDER: ");
    postOrder(root);
    
    return 0;
}
