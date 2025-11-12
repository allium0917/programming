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

int main() {
    int n;
    printf("노드 ");
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

    char target[100];
    printf("찾을 수");
    scanf("%s", target);

    Node* temp = head;
    int index = 1;
    int found = 0;
    while (temp) {
        if (strcmp(temp->data, target) == 0) {
            printf("%s 는 %d번째 노드에\n", target, index);
            found = 1;
            break;
        }
        temp = temp->next;
        index++;
    }
    if (!found) printf("없써..\n");
}