#include<stdio.h>
#define SIZE 15
int binsearch(int arr[SIZE], int key, int size);

int main(void)
{
	int key;
	int size = SIZE;
	int arr[SIZE] = { 13,16,19,23,35,43,47,49,52,56,59,61,63,76,81 };
	printf("탐색하려는 값을 입력하시오?");
	scanf_s("%d", &key);
	
	if (binsearch(arr, key, size) == -1)
	{
		printf("탐색하려는 값이 없습니다.");
	}
	else
	{
		printf("탐색하려는 값은 arr[%d]에 있습니다.", binsearch(arr, key, size));
	}
}

int binsearch(int arr[SIZE], int key, int size)
{
	int low, middle, high;
	low = 0;
	high = size;
	
	while (low <= high)
	{
		middle = (low + high) / 2;
		if (arr[middle] == key)
			return middle;
		else if (arr[middle] > key)
		{
			high = middle - 1;
		}
		else if(arr[middle] < key)
		{
			low = middle + 1;
		}

	}
	return -1;
}