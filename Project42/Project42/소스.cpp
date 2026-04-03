#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int get_max(int i, int k);
int get_integer();
int main(void)
{
	int a, b, max;
	
	a = get_integer();
	b = get_integer();
	max = get_max(a, b);
	printf("두 수 중에 큰 값은 %d입니다.");

	return 0;
}

int get_integer()
{
	int n;
	printf("정수를 입력하시오: ");
	scanf("%d", &n);

	return n;
}

int get_max(int i, int k)
{
	if (i > k)
		return i;
	else
		return k;
}
