#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	Node* next = NULL;

}Node;

Node* top = NULL;


Node* Create_Node(int data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	
	if (newnode == NULL) {
		printf("Stack_Overflow\n");
		return NULL;
	}

	newnode->data = data;
	return newnode;
}

void push(int data)
{

	Node* newnode = Create_Node(data);
	if (newnode == NULL) { return; }

	newnode->next = top;
	top = newnode;
}


int pop()
{
	if (top == NULL) {
		printf("지울 내용이 없습니다\n");
		return -1;
	}

	Node* tmp = top;
	int value = tmp->data;
	top = top->next;
	free(tmp);
	return value;
}

int peek()
{
	if (top == NULL) {
		printf("지울 내용이 없습니다\n");
		return -1;
	}
	return top->data;
}


int main() {
	push(10);
	push(20);
	push(30);
	printf("Popped: %d\n", pop());
	printf("Popped: %d\n", pop());
	printf("Peek - Top element: %d\n", peek());
	return 0;
}
