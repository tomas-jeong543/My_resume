#define _CRT_SECURE_NO_WARNINGS	

#include<stdio.h>

int factorial(int);

int factorial(int n)
{
	if (n <= 1)
		return(1);
	else
		return(n * factorial(n - 1));
}
int main(void)
{
	int n,i;

	printf("정수를 입력하시오:");
	scanf("%d", &n);
	i = factorial(n);

	printf("%d ! = %d", n, i);

	return 0;

}