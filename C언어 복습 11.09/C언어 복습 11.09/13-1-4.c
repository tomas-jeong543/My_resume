/*#include<stdio.h>

int main(void) {

	int arr[6] = { 1,2,3,4,5,6 };
	int* ptrSt = arr;
	int* ptrEnd = &arr[5];
	int temp = 0;

	printf("기존 arr값: ");
	for (int i = 0; i < 6; i++)
		printf("%d ", arr[i]);

	printf("\n");

		for (int i = 0; i < 3; i++) {

			temp = *ptrSt;
			*ptrSt = *ptrEnd;
			*ptrEnd = temp;

			ptrSt++, ptrEnd--;
	}

		printf("변화된 arr값: ");
		for (int i = 0; i < 6; i++)
			printf("%d ", arr[i]);

	return 0;

}*/