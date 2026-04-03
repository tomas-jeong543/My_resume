#include<stdio.h>
#define SIZE 16

int binary_search(int s[SIZE], int n, int key);

int main(void)
{
	int key, i;
	int list[SIZE] = { 2,6,11,13,18,20,22,27,29,30,34,38,41,42,45,47 };

	printf("탐색할 값을 입력하시오.");
	scanf_s("%d", &key);
	printf("탐색결과 = %d", binary_search(list, SIZE,  key));
	
	return 0;
}

int binary_search(int s[SIZE], int n, int key)
{
	int low, high, middle;
	low = 0;
	high = n - 1;
	
	while (low <= high)
	{
		printf("%d ~ %d\n", low, high);
		middle = (low + high) / 2;
		if (key == s[middle])
			return middle;
		else if (key > s[middle])
			low = middle + 1;
		else
			high = middle - 1;

	}
	return -1;
}