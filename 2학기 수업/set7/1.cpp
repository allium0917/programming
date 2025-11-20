#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Node* search(Node* root, int key) {
//     while (root != NULL) {
//         if (root->data == key) return root;
//         else if (root->data < key) root = root->right;
//         else root = root->left;
//     }
//     return NULL;
// }

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

// int H(Node* root) {
//     if (root == NULL) return -1;
//     int lH = H(root->left);
//     int rH = H(root->right);
//     return (lH > rH ? lH : rH) + 1;
// } 실수로 간선 기준으로 생각해버려써요....

int H(Node* root) {
    if (root == NULL) return 0;
    int lH = H(root->left);
    int rH = H(root->right);
    return (lH > rH ? lH : rH) + 1;
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

    int n, val;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &val);
        root = insert(root, val);
    }

    int a,b,c;
    printf("삽입");
    scanf("%d", &a);
    insert(root, a);

    printf("<UNK>");
    scanf("%d", &b);
    Node* result = search(root, b);

    if (result != NULL)
        printf("%d\n", result->data);
    else
        printf("없\n");

    printTree(root, 0);

    printf("삭제");
    scanf("%d", &c);
    root = del(root, c);

    printTree(root, 0);
    printf("%d\n", H(root));

    return 0;
}