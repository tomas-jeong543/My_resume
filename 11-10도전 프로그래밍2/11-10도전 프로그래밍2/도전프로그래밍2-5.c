#include<stdio.h>

void BubbleSort(int ary[], int len);

int main(void) {

	int arr[7] = {0,0,0,0,0,0,0};
	int len = 7;
	
	for (int i = 0; i < len; i++) {
		printf("ют╥б: ");
		scanf_s("%d", &arr[i]);
	}

	BubbleSort(arr, len);

	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}

void BubbleSort(int ary[], int len) {

	int i, j;
	int temp;

	for (int i = 0; i < len - 1; i++) {

		for (j = 0; j < (len - i) - 1; j++) {
			if (ary[j] < ary[ j + 1 ]) {
				temp = ary[j];
				ary[j] = ary[j + 1];
				ary[j + 1] = temp;
			}
		}
	}
}