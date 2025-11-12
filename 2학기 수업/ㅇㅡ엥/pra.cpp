// 1.	int 값을 저장하는 단일 연결 리스트(Singly Linked List) 구조체 정의하기.
// 2.	노드 1개 생성해서 값 저장 후 출력하기.
// 3.	리스트의 맨 앞에 노드 추가(push_front) 함수 구현.
// 4.	리스트의 모든 노드 출력(print_list) 함수 구현.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> next = NULL;
    return newNode;
}

void push_front(Node** head, int value) {
    Node * newNode = createNode(value);
    newNode -> next = *head;
    *head = newNode;
}

void print_list(Node* head) {
    Node * tmp = head;
    while (tmp!=NULL) {
        printf("%d ", tmp -> data);
        tmp = tmp -> next;
    }
    printf("\n");
}

void delate(Node** head) {
    Node * tmp = *head;
    *head = (*head) -> next;
    free(tmp);
}

void back_push(Node** head, int value) {
    Node * newNode = createNode(value);
    Node * cur = *head;
    while (cur != NULL) {
        cur = cur -> next;
    }
    cur -> next = newNode;
}

int main() {
    Node * head = NULL;
    push_front(&head, 10);
    push_front(&head, 20);
    push_front(&head, 30);
}