#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10

int get_max(int prices[SIZE]);
int get_min(int prices[SIZE]);

int main(void)
{
	int prices[SIZE];
	int i, max, minimum;
	printf("------------------------------\n");
	printf("0  1  2  3  4  5  6  7  8  9\n");
	printf("------------------------------\n");
	srand((unsigned)time(NULL));
	for (i = 0; i < SIZE; i++)
	{
		prices[i] = (rand() % 100) + 1;
		printf("%d ", prices[i]);

	}
	printf("\n\n");

	max = get_max(prices);
	minimum = get_min( prices);
	printf("가격의 최대값은 %d입니다.\n", max);
	printf("가격의 최솟값은 %d입니다.\n", minimum);
	return 0;
}

int get_max(int prices[SIZE])
{
	int max,i;
	max = prices[0];

	for (i = 1; i < SIZE; i++)
	{
		if (prices[i] > max)
			max = prices[i];
	}
	return max;
}

int get_min(int prices[SIZE])
{
	int min, i;
	min = prices[0];

	for (i = 1; i < SIZE; i++)
	{
		if (prices[i] < min)
			min = prices[i];
	}
	return min;
}