#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

void printTree(Node* root, int level) {
    if(root == NULL) return;
    printTree(root->right, level + 1);
    for(int i = 0; i < level; i++) printf("    ");
    printf("%d\n", root->data);
    printTree(root->left, level + 1);
}

void pre(Node* root) {
    if(root == NULL) return;
    printf("%d ", root->data);
    pre(root->left);
    pre(root->right);
}

void mid(Node* root) {
    if(root == NULL) return;
    mid(root->left);
    printf("%d ", root->data);
    mid(root->right);
}

void back(Node* root) {
    if(root == NULL) return;
    back(root->left);
    back(root->right);
    printf("%d ", root->data);
}

int main() {

    Node N4 = {3, NULL, NULL};
    Node N5 = {7, NULL, NULL};
    Node N2 = {5, &N4, &N5};
    Node N3 = {15, NULL, NULL};
    Node N1 = {10, &N2, &N3};

    int ch;
    Node* root = &N1;
    scanf("%d", &ch);

    switch(ch) {
        case 1: pre(root); break;
        case 2: mid(root); break;
        case 3: back(root); break;
    }
    printf("\n");
    printTree(root, 0);
    printf("\n");
    return 0;
}