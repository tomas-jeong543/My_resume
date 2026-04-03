#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	Node* next = NULL;

}Node;

Node* top = NULL;


void init()
{
	top = NULL;
}


void Remove_All()
{
	while (top != NULL) {
		Node* tmp = top;
		top = top->next;
	}
	
}


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
		return -1;
	}
	return top->data;
}

Node* Get_top(){
	return top;
}


bool Is_Empty()
{
	if (top == NULL) {
		return true;
	}

	return false;
}