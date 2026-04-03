#include <stdio.h>
#include <stdlib.h>
//점
typedef struct Node {
    int data;
    struct Node* next;
} Node;

//점의 정보 중 시작과 끝을 가르키는 포인터 둘 초기화
Node* front = NULL, * rear = NULL;

void enqueue(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    //예외 처리
    if (!newNode) {
        printf("Heap Overflow!\n");
        return;
    }
    //새로운 점 초기화
    newNode->data = value;
    newNode->next = NULL;

    //처음 점 예외처리
    if (rear == NULL) { // if the element is the first one
        front = rear = newNode;
    }//newnode와 앞 점을 연결하고 rear가 새로운 점을 가르키게 함
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue() {
    if (front == NULL) {
        printf("Queue Underflow!\n");
        return -1;
    }

    Node* temp = front;
    int value = temp->data;
    front = front->next;

    //만약 요소가 하나밖에 없는 경우에는
    if (front == NULL) rear = NULL; // if the element is the last one
    free(temp);
    return value;
}

void print() {
    //시작점을 점을 가르키는 포인터로 받아온다
    Node* temp = front;
    //출력
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    print();
    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());
    print();

    return 0;
}
