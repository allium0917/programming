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

Node* createTree() {
    int n;
    scanf("%d", &n);

    Node** arr = (Node**)malloc(sizeof(Node*) * n);
    for(int i = 0; i < n; i++) {
        arr[i] = (Node*)malloc(sizeof(Node));
        scanf("%d", &arr[i]->data);
        arr[i]->left = NULL;
        arr[i]->right = NULL;
    }
    for(int i = 0; i < n; i++) {
        if(2*i + 1 < n) arr[i]->left = arr[2*i + 1];
        if(2*i + 2 < n) arr[i]->right = arr[2*i + 2];
    }
    return arr[0];
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
    Node* root = createTree();

    int ch;
    scanf("%d", &ch);


    switch(ch) {
        case 1: pre(root); break;
        case 2: mid(root); break;
        case 3: back(root); break;
        default: printf("잘못된 선택"); return 0;
    }
    printf("\n");
    printTree(root, 0);
    printf("\n");
    return 0;
}