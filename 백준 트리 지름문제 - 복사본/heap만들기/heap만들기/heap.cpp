#define Capcity 9
#include<iostream>
#include<cmath>
using namespace std;

int heap[Capcity]{ 3, 8, 10, 7, 6, 9, 2 };
int sizeinfo;

void init() {
	sizeinfo = 0;
}

void swap(int* x, int* y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void rebalancce(int root) {

	if (root * 2 + 1 < sizeinfo) {
		rebalancce(root * 2 + 1);

	}

	if (root * 2 + 2 < sizeinfo) {
		rebalancce(root * 2 + 2);
	}

	int maxchild;
	if (root * 2 + 1 < sizeinfo ) {
		maxchild = heap[root * 2 + 1];
	}
	else {
		return;
	}

	if (root * 2 + 2 < sizeinfo && maxchild < heap[root * 2 + 2]) {
		maxchild = heap[root * 2 + 2];
		if (maxchild > heap[root]) {
			swap(&heap[root], &heap[root * 2 + 2]);
			rebalancce(root * 2 + 2);
		}
	}
	else {
		if (maxchild > heap[root]) {
			swap(&heap[root], &heap[root * 2 + 1]);
			rebalancce(root * 2 + 1);
		}
	}
}



void heappush(int x)
{
	if (sizeinfo < Capcity) {
		heap[sizeinfo++] = x;
		rebalancce(0);
	}
	else {
		cout << "heap is already full" << endl;
	}

}

int maxheappop()
{
	int max = heap[0];
	if (sizeinfo >= 1) {
		heap[0] = heap[sizeinfo - 1];
		sizeinfo -= 1;
		rebalancce(0);
		return max;
	}
	else {
		cout << "heap is empty" << endl;
		exit(0);
	}
}

int main()
{
	init();
	/*heappush(3);
	heappush(1);
	heappush(2);
	heappush(15);
	heappush(10);
	heappush(12);
	heappush(11);
	for (int i = 0; i < sizeinfo; i++) {
		cout << heap[i] << "\t";
	}
	*/
	sizeinfo = 7;
	rebalancce(0);
	for (int i = 0; i < sizeinfo; i++) {
		cout << heap[i] << "\t";
	}
	return 0;
}