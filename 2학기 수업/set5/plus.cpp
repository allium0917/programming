#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// 새 노드 생성 함수
Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 리스트 출력 함수
void printList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL");
}

// 맨 앞에 노드 삽입
Node* insertFront(Node *head, int data) {
    Node *newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// 중간(중앙)에 노드 삽입
Node* insertMiddle(Node *head, int data) {
    if (head == NULL) return createNode(data);

    Node *slow = head;         // 1칸씩 이동
    Node *fast = head->next;   // 2칸씩 이동

    // fast가 끝 또는 끝 바로 앞까지 이동
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *newNode = createNode(data);
    newNode->next = slow->next;
    slow->next = newNode;
    return head;
}

int main() {
    int nodeCount, insertValue, insertOption;
    Node *head = NULL;
    Node *last = NULL;

    // 초기 리스트 입력
    scanf("%d", &nodeCount);
    for (int i = 0; i < nodeCount; i++) {
        int value;
        scanf("%d", &value);
        Node *newNode = createNode(value);
        if (head == NULL) {
            head = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }

    // 삽입 옵션과 값 입력
    scanf("%d %d", &insertOption, &insertValue);

    if (insertOption == 1) {
        head = insertFront(head, insertValue);
    } else if (insertOption == 2) {
        head = insertMiddle(head, insertValue);
    } else {
        printf("ERROR");
    }

    // 리스트 출력
    printList(head);

    // 메모리 해제
    Node *current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}