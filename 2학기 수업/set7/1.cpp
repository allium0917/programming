#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* search(Node* root, int key) {
    while (root != NULL) {
        if (root->data == key)
            return root;
        else if (root->data < key)
            root = root->right;
        else
            root = root->left;
    }
    return NULL;
}

int main() {
    Node N1 = {10, NULL, NULL};
    Node N2 = {20, &N1, NULL};
    Node N3 = {30, &N2, NULL};
    Node N4 = {40, &N3, NULL};
    Node N5 = {50, &N4, NULL};
    Node N6 = {60, &N5, NULL};
    Node N7 = {70, &N6, NULL};

    Node* result = search(&N2, 10);
    if (result != NULL)
        printf("%d\n", result->data);
    else
        printf("없\n");

    return 0;
}