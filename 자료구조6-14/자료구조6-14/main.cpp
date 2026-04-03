#define MAX_SIZE 100
#include<iostream>
#include<time.h>

using namespace std;

int heap[MAX_SIZE];
int heapsize = 0;

int parent(int x) {
	return x / 2;
}

int left(int x) {
	return 2 * x;
}

int right(int x) {
	return 2 * x + 1;
}

void swap(int& x, int& y) {
	int tmp = x;
	x = y;
	y = tmp;
}

void insert(int x) {

	if (heapsize == MAX_SIZE - 1) {
		cout << "가득 참" << endl;
		return;
	}
	heap[++heapsize] = x;
	int i = heapsize;

	while (i > 1) {
		if (heap[parent(i)] < heap[i]) {
			swap(heap[parent(i)], heap[i]);
			i = parent(i);
		}
		else {
			return;
		}
	}
	
}

int pop() {
	if (heapsize == 0)return -1;

	int max = heap[1];
	heap[1] = heap[heapsize--];

	int largest = 1;

	while (true) {

		int prev = largest;
		int l = left(largest);
		int r = right(largest);

		if (l <= heapsize && heap[largest] < heap[l]) largest = l;
		if (r <= heapsize && heap[largest] < heap[r]) largest = r;

		if (largest == prev) {
			return max;
		}
		else {
			swap(heap[largest], heap[prev]);
		}
	
	}
}

void heapify(int x) {

	int largest = x;
	int prev = x;
	int l = left(x);
	int r = right(x);

	if (l < heapsize && heap[largest] <= heap[l]) largest = l;
	if (r < heapsize && heap[largest] <= heap[r]) largest = r;

	if (largest != prev) {
		heapify(largest);
	}

}

void makeHeap() {
	for (int i = parent(heapsize); i >= 1; i--) {
		heapify(i);
	}
}

int interpolation_search(int arr[], int n, int key) {
	int low = 0, high = n - 1;
	while (low <= high && key >= arr[low] && key <= arr[high]) {
		int pos = low + (double)(high - low) * (key - arr[low]) / (arr[high] - arr[low]);

		if (arr[pos] == key) {
			return pos;
		}
		else if (arr[pos] > key) {
			high = pos - 1;
		}
		else {
			low = pos + 1;
		}
	}
	return -1;
}

int expo_search(int arr[], int n, int key) {
	
	if (arr[0] == key)return 0;
	int i = 1;

	while (arr[(i < n ? i : n) - 1] < key && i < n) {
		i *= 2;
	}

	int left = i / 2;
	int right = (i > n ? n : i);

}

int bineary_search(int arr[], int left, int right, int key) {

	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == key) {
			return key;
		}
		else if (arr[mid] > key) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return -1;
}

int teranary_search(int arr[], int size) {
	int left = 0, right = size - 1;
	while (right - left > 2) {
		int mid1 = left + (right - left) / 3;
		int mid2 = right - (right - left) / 3;
		if (arr[mid1] < arr[mid2]) { left = mid1 + 1; }
		else { right = mid2 - 1; }
	}
}

int main() {
	srand(static_cast<unsigned int>(time(NULL)));

	//for (int i = 0; i < 10; i++) {
	//	insert(rand() % 100);
	//}

	//for (int i = 0; i < 10; i++) {
	//	cout << heap[i] << " ";
	//}
	//cout << endl;
	//for (int i = 0; i < 10; i++) {
	//	cout << pop() << endl;
	//}
	int arr[10];

	for (int i = 0; i < 10; i++) {
		arr[i] = i + 1;
	}


	for (int i = 0; i < 10; i++) {
		int idx = rand() % 20;
		cout << idx << ":" << interpolation_search(arr, 10, idx) << endl;
	
}