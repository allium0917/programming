#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* search(Node* root, int key) {
    if (root == NULL) return NULL;

    if (root->data == key) return root;
    else if (root->data < key) return search(root->right, key);
    else return search(root->left, key);
}
Node* insert(Node* root, int key) {
    if (root == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = key;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (key < root->data) root->left = insert(root->left, key);
    else if (key > root->data) root->right = insert(root->right, key);

    return root;
}
Node* del(Node* root, int key){
    if (root == NULL) return NULL;

    if (key < root->data)
        root->left = del(root->left, key);

    else if (key > root->data)
        root->right = del(root->right, key);

    else {

        if (root->left == NULL) {
            Node* temp = root->right; free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left; free(root);
            return temp;
        }

        Node* cur = root->right;
        while (cur->left != NULL) cur = cur->left;
        root->data = cur->data;
        root->right = del(root->right, cur->data);

    }

    return root;
}

//경우1:왼쪽만(둘다 < 현노드) -> 재귀
//경우2:오른쪽만(둘다 > 현노드) -> 재귀
//경우3:왼쪽 하나 오른쪽 하나

Node* find(Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (root->data > n1 && root->data > n2)
        return find(root->left, n1, n2);
    if (root->data < n1 && root->data < n2)
        return find(root->right, n1, n2);
    return root;
}

void printTree(Node* root, int level) {
    if(root == NULL) return;
    printTree(root->right, level + 1);
    for(int i = 0; i < level; i++) printf("    ");
    printf("%d\n", root->data);
    printTree(root->left, level + 1);
}

int main() {
    Node* root = NULL;

    root = insert(root, 40);
    insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 60);
    insert(root, 50);
    insert(root, 70);

    Node* result = search(root, 10);

    if (result != NULL)
        printf("%d\n", result->data);
    else
        printf("없\n");

    printTree(root, 0);

    Node* lca = find(root, 10, 30);
    printf("%d\n", lca->data);

    return 0;
}