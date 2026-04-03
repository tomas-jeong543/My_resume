#pragma once;
typedef struct Node {
	int data;
	Node* next = NULL;

}Node;

Node* Create_Node(int data);
void push(int data);
int pop();
int peek();
bool Is_Empty();
void init();
void Remove_All();
Node* Get_top();
