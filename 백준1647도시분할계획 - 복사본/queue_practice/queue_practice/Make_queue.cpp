#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

typedef struct Node {
	int data;
	Node* next = nullptr;
};


Node* front = NULL;
Node* back = NULL;

Node* Make_Node(int data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode == nullptr) { return nullptr; }
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}

void enque(int data)
{
	Node* newnode = Make_Node(data);

	if (front == NULL) {
		front = newnode;
		back = newnode;
		return;
	}
	back->next = newnode;
	back = back->next;
}

int deque()
{
	if (front == NULL) {
		printf("heap underflow\n");
		return -1;
	}

	if (front->next == NULL) {
		int val = front->data;
		free(front);
		front = NULL;
		back = NULL;
		return val;
	}

	Node* tmp = front;
	int val = front->data;
	front = front->next;
	free(tmp);
	return val;
}

void print_queue()
{	
	Node* tmp = front;

	while (tmp != NULL) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}

	free(tmp);
	tmp = NULL;
}

int main()
{
	enque(10);
	enque(20);
	enque(30);
	enque(40);

	print_queue();
	printf("Dequeued: %d\n", deque());
	printf("Dequeued: %d\n", deque());
	print_queue();


	return 0;
}