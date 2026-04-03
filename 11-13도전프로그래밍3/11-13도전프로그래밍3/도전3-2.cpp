#include<stdio.h>

int main(void) {

	int size;


	printf("배열의 크기를 입력:");
	scanf_s("%d", &size);
	
	int* arr = malloc(size * sizeof(int));

	int arr[size][size];

	return 0;
}