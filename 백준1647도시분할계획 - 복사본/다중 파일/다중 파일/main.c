#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "power.h"
int my = 10;

int main(void)
{
	int x, y;

	printf("X의 값을 입력하시오: ");
	scanf("%d", &x);
	printf("Y의 값을 입력하시오: ");
	scanf("%d", &y);
	printf("%d 의 %d승 값은 %f\n", x, y, power(x, y));
	printf("main-my %d", my);
	return 0;
}