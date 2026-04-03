#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int get_integer();
int add(int a, int b);

int main(void)
{
	int i, n, sum = 0;
	i = get_integer();
	n = get_integer();
	sum = add(i, n);
	printf("두 수의 합은 %d 입니다.", sum);
	return 0;
}

int get_integer()
{
	int j;
	printf("정수를 입력하시오: ");
	scanf("%d", &j);
	return j;
}

int add(int a, int b)
{
	return (a + b);
}

