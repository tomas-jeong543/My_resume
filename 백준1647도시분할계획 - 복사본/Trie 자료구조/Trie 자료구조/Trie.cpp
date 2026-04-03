#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//문자열을 개수를 정한다
#define ALPHABET_SIZE 26

// Trie node structure 트라이 구조의 점의 구성 요소는 트라이 점들의 배열과 끝 단어 여부를 나타내는 변수가 있다.
typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
} TrieNode;

//새로운 점을 만드는 함수이다.
TrieNode* createNode() {
    //점 생성
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    //끝 점 여부 초기화
    node->isEndOfWord = false;
    //자식 노드 초기화
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    //생성한 점의 포인터를 반환한다.
    return node;
}

//문자열 삽입하는 함수
void insert(TrieNode* root, const char* word) {
    
    TrieNode* curr = root;
    //문자열의 끝점 도달 전까지 반복한다
    for (int i = 0; word[i] != '\0'; i++) {
        //인덱스 정보 획득
        int index = word[i] - 'a';
        //만약 자식이 존재하지 않는 경우에는 자식 생성
        if (curr->children[index] == NULL)
            curr->children[index] = createNode();
        //자식 점으로 이동
        curr = curr->children[index];
    }
    //끝점 도달시 현재점의 마지막 문자열 정보를 true로 바꾼다.
    curr->isEndOfWord = true;
}
//탐색하는 함수 삽입함수와 유사하다
bool search(TrieNode* root, const char* word) {
    TrieNode* curr = root;
    //문자열 끝까지 탐색
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        //현재 문자열의 점이 존재하지 않는다면 그 단어가 존재하지 않는다는 의미이기 때무에 거짓 반환
        if (curr->children[index] == NULL)
            return false;
        curr = curr->children[index];
    }
    // 이 부분이 중요하다 모든 단어가 경로에 있더라도 그 단어가 문장의 끝이 아니라면 거짓을 반환하게 된다 한마디로 cart를 입력하고 car단어가 있는지 찾으면 없다고 나온다는 의미이다.
    return curr->isEndOfWord;
}

//트리가 자식이  하나라도 존재하는 지 알려주는 함수
bool isEmpty(TrieNode* root) {
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i]) return false;
    return true;
}
//단어를 삭제하는 함수
TrieNode* deleteWord(TrieNode* root, const char* word, int depth = 0) {
    //단어 미존재 base케이스로  NULL값을 반환한다.
    if (!root) {
        return NULL;
    }

    //단어의 끝에 도달한 경우에는
    if (word[depth] == '\0') {
        //만약 단어의 문자가 끝이라고 되어 있다면 그 단어는 이제 존재하지 않음으로 거짓으로 값을 변경한다
        if (root->isEndOfWord)
            root->isEndOfWord = false;
        //만약 그 문자가 자식이 하나도 없으면 그 문자를 삭제하고 NULL을 반환하고 하나라도 있으면 그 문자를 반환한다
        if (isEmpty(root)) {
            free(root);
            return NULL;
        }
        return root;
    }

    //현재 문자의 위치 정보를 획득한다
    int index = word[depth] - 'a';
    //그 곳으로 이동해 단어를 삭제하기 위해서 이동한다 다음 문자로 이동
    root->children[index] = deleteWord(root->children[index], word, depth + 1);
    //만약 현재 문자가 자식이 없고 어떤 단어의 끝문자가 아니라면 그 문자역시 지우고 NULL값을 반환한다.
    if (isEmpty(root) && !root->isEndOfWord) {
        free(root);
        return NULL;
    }

    return root;
}

int main() {
    TrieNode* root = createNode();

    insert(root, "hello");
    insert(root, "hi");
    insert(root, "hill");
    insert(root, "toma");
    printf("Search results:\n");
    printf("hi: %s\n", search(root, "hi") ? "Found" : "Not Found");
    printf("hill: %s\n", search(root, "hill") ? "Found" : "Not Found");
    printf("hive: %s\n", search(root, "hive") ? "Found" : "Not Found");

    printf("\nInsert hive:\n");
    insert(root, "hive");
    printf("hive: %s\n", search(root, "hive") ? "Found" : "Not Found");

    deleteWord(root, "hi");
    printf("\nDelete hi:\n");
    printf("hi: %s\n", search(root, "hi") ? "Found" : "Not Found");

    deleteWord(root, "tomas");
    return 0;
}