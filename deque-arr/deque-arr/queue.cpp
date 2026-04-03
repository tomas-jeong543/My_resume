#include"queue.h"
#define MAX_SIZE 5

int queue[MAX_SIZE];
int rear;
int front;

void initallize()
{
	rear = -1;
	front = -1;
}

bool isEmpty(int rear, int front) {
	return rear == -1 && front == -1;
}

bool isFull(int rear, int front) {
	return rear == MAX_SIZE - 1 && front == -1;
}

void enqueue(int value) {

	printf("%d\n", rear);
	if (rear == front && rear >  0 ) {
		rear = -1;
		front = -1;
	}

	if (rear == MAX_SIZE - 1 && front > 0) {
		rear = 0;
	}

	if (isFull(rear, front)) {
		return;
	}
	
	if (isEmpty(rear, front)) {
		rear += 1;
		front += 1;
		queue[rear] = value;
	}else {
		rear += 1;
		queue[rear] = value;
	}

}

int dequeue()
{
	int value = -1;
	printf("%d\n", rear);
	if (rear == front && rear > 0) {
		rear = -1;
		front = -1;
	}

	if (isEmpty(rear, front) || front == -1) {
		return -1;
	}
	else {
		value = queue[front];
		front += 1;
	}

	
	return value;
}

int main()
{
	initallize();
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	printf("%d\n", dequeue());
	enqueue(50);

	printf("%d %d\n", rear, front);

}