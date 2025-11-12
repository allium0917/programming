#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Stack {
    Node* node;
    struct Stack* next;
} Stack;

void push(Stack** top, Node* node) {
    Stack* newNode = (Stack*)malloc(sizeof(Stack));
    newNode->node = node;
    newNode->next = *top;
    *top = newNode;
}

Node* pop(Stack** top) {
    if(*top == NULL) return NULL;
    Stack* temp = *top;
    Node* node = temp->node;
    *top = temp->next;
    free(temp);
    return node;
}

Node* peek(Stack* top) {
    if(top == NULL) return NULL;
    return top->node;
}

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

void midrepeat(Node* root) {
    Stack* stack = NULL;
    Node* current = root;

    while(current != NULL || stack != NULL) {
        while(current != NULL) {
            push(&stack, current);
            current = current->left;
        }
        current = pop(&stack);
        printf("%d ", current->data);
        current = current->right;
    }
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
            printf("❗없는뎅\n");
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

    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1: pre(root); break;
        case 2: mid(root); break;
        case 3: back(root); break;
        case 4: midrepeat(root); break;
        default: printf("잘못된 선택"); return 0;
    }
    printf("\n");
    printTree(root, 0);

    return 0;
}