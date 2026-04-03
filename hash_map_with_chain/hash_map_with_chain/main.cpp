#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//해시 저장 구조의 용량
#define CAPACITY 10
//현재 크기를 설정한다 나중에 변경할 수 있게 변수로 선언합니다.
int current_capa = CAPACITY;


//해시값을 생성하는 해시 함수
unsigned long hash(const char* str) { // djb2
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

//기본 구성 요소로는 key값 value값  hash값 그리고 다음 점을 가르키는 포인터 값으로 구성이 되어 있습니다
typedef struct Node {
    char* key;
    int value;
    unsigned long hash;
    struct Node* next;
} Node;

//이러한 점들을 저장하는 공간의 맨 앞의 주소를 가르키는 포인터
Node** bucket = NULL;

//해시맵의 크기 정보를 이용해 해시맵을 생성하는 함수
void init_bucket(int size) {
    //초기화 및 동적 할당하는 과정
    current_capa = size;
    bucket = (Node**)calloc(current_capa, sizeof(Node*));
}

//삽입 함수
void chain_insert(const char* key, int value) {
    //해시값과 해시값과 크기 정보를 이용해 얻은 인덱스 위치 값을 획득합니다.
    unsigned long h = hash(key);
    unsigned long index = h % current_capa;

    printf("Trying to insert %s at index %lu (hash: %lu)\n", key, index, h);
    //점에 동적 메모리 할당
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) { printf("오류 발생\n"); return; }
    
    //점의 key값 동적 할당 및 내용복사
    new_node->key = (char*)malloc(strlen(key) + 1);
    if (new_node->key != NULL) {
        strcpy_s(new_node->key, strlen(key) + 1, key);
    }

    //점 정보의 초기화
    new_node->value = value;
    new_node->hash = h;
    //체인을 거는 과정 이 코드 상으로는 3번째요소 -> 2번째 요소 -> 1번째 요소 순으로 연결이 되어 있다. 나중에 삽입된 요소일 수록 앞쪽에 배치가 되어 있다는 의미이다.
    new_node->next = bucket[index];
    bucket[index] = new_node;
}

//KEY값을 이용해 요소 정보를 획득하는 함수
int chain_get(const char* key) {
    //해시값의 모듈러 연산을 통해 인덱스 정보를 획득합니다
    unsigned long index = hash(key) % current_capa;
    //현재 점의 인덱스 정보를 통해 그 점이 비거나 요소를 찾을 땨까지 WHILE문에서 일치하는 키 값이 있는지 비교하고 있으면 그 value값을 반환한다.
    Node* curr = bucket[index];
    //일치하는 키 값을 찾는 과정
    while (curr) {
        if (strcmp(curr->key, key) == 0) return curr->value;
        curr = curr->next;
    }
    //존재하지 않는 경우에 대한 예외처리
    return -1;
}

//있는 요소를 제거하는 함수로 찾는 함수와 유사하다
void chain_remove(const char* key) {

    unsigned long index = hash(key) % current_capa;
    Node* curr = bucket[index], * prev = NULL;
    while (curr) {
        //삭제하려는 키 값을 발견한 경우
        if (strcmp(curr->key, key) == 0) {
            //만약 삭제하려는 점이 첫번째 요소가 아닌 경우 단방향 연결 리스트와 마찬가지로 이전 점과 현재 점의 다음 점을 연결한 후 목표로 한 삭제 점을 삭제한다
            if (prev) prev->next = curr->next;
            //삭제하려는 키 값이 첫번째 요소인 경우 두 번째 점을 첫번째 점에 위치로 이동시키고 첫 번째 점요소를 삭제한다
            else bucket[index] = curr->next;
            //동적 데이터의 메모리 해제
            free(curr->key);
            free(curr);
            return;
        }
        //아닌 경우에 대해서는 탐색을 계속이어간다
        prev = curr;
        curr = curr->next;
    }
}

void print_chain_bucket() {
    printf("\n[Bucket - Chaining]\n");
    for (int i = 0; i < current_capa; i++) {
        //키 값
        printf("[%d] ", i);
        Node* curr = bucket[i];
        //그 키 값에 해당되는 요소들의 출력 없을 때까지
        while (curr) {
            printf("(%s:%d) -> ", curr->key, curr->value);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

// Rehashing for Chaining
void chain_rehash_bucket() {
    //1.3은 크게 의미가 있는 수치는 아니다.
    int new_size = current_capa * 1.3;
    //동적 메모리 재할당
    Node** new_bucket = (Node**)calloc(new_size, sizeof(Node*));
    if (new_bucket == NULL) { return; }
    for (int i = 0; i < current_capa; i++) {
        //기존 점들의 위치 정보를 다시 재조정하는 과정이다.
        Node* curr = bucket[i];
        //chain에 더 이상 요소가 존재하지 않는 경우에는 그냥 넘어간다.
        while (curr) {
            //다음 점으로 이동하기 위한 작업
            Node* next = curr->next;
            //현재 점의 해시값과 변화된 크기에 따른 나머지 값을 new_index에 저장한다
            unsigned long new_index = curr->hash % new_size;
            //같은 키에 있는 값에 대한 삽입 과정
            curr->next = new_bucket[new_index];
            new_bucket[new_index] = curr;
            //다음 점으로 이동
            curr = next;
        }
    }
    //기존 bucket의 메모리를 해제하고 새로운 bucket으로 바꾼다. 또한 변화된 크기 정보 역시 갱신을 한다.
    free(bucket);
    bucket = new_bucket;
    current_capa = new_size;

    printf("Chaining bucket rehashed to size %d\n", current_capa);
}

//hashmap 메모리 할당의 해제
void free_chain_bucket() {
    for (int i = 0; i < current_capa; i++) {
        Node* curr = bucket[i];
        while (curr) {
            Node* next = curr->next;
            free(curr->key);
            free(curr);
            curr = next;
        }
    }
    free(bucket);
    bucket = NULL;
}

int main() {
    printf("=== Hash Table with Chaining ===\n");
    init_bucket(CAPACITY);
    chain_insert("apple", 100);
    chain_insert("banana", 80);
    chain_insert("grape", 120);
    chain_insert("melon", 90);
    chain_insert("lemon", 95);

    print_chain_bucket();

    printf("Price of lemon: %d\n", chain_get("lemon"));

    chain_rehash_bucket();

    print_chain_bucket();

    free_chain_bucket();

    return 0;
}