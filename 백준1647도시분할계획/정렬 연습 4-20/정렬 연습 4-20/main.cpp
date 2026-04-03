#include<stdio.h>
#include<stdlib.h>
#include<queue>


void Printarr(int arr[], int size)
{
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void InsertionSort(int arr[], int size)
{
	for (int i = 1; i < size; i++) {
		int j = i - 1;
		int num = arr[i];
		while (j >= 0 && arr[j] > num) {
			arr[j + 1] = arr[j];
			j -= 1;
		}
		arr[j + 1] = num;
	}
}

int Partition(int arr[], int left, int right)
{
	int pivot = arr[left];

	int i = right + 1;

	for (int j = right; j > left; j--) {
		if (arr[j] > pivot) {
			i -= 1;
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}

	int tmp = arr[i - 1];
	arr[i - 1] = arr[left];
	arr[left] = tmp;
	return i - 1;
}

void QuickSort(int arr[], int left, int right)
{
	if (left < right) {
		int pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}

void selction_Sort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++) {
		int minidx = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[minidx] > arr[j]) {
				minidx = j;
			}
		}

		int tmp = arr[minidx];
		arr[minidx] = arr[i];
		arr[i] = tmp;
	}
}

void Radius_Sort(int arr[], int size)
{
	std::queue<int> bucket[10];

	int max = arr[0];

	for (int i = 1; i < size; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}

	int ex = 1;
	while (max / ex > 0) {
		for (int i = 0; i < size; i++) {
			int num = (arr[i] / ex) % 10;
			bucket[num].push(arr[i]);
		}

		int idx = 0;
		for (int i = 0; i < 10; i++) {
			while (!bucket[i].empty()) {
				//printf("%d %d %d\n", arr[idx], idx, bucket[i].front());
				arr[idx++] = bucket[i].front();
				
				bucket[i].pop();
			}
		}
		ex *= 10;
		//Printarr(arr, size);
	}
}

void Bubble_sort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

void MergePartiton(int arr[], int left, int middle, int right)
{
	int lsize = middle - left + 1;
	int rsize = right - middle;

	int* L = (int*)malloc(sizeof(int) * lsize);
	int* R = (int*)malloc(sizeof(int) * rsize);

	if (L == nullptr || R == nullptr) {
		printf("dynamic memory allocation failed\n");
		return;
	}

	for (int i = 0; i < lsize; i++) { L[i] = arr[i + left]; }
	for (int i = 0; i < rsize; i++) { R[i] = arr[i + middle + 1]; }

	int i = 0, j = 0, k = left;

	while (i < lsize && j < rsize) {
		if (L[i] < R[j]) { arr[k++] = L[i++]; }
		else { arr[k++] = R[j++]; }
	}

	while (i < lsize) { arr[k++] = L[i++]; }
	while (j < rsize) { arr[k++] = R[j++]; }
}

void mergeSort(int arr[], int left, int right)
{
	if (left < right) {
		int middle = left + (right - left) / 2;
		mergeSort(arr, left, middle);
		mergeSort(arr, middle + 1, right);
		MergePartiton(arr, left, middle, right);
		for (int i = 0; i < 7; i++) {
			printf("%d ", arr[i]);
		
		}
		printf("\n");
	}
}



int main()
{
	const int SIZE = 7;
	int arr[SIZE] = { 1,23,543,43,65,25,57 };
	Printarr(arr, SIZE);
	mergeSort(arr,0,SIZE - 1 );
	Printarr(arr, SIZE);
	return 0;
}