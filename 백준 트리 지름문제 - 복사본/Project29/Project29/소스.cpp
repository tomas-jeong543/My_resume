#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main(void)
{
	int x, y, r;

	printf("두개의 정수를 입력하십시오(큰 수,작은 수):");
	scanf("%d %d", &x, &y);

	do
	{
		r = x % y;
		x = y;
		y = r;

	} while (y != 0);

		printf("최대 공약수는 %d입니다.", x);

	return 0;
}