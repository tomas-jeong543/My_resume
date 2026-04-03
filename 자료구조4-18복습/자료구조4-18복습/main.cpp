#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<queue>


int* init()
{
	const int SIZE = 7;
	srand(static_cast<unsigned int>(time(NULL)));
	int* arr = (int*)malloc(sizeof(int) * SIZE);
	if (arr == nullptr)
	{
		printf("동적 메모리 할당 오류");
		return nullptr;
	}

	for (int i = 0; i < SIZE; i++) {
		int mul = rand() % 100;

		arr[i] = (i + 1) * mul;
	}

	for (int i = 0; i < SIZE / 2; i++)
	{
		int tmp = arr[i];


		int num = rand() % SIZE;

		arr[i] = arr[num];
		arr[num] = tmp;
	}


	return arr;
}

//버블 정복 완료
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

//완
void Selection_sort(int arr[], int size)
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

void printarr(int arr[], int size)
{
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}


//다시 복습 필요 바교 대상은 키이고 while문 안의 순서는 생각보다 중요하다
void Insertion_sort(int arr[], int size)
{
	for (int i = 1; i < size; i++) {
		int j = i - 1;
		int key = arr[i];

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j -= 1;
		}
		arr[j + 1] = key;
	}
}

//병합 정렬은 이제 어느 정도 머리에 들어와서 활용할 수 있는 수준까지 도달했다
void Partiton(int arr[], int left,int middle, int right)
{
	int lsize = middle - left + 1;
	int rsize = right - middle;

	int* L = (int*)malloc(sizeof(int) * lsize);
	int* R = (int*)malloc(sizeof(int) * rsize);
	if (L == nullptr || R == nullptr)
	{
		printf("동적 메모리 할당 오류\n");
		return;
	}

	for (int i = 0; i < lsize; i++) { L[i] = arr[left + i]; }
	for (int i = 0; i < rsize; i++) { R[i] = arr[middle + i + 1]; }

	int i = 0, j = 0, k = left;

	while (i < lsize && j < rsize) {
		if (L[i] < R[j]) { arr[k++] = L[i++]; }
		else { arr[k++] = R[j++]; }
	}

	while (i < lsize) { arr[k++] = L[i++]; }
	while (j < rsize) { arr[k++] = R[j++]; }

	free(R);
	free(L);
}

void Merge(int arr[], int left, int right)
{
	if (left < right) {
		int middle = left + (right - left) / 2;
		Merge(arr, left, middle);
		Merge(arr, middle + 1, right);
		Partiton(arr, left, middle, right);
	}
}

//완료 그냥 어느 정도 이해함
void Radix_sort(int arr[] , int size)
{
	std::queue<int> bucket[10];
	int max = arr[0];

	printf("inside_func\n");

	for (int i = 1; i < size; i++) {
		if (arr[i] > max)
			max = arr[i];
	}
	
	int ex = 1;

	while (max / ex > 0) {

		for (int i = 0; i < size; i++) {
			int check = (arr[i] / ex) % 10;
			bucket[check].push(arr[i]);
		}

		int idx = 0;
		for (int i = 0; i < 10; i++) {
			while (!bucket[i].empty()) {
				arr[idx++] = bucket[i].front();
				bucket[i].pop();
			}
		}


		ex *= 10;
		printarr(arr, size);
		printf("\n");
	}
	printf("inside_func\n");
}


int Quick_partition(int arr[], int low, int high) {
	printf("%d %d\n", low, high);
	int pivot = arr[low];
	int i = high + 1;

	for (int j = high; j > low; j--) {
		if (arr[j] > pivot) {
			i--;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	int temp = arr[i - 1];
	arr[i - 1] = pivot;
	arr[low] = temp;
	return i - 1;
}


void Quick_sort(int arr[], int left, int right)
{
	if (left < right) {
		int pivot = Quick_partition(arr, left, right);
		printf("pivot: %d\n", pivot);
		for (int i = 0; i < 7; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		Quick_sort(arr, left, pivot -1 );
		Quick_sort(arr, pivot + 1, right);
	}
}


int main()
{
	const int SIZE = 7;
	int* arr = init();
	if (arr != nullptr) {
		printarr(arr, SIZE);
		Quick_sort(arr,0,SIZE - 1 );
		printf("after\n");
		printarr(arr, SIZE);
	}
	return 0;
}