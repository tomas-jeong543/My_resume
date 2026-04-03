/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define THRPLUS(X, Y , Z)  ((X) + (Y) + (Z))
#define THRMUL(X, Y , Z)  ((X) * (Y) * (Z))

void RemoveLineBuf(void) {
	while (getchar() != '\n');
}

int main(void) {

	int num[3];

	for (int i = 0; i < 3; i++) {
		printf("정수 입력: ");
		scanf_s("%d", &num[i]);
		RemoveLineBuf();
	}

	printf("세 개의 정수의 합: %d \n", THRPLUS(num[0], num[1], num[2]));
	printf("세 개의 정수의 합: %d \n", THRMUL(num[0], num[1], num[2]));
	
	return 0;
}
*/