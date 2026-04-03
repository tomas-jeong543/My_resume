#include<stdio.h>
#include<stdlib.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Implement a binary tree | linked lists

//이진 트리 노드의 구성요소를 나타내는 구조체
typedef struct TreeNode {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;

//트리 점을 만들어 반환하는 함수
TreeNode* createNode(int data) {
	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
	if (newNode == nullptr) { printf("동적 메모리 할당 오류\n"); return NULL; }
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

//전체 트리를 삭제하는 함수
void freeTree(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	freeTree(root->left);
	freeTree(root->right);
	free(root);
}

//트리를 출력하는 함수 중순위 순회로 데이터를 출력하고 있다
void printTree(TreeNode* root, int indent) {
	//base 케이스
	if (root == NULL) return;

	//왼쪽 점이 존재시 왼쪽 점 부터 방문
	if (root->left) {
		printTree(root->left, indent + 4);
		for (int i = 0; i < indent + 2; i++) printf(" ");
		printf("/\n");
	}
	//가운데 점 방문
	for (int i = 0; i < indent; i++) printf(" ");
	printf("%d\n", root->data);
	//오른쪽 방문
	if (root->right) {
		for (int i = 0; i < indent + 2; i++) printf(" ");
		printf("\\\n");
		printTree(root->right, indent + 4);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Implement a binary tree | array 배열로 구현한 이진 트리의 저장 주로 완전이진 트리나 perfect binary tree에 사용이 된다.
#define MAX_SIZE 20

int BT_Array[MAX_SIZE];
int BT_Array_Size = 0;

void insertBT_Array(int value) {
	if (BT_Array_Size >= MAX_SIZE) {
		printf("Tree is full!\n");
		return;
	}
	BT_Array[BT_Array_Size] = value;
	BT_Array_Size = BT_Array_Size + 1;
}

void printBT_Array() {
	printf("\nParent-Child Relations:\n");
	for (int i = 0; i < BT_Array_Size; i++) {
		//부모와 자식 관계 왼쪽 자식은 부모 위치 * 2 + 1, 오른쪽은  부모위치 * 2 + 2에 저장되어 있다는 점을 이용한다.
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		//자식들이 존재시 출력
		if (left < BT_Array_Size) {
			printf("Parent %d: ", BT_Array[i]);
			printf("Left = %d ", BT_Array[left]);
		}
		if (right < BT_Array_Size) {
			printf("Right = %d", BT_Array[right]);
		}
		printf("\n");
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Implement a binary search tree
TreeNode* insertBST(TreeNode* root, int data) {
	//재귀 구조 + 이진 탐색 트리의 왼쪽 서브트리의 최댓값은 루트값보다 작고 루트값은 오른쪽 서브트리의 최솟값보다 크다는 점을 이용한 삽입
	if (root == NULL) {
		return createNode(data);
	}
	if (data < root->data) {
		root->left = insertBST(root->left, data);
	}
	else if (data > root->data) {
		root->right = insertBST(root->right, data);
	}
	return root;
}

//탐색 역시 같은 방법으로 찾는다.
TreeNode* searchBST(TreeNode* root, int target_data) {
	if (root == NULL || root->data == target_data) {
		return root;
	}
	else if (target_data < root->data) {
		return searchBST(root->left, target_data);
	}
	else {
		return searchBST(root->right, target_data);
	}
}

//트리의 점을 삭제하는 함수 여기에서는 왼쪽 서브트리의 가장 큰 값을 루트로 바꾸는 방법을 이용했다.
TreeNode* deleteBST(TreeNode* root, int target_data) {
	//우선 탐색을 통해서 찾는다. 재귀를 통한 탐색을 이용한다.
	if (root == NULL) {
		return root;
	}
	else if (target_data < root->data) {
		root->left = deleteBST(root->left, target_data);
	}
	else if (target_data > root->data) {
		root->right = deleteBST(root->right, target_data);
	}//가장 핵심인 부분 지우려는 데이터를 발견했을 때
	else {
		//왼쪽 노드나 오른쪽 노드가 존재하지 않는 경우에 대해서는 그 반대쪽 노드를 루트로 삼고 원래 루트를 삭제한다
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		////양쪽 자식이 모두 존재하는 경우 오른쪽 서브트리의 가장 작은 값을 루트로 삼는다.
		//TreeNode* temp = root->right;
		//while (temp && temp->left != NULL) {
		//	temp = temp->left;
		//}
		////값은 대체하고 다시 재귀 함수를 호출해 오른쪽 서브트리에서 대체된 값을 가진 점을 지운다.
		//root->data = temp->data;
		//root->right = deleteBST(root->right, temp->data);

		//양쪽 자식이 모두 존재하는 경우 왼쪽 서브트리의 가장 큰 값을 루트로 삼는다.
		TreeNode* temp = root->left;
		while (temp && temp->right != NULL) {
			temp = temp->right;
		}
		//값은 대체하고 다시 재귀 함수를 호출해 왼쪽 서브트리에서 대체된 값을 가진 점을 지운다.
		root->data = temp->data;
		root->left = deleteBST(root->left, temp->data);
	}

	//최종 반환
	return root;
}

int main() {
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Simple creation of a binary tree
	printf("-------- 1. Simple binary tree\n");
	TreeNode* root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->left->left->right = createNode(6);

	// Visualize the binary tree
	printTree(root, 0);
	// Free the tree
	freeTree(root);
	printf("\n\n\n\n\n");

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Create a binary tree using an array
	printf("-------- 2. Binary tree uisng an array\n");
	insertBT_Array(1);
	insertBT_Array(2);
	insertBT_Array(3);
	insertBT_Array(4);
	insertBT_Array(5);
	insertBT_Array(6);
	insertBT_Array(7);

	printBT_Array();
	printf("\n\n\n\n\n");

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Create a binary search tree
	printf("-------- 3. Binary search tree\n");
	TreeNode* bstRoot = createNode(10);
	bstRoot = insertBST(bstRoot, 5);
	bstRoot = insertBST(bstRoot, 3);
	bstRoot = insertBST(bstRoot, 12);
	bstRoot = insertBST(bstRoot, 1);
	bstRoot = insertBST(bstRoot, 4);
	bstRoot = insertBST(bstRoot, 7);
	bstRoot = insertBST(bstRoot, 8);
	bstRoot = insertBST(bstRoot, 6);

	// Search the node (7) in the binary search tree
	TreeNode* search_result = searchBST(bstRoot, 7);
	if (search_result == NULL) {
		printf("Target data is not exist in the Tree \n");
	}
	else {
		printf("Target data is exist in the Tree \n");
	}

	// Visualize the binary search tree
	printTree(bstRoot, 0);
	printf("\n\n");

	// Delete the node (5) in the binary search tree
	printf("checjpoint\n");
	bstRoot = deleteBST(bstRoot, 5);

	// Visualize the binary search tree after deletion
	printTree(bstRoot, 0);
	freeTree(bstRoot);

	return 0;
}
