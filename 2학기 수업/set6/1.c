#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

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

void printTree(Node* root, int level) {
    if(root == NULL) return;
    printTree(root->right, level + 1);
    for(int i = 0; i < level; i++) printf("    ");
    printf("%d\n", root->data);
    printTree(root->left, level + 1);
}

int main() {
    Node* root = createTree();
    printTree(root, 0);
    return 0;
}