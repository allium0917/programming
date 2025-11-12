#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node* createNode(int value) {
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> next = NULL;
    return newNode;
}

void printList(Node* head) {
    Node *tmp = head;
    while (tmp !=NULL) {
        printf("%d", tmp -> data);
        tmp = tmp -> next;
    }
    printf("\n");
}

void push_front(Node** head, int value) {
    Node *newnode = createNode(value);
    newnode -> next = *head;
    *head = newnode;
}

void push_back(Node** head, int value) {
    Node *newnode = createNode(value);
    Node *cur = *head;
    while (cur -> next != NULL) {
        cur = cur -> next;
    }
    cur -> next = newnode;
}

void remove_node(Node** head, int value) {


}

int main() {
    Node *head = NULL;
    Node *tail = NULL;

    Node *first = createNode(1);
    printList(head);

    push_front(&head, 1);
    push_front(&head, 2);
    push_front(&head, 3);
    push_back(&head, 4);

    printList(head);
}