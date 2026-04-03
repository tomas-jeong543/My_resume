/*#include<stdio.h>

void PrintOddNum(int *num, int len);
void PrintEvenNum(int *num, int len);

int main(void) {

	int arr[10];

	for (int i = 0; i < 10; i++) {
		printf("ÀÔ·Â: ");
		scanf_s("%d", &arr[i]);
	}

	PrintOddNum(&arr, sizeof(arr) / sizeof(int));
	PrintEvenNum(&arr, sizeof(arr) / sizeof(int));
	return 0;
}

void PrintOddNum(int *num, int len ) {
	
	printf("È¦¼ö Ãâ·Â: ");
	for (int i = 0; i < len; i++) {
		if (num[i] % 2 != 0)
			printf("%d, ", num[i]);
	}

	printf("\n");
}

void PrintEvenNum(int* num, int len) {
	printf("Â¦¼ö Ãâ·Â: ");
	for (int i = 0; i < len; i++) {
		if (num[i] % 2 == 0)
			printf("%d, ", num[i]);
	}

	printf("\n");
}
*/