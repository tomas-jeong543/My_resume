#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (node == nullptr) { return nullptr; }
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// Binary Search Tree Implementation
TreeNode* insertBST(TreeNode* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data) {
        root->left = insertBST(root->left, data);
    }
    else if (data > root->data) {
        root->right = insertBST(root->right, data);
    }
    //중복되는 데이터에 재한 처리
    return root;
}

void printTree(TreeNode* root, int indent) {
    if (root == NULL) return;

    // Print left subtree
    if (root->left) {
        printTree(root->left, indent + 4);
        for (int i = 0; i < indent + 2; i++) printf(" ");
        printf("/\n");
    }

    // Print current node
    for (int i = 0; i < indent; i++) printf(" ");
    printf("%d\n", root->data);

    // Print right subtree
    if (root->right) {
        for (int i = 0; i < indent + 2; i++) printf(" ");
        printf("\\\n");
        printTree(root->right, indent + 4);
    }
}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// AVL Tree Implementation 높이를 반환하는 함수 가장 기본이다.
int height(TreeNode* root) {
    if (root == NULL) {
        //말단 노드거나 트리가 빈 경우에는 높이를 0으로 지정한다
        return 0;
    }
    //각 트리의 왼쪽 서브트리와 오른쪽 서브트리를 이용해서 둘 중 더 높이 높은 노드 높이 + 1로 현재 높이를 지정한다 재귀 구조의 이영
    int l = height(root->left);
    int r = height(root->right);
    int max_height;
    if (l > r) {
        max_height = l;
    }
    else {
        max_height = r;
    }
    return max_height + 1;
}

//높이 정보를 이용해서 벨런스 팩터를 계산하는 해 반환하는 함수
int getBalance(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return height(root->left) - height(root->right);
}

//왼쪽 편향된 것을 회전시키는 함수
TreeNode* rotateLL(TreeNode* y) {
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    return x;
}

//오른쪽 편향된 것을 회전시키는 함수
TreeNode* rotateRR(TreeNode* x) {
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    return y;
}

TreeNode* insertAVL(TreeNode* root, int data) {
    //트리가 비어있는 경우
    if (root == NULL) {
        return createNode(data);
    }//bst와 마찬가지로 일단 그 위치에 주어진 숫자를 위치시킨다.

    if (data < root->data) {
        root->left = insertAVL(root->left, data);
    }
    else if (data > root->data) {
        root->right = insertAVL(root->right, data);
    }//중복되는 값에 대한 처리
    else {
        return root;
    }

    //삽입 후 밸런스 정보를 획득한다
    int balance = getBalance(root);
    //printf("mys: %d\n", root->data);
    if (balance > 1 && data < root->left->data)  // LL케이스 인 경우 LL단일 회전을 수행한다.
        return rotateLL(root);
    if (balance < -1 && data > root->right->data) // RR케이스 인 경우 RR단일 회전을 수행한다.
        return rotateRR(root);
    if (balance > 1 && data > root->left->data) { // LR 인 경우 즉 새로 삽입된 점에 의해 밸런스 팩터가 문제가 생기고 그 점보다 데이터값이 큰 경우
        //는 우선적으로 왼쪽 자식을 RR단일 회전을 시킨 뒤에 LL상태를 만들고 그 다음에 LL단일 회전을 시킨다. 
        root->left = rotateRR(root->left);
        return rotateLL(root);
    }
    if (balance < -1 && data < root->right->data) { // RL인 경우에 는 우선적으로 오른쪽 자식을 LL단일 회전을 시킨 뒤에 RR상태를 만들고 그 다음에 RR단일 회전을 시킨다.
        root->right = rotateLL(root->right);
        return rotateRR(root);
    }
    return root;
}

int main() {
    TreeNode* avl = NULL;
    TreeNode* bst = NULL;
    int values[] = { 10, 30, 70, 75, 30};
    for (int i = 0; i < 4; i++) {
        avl = insertAVL(avl, values[i]);
       bst = insertBST(bst, values[i]);
    }
    printf("\nAVL Tree after insertions:\n");
    printTree(avl, 0);
    printf("\---------------------------------------\n");
    printf("\nBST Tree after insertions:\n");
    printTree(bst, 0);
    return 0;
}
