#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int get_integer();
int factorial(int);
int combination(int, int);

int main(void)
{
	int n, r,ans;
	n = get_integer();
	r = get_integer();
	ans = combination(n, r);
	printf("%d C %d = %d", n, r, ans);
	return 0;
}


int get_integer(void)
{
	int n;
	printf("정수를 입력하시오:");
	scanf("%d", &n);
	return n;
}

int factorial(int num)
{
	int n = 1;
	int k = 1;
	for (n = 1; n <= num; n++)
	{
		k *= n;
	}
	
	return k;
}

int combination(int n, int r)
{
	int a, b, c;

	a = factorial(n);
	b = factorial(n - r);
	c = factorial(r);

	return a / (b * c);

}