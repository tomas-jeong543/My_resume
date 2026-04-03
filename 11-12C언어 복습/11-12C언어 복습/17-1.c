/*#include<stdio.h>

void MaxAndMin(int* arr, int** Max, int** Min);


int main(void) {

	
	int arr[5] = { 1,2,3,4,5 };
	int* maxPtr = &arr[0];
	int* minPtr = &arr[0];
	printf("弥稼蔼 林家:%p  弥瘩癌 林家: %p\n", &arr[0], &arr[4]);
	
	
	MaxAndMin(arr, &maxPtr, &minPtr);

	printf("maxPtr 林家: %p , minPtr林家: %p\n", maxPtr, minPtr);

	return 0;
}

void MaxAndMin(int* arr, int** Max, int** Min) {

	int ** dmax = Max;
	int ** dmin = Min;

	for (int i = 0; i < 5; i++) {
		if (arr[i] > **dmax)
			*dmax = &arr[i];

		if (arr[i] < **dmin)
			*dmin = &arr[i];
	}
}*/                                                       