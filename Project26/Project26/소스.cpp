#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main(void)
{
	int n;
	int l = 1;
	int sum = 0;
	printf("정수를 입력하시오: ");
	scanf("%d", &n);

	while (l <= n)
	{
		if (l % 2 == 0)
		{
			sum += l;
			l++;
		}
		else
		{
			l++;
		}

	}

	printf("1부터 10까지의 짝수의 합은 %d이다.",sum);
	
	return 0;
}