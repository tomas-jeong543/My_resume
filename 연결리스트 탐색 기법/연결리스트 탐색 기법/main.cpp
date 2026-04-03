#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//기본 데이터 타입 노드
typedef struct Node {
    int data;
    struct Node* next;
} Node;

//해드 포인터와 꼬리 포인터
Node* head = NULL;
Node* tail = NULL;

//점 생성하는 함수
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

//새로운 데이터를 마지막 요소 다음에 연결
void append(int data) {
    Node* new_node = create_node(data);
    if (!head) {
        head = tail = new_node;
        return;
    }
    tail->next = new_node;
    tail = new_node;
}
//연결 리스트 출력
void print_list(Node* node) {
    while (node) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Linear search
Node* linear_search(Node* node, int key) {
    //마지막 점 도달 전까지 탐색
    while (node) {
        if (node->data == key) return node;
        node = node->next;
    }
    return NULL;
}

// Sentinel linear search (insert sentinel node at the end)
Node* sentinel_linear_search(Node* head, int key) {
    //만약 요소가 하나도 존재하지 않으면 NULL반환
    if (!head) return NULL;

    //보초 점 하나 생성해 마지막 요소 다음 점에 위치시킨다
    Node* sentinel = create_node(key);
    tail->next = sentinel;

    //head 부터 시작해 탐색한다
    Node* curr = head;
    while (curr->data != key) {
        curr = curr->next;
    }

    //다시 보초로 만든 점은 삭제
    tail->next = NULL;
    free(sentinel);

    //보초와 비교해 보초인 경우 데이터가 존재하지 않음으로 NULL반환 아닌 경우에는 현재 점을 반환한다
    return (curr == sentinel) ? NULL : curr;
}

// Print search result
void print_result(Node* result) {
    if (result) printf("Found: %d\n", result->data);
    else printf("Not found\n");
}

int main() {
    for (int i = 0; i < 100000; i++) append(i * 2);

    int key = 100000;
    printf("Searching for key: %d\n\n", key);

    clock_t start, end;
    double time_taken = 0;
    Node* result = NULL;

    // Repeat multiple times to improve measurement resolution
    int trials = 10000;

    // Linear Search Timing
    start = clock();
    for (int i = 0; i < trials; i++) {
        result = linear_search(head, key);
    }
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / trials;
    printf("Linear Search: ");
    print_result(result);
    printf("Average time taken (over %d trials): %.9f seconds\n\n", trials, time_taken);

    // Sentinel Linear Search Timing
    start = clock();
    for (int i = 0; i < trials; i++) {
        result = sentinel_linear_search(head, key);
    }
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / trials;
    printf("Sentinel Linear Search: ");
    print_result(result);
    printf("Average time taken (over %d trials): %.9f seconds\n\n", trials, time_taken);

    return 0;
}
