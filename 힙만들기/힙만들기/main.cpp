#define MAX_SIZE 100
#include<iostream>

using namespace std;

int heap[MAX_SIZE];
int cursize = 0;

int left(int i) {
	return 2 * i + 1;
}


int right(int i) {
	return 2 * i + 2;
}


int parent(int i) {
	return (i - 1) / 2;
}

void swap(int& x, int& y) {
	int tmp = x;
	x = y;
	y = tmp;
}


void insert(int data) {
	if (cursize >= MAX_SIZE) {
		cout << "공간이 부족합니다" << endl;
		return;
	}

	heap[cursize++] = data;
	int i = cursize - 1;

	while (i >= 0 && heap[parent(i)] < heap[i]) {
		swap(heap[parent(i)], heap[i]);
		i = parent(i);
	}
}

int pop() {
	if (cursize <= 0) {
		cout << "값이 존재하지 않습니다" << endl;
		return -1;
	}

	int top = heap[0];
	heap[0] = heap[--cursize];

	int idx = 0;

	while (true) {
		int prevtop = idx;
		int L = left(idx);
		int R = right(idx);

		if (L <= cursize && heap[L] > heap[idx]) { idx = L; }
		if (R <= cursize && heap[R] > heap[idx]) { idx = R; }

		if (prevtop == idx)break;
		else {
			swap(heap[idx], heap[prevtop]);
		}
	}


	return top;
}

void printHeap() {
	for (int i = 0; i < cursize; i++) {
		cout << heap[i] << "\t";
	}
	cout << endl;
}

void heapify(int arr[],int idx) {
	
	
	int arrsize = 6;
	
	if (idx >= arrsize) {
		return;
	}

	int prevtop = idx;
	int L = left(idx);
	int R = right(idx);
	cout << "L: " << L << " R: " << R << endl;
	if (L <= arrsize && arr[L] > arr[idx]) { idx = L; }
	if (R <= arrsize && arr[R] > arr[idx]) { idx = R; }
	cout << "prevtop: " << prevtop << " idx: " << idx << endl;
	if (prevtop == idx)return;
	else {
		swap(arr[idx], arr[prevtop]);
		heapify(arr,idx);
	}
}


void buildheap(int arr[], int cursize) {
	for (int i = parent(cursize); i >= 0; i--) {
		heapify(arr, i);
	}
}

int main()
{/*
	insert(5);
	printHeap();
	insert(9);
	printHeap();
	insert(8);
	printHeap();
	insert(7);
	printHeap();
	insert(6);
	printHeap();
	insert(4);
	printHeap();
	insert(10);
	printHeap();

	while (cursize > 0) {
		cout << pop() << endl;
	}*/
	

	return 0;
}