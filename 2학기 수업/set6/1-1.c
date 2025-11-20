#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* find(Node* root, int target) {
    if(root == NULL) return NULL;
    if(root->data == target) return root;

    Node* left = find(root->left, target);
    if(left) return left;
    return find(root->right, target);
}

void printTree(Node* root, int level) {
    if(root == NULL) return;
    printTree(root->right, level + 1);
    for(int i = 0; i < level; i++) printf("    ");
    printf("%d\n", root->data);
    printTree(root->left, level + 1);
}

int main() {
    int n;
    scanf("%d", &n);


    int rootData;
    scanf("%d", &rootData);

    Node* root = (Node*)malloc(sizeof(Node));
    root->data = rootData;
    root->left = NULL;
    root->right = NULL;

    for(int i = 1; i < n; i++) {
        int data, parentData;
        char dir;

        printf("\ndata: ");
        scanf("%d", &data);
        printf("부모 data: ");
        scanf("%d", &parentData);
        printf("rl: ");
        scanf(" %c", &dir);

        Node* parent = find(root, parentData);
        if(parent == NULL) {
            printf("없는뎅\n");
            i--;
            continue;
        }

        if(dir == 'l') {
            if(parent->left != NULL) {
                printf("이써\n");
                i--;
                continue;
            }
            parent->left = (Node*)malloc(sizeof(Node));
            parent->left->data = data;
            parent->left->left = NULL;
            parent->left->right = NULL;
        }
        else if(dir == 'r') {
            if(parent->right != NULL) {
                printf("이써\n");
                i--;
                continue;
            }
            parent->right = (Node*)malloc(sizeof(Node));
            parent->right->data = data;
            parent->right->left = NULL;
            parent->right->right = NULL;
        }
    }

    printTree(root, 0);

    return 0;
}