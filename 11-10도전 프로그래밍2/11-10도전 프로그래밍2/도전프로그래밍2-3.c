/*#include<stdio.h>

void FillArry(int arry[], int len, int arrychange[]);

int main(void) {

	int arr[10];
	int arrchange[10];
	printf("총 10개의 숫자 입력");
	printf("\n");

	for (int i = 0; i < 10; i++) {		
		printf("입력: ");
		scanf_s("%d", &arr[i]);
	}


	FillArry(arr, 10, arrchange);

	for (int i = 0; i < 10; i++) {
		arr[i] = arrchange[i];
	}

	printf("배열 요소의 출력:");
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}


	return 0;
}

void FillArry(int arry[], int len, int arrychange[]) {

	int count = 0;
	int lenreplica = len;
	for (int i = 0; i < len; i++) {
		if (arry[i] % 2 == 0)
			arrychange[--lenreplica] = arry[i];
		else
			arrychange[count++] = arry[i];
	}



}*/