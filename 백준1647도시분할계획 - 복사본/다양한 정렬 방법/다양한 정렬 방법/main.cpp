#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <stack>
#include <time.h>
#include"func.h"
#include<iostream>

void Swap(int* num1, int* num2) {
	int tmp;
	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

//맨 뒤의 값이 가장 큰 값이 저장됨
void Bubble(int arr2[5], int size) {


	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr2[j + 1] < arr2[j]) {
				Swap(&arr2[j + 1], &arr2[j]);
			}
		}

		/*for (int i = 0; i < size; i++) {
			printf("%d \t", arr2[i]);
		}
		printf("\n");*/

	}
}

void selectionSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		//최솟갑 위치 초기화
		int min_idx = i;

		//최솟값 위치 파악
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min_idx]) {
				min_idx = j;
			}
		}

		//값 바꾸기
		int temp = arr[min_idx];
		arr[min_idx] = arr[i];
		arr[i] = temp;
	}
}

//선택 정렬과 유사하지만 최고의 케이스에서는 시간복잡도가 o(n)이다 기존 데이터 정렬되어 있을 때 새로운 데이터가 들어올 때 사용하기 좋은 알고리즘
void Insertion_Sort(int arr[5], int size)
{
	for (int i = 1; i < size; i++) {
		//2번째 요소 선택
		int key = arr[i];
		int j = i - 1;

		// j >= 0 정렬 완료 되었는지 여부 arr[j] > key 변경 필요의 가능성 확인
		while (j >= 0 && arr[j] > key) {
			
			arr[j + 1] = arr[j];
			j -= 1;
		}

		arr[j + 1] = key;
	
		for (int i = 0; i < size; i++) {
			printf("%d \t", arr[i]);
		}

		printf("\n");
	
	}


	return;
}


// Merge Sort 단점은 많은 메모리를 동적 할당해 메모리를 잡아먹는다는 단점이 있다
void merge(int arr[], int left, int mid, int right) {
	
	
	//변수 선언
	int i, j, k;
	//왼쪽 변수 개수
	int n1 = mid - left + 1;
	//오른쪽 변수 개수
	int n2 = right - mid;

	//동적 메모리 할당 및 예외 처리 이게 유일한 단점 메모리를 많이 잡아먹는다는 점
	int* L = (int*)malloc(n1 * sizeof(int));
	int* R = (int*)malloc(n2 * sizeof(int));

	if (L == NULL || R == NULL) {
		printf("Memory allocation failed!\n");
		exit(1);
	}
	//


	//초기화 L은 가운데 기준 왼쪽에 있느  변수 R은 가운데 기준 오른쪽에 있는 변수
	for (i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];


	//일단 개수가 홀수던 짝수던 진행 비교 과정으로 인한 정렬 과정 L과 R둘 중 하나의 끝에 도달할 때까지
	i = 0; j = 0; k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) arr[k++] = L[i++];
		else arr[k++] = R[j++];
	}

	//개수가 홀수개 일때의 대응 남은 값 너어주기
	while (i < n1) arr[k++] = L[i++];
	while (j < n2) arr[k++] = R[j++];


	//메모리 헤제
	free(L);
	free(R);
}


void mergeSort(int arr[], int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		// 왼쪽으로 분할
		mergeSort(arr, left, mid);
		//오른쪽으로 분할
		mergeSort(arr, mid + 1, right);
		//병합
		merge(arr, left, mid, right);
	}
}

//파티션
int partition(int arr[], int low, int high) {
	
	//가장 오른쪽 있는 점으로 피봇 초기화
	int pivot = arr[high];

	//가장 아랫점 - 1
	int i = low - 1;

	//전체적으로 한 번 범위 내 숫자에 대한 순환
	for (int j = low; j < high; j++) {
		if (arr[j] < pivot) {
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	int temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	return i + 1;
}

int partition2(int arr[], int low, int high) {

	//가장 왼쪽에 있는 점으로 피봇 초기화
	int pivot = arr[low];
	//가장 아랫점 - 1으로 초기화
	int i = low;

	//전체적으로 한 번 범위 내 숫자에 대한 순환
	for (int j = low + 1; j <= high; j++) {
		if (arr[j] < pivot) {
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	//피봇을 피봇보다 작은 수 바로 뒤에 나두는 작업이다 
	int temp = arr[i];
	arr[i] = arr[low];
	arr[low] = temp;
	return i;
}

//퀵 정렬 메모리를 덜 먹는다는 장점 덕분에 최악의 경우 시간 복잡도가 m ** 2가 나오는데도 많이 사용되는 정렬 기법
void quickSort(int arr[], int low, int high, int size) {
	if (low < high) {
		//현재 피봇에 적합한 값 위치 지정
		int pi = partition2(arr, low, high);
		for (int i = 0; i < size; i++) {
			printf("%d \t", arr[i]);
		}
		printf("\n");
		printf("\n");
		//기준점 아래 정렬
		quickSort(arr, low, pi - 1, size);
		//기준점 위의 정렬
		quickSort(arr, pi + 1, high,size);
	}
	
	
}
//Radix Sort(with Queue)
void radixSort(int arr[], int n) {
	
	//초기화 하는 과정 자료구조 queue가 필요하다
	std::queue<int> buckets[10];//지금 데이터가 어디 들어가는 지 확인이 필요하다
	int maxVal = arr[0];
	
	//가장 큰 수 값을 획득한다
	for (int i = 1; i < n; i++)
		if (arr[i] > maxVal) maxVal = arr[i];

	//1의 자리수 부터 시작
	int exp = 1;
	//가장 큰 자리수까지 반복
	while (maxVal / exp > 0) { 
		
		//각 자리수의 숫자에 따라 분류하는 과정
		for (int i = 0; i < n; i++) {
			int bucketIdx = (arr[i] / exp) % 10; //현재 value가 어디 버킷에 들어가야 되는지 확인 
			buckets[bucketIdx].push(arr[i]);
		}

		//자릿수대로 정렬하는 과정
		int index = 0;
		for (int i = 0; i < 10; i++) {
			while (!buckets[i].empty()) {
				//작은 순서대로 먼저 넣는다
				arr[index++] = buckets[i].front();
				buckets[i].pop();
			}
		}
		//*10을 반복하는 과정
		exp *= 10;
	}
}







void init(int* arr)
{
	arr[1] = 7, arr[0] = 5, arr[2] = 6, arr[3] = 4, arr[4] = 10;
}

void init2(int* arr)
{
	arr[0] = 10, arr[1] = 4, arr[2] = 5, arr[3] = 6, arr[4] = 7;
}

void init3(int* arr)
{
	arr[0] = 910, arr[1] = 1004, arr[2] = 59, arr[3] = 63, arr[4] = 273;
}

int main()
{
	const int SIZE = 5;
	int* arr = (int*)malloc(sizeof(int) * 5);
	if (arr == nullptr) { return -1; }
	


	// 5,7,6,4,10
	
	init(arr);
	printf("버블 정렬\n");
	Bubble(arr, SIZE);
	
	init(arr);
	printf("선택 정렬\n");
	selectionSort(arr, SIZE);
	
	init(arr);
	printf("삽입 정렬\n");
	Insertion_Sort(arr, SIZE);
	
	init2(arr);
	
	printf("퀵 정렬\n");
	quickSort(arr, 0, SIZE - 1, SIZE);
	for (int i = 0; i < SIZE; i++) {
		printf("%d \t", arr[i]);
	}
	printf("\n");


	string arrstr[] = {"tomas", "amy", "charles", "steve", "daniel", "ann"};
	printf("퀵 정렬 연습\n");
	quick_sort_practice(arrstr, 0, 5);
	for (int i = 0; i < SIZE; i++) {
		cout << arrstr[i] << '\t';
	}


	init3(arr);
	printf("숫자 자릿수 정렬\n");
	Radius_sort_practice(arr, 5);
	for (int i = 0; i < SIZE; i++) {
		printf("%d \t", arr[i]);
	}

	printf("\n");
	free(arr);
	return 0;
}
