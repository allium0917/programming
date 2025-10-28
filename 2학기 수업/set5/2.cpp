#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[100];         // 정수도 문자열로 저장 가능하도록 통일
    struct Node* next;
} Node;

Node* createNode(const char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, value);
    newNode->next = NULL;
    return newNode;
}

// 연결 리스트 길이 구하기
int getLength(Node* head) {
    int len = 0;
    Node* temp = head;
    while (temp) {
        len++;
        temp = temp->next;
    }
    return len;
}

// 전체 출력
void printList(Node* head) {
    Node* temp = head;
    int idx = 1;
    while (temp) {
        printf("[%d] %s -> ", idx++, temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n;
    printf("노드");
    scanf("%d", &n);

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        char buffer[100];
        scanf("%s", buffer);

        Node* newNode = createNode(buffer);
        if (head == NULL) head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printList(head);
}