#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main(void)
{
	int a, b, c;//단 c는 빗변이다.
	int sum=0;

	for (c = 1; c <= 100; c++)
	{
		for (b = 1; b <= 100; b++)
		{
			for (a = 1; a <= 100; a++)
			{
				if (c * c == a * a + b * b)
				{
					sum++;
					printf("직각삼각형: %d %d %d\n", a, b, c);
					break;
				}
			}
		}
	}
	printf("총 %d개입니다.", sum);

	return 0;
}