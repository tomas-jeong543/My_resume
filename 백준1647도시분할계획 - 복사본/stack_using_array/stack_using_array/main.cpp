#include <stdio.h>
#define MAX 5

int stack[MAX];
int top;

void initialize() {
	top = -1;
}

bool isEmpty() {
	return top == -1;
}

bool isFull() {
	return top == MAX - 1;
}

int peek() {
	if (isEmpty()) {
		printf("Stack is empty!\n");
		return -1;
	}
	return stack[top];
}

void push(int value) {
	if (isFull()) {
		printf("Stack Overflow!\n");
		return;
	}

	top += 1;
	stack[top] = value;
}

int pop() {
	if (isEmpty()) {
		printf("Stack Underflow!\n");
		return -1;
	}
	int value = stack[top];

	top -= 1;

	return value;
}

int main() {
	
	initialize();
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	pop();
	int topnum = peek();
	//주의해야 한다 배열을 이용해서 스택을 구현하는 경우에는 마지막 요소가 pop됬다고 그 값이 사라지는 것이 아니다
	printf("%d\n", stack[MAX - 1]);
	printf("%d\n", topnum);
	return 0;
}