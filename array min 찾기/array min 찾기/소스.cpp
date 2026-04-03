#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10

int main(void)
{
	srand(time(NULL));
	int prices[SIZE];
	int i, minimum;
	int index;
	printf("--------------------\n");
	printf("0 1 2 3 4 5 6 7 8 9 \n");
	printf("--------------------\n");
	for (i = 0; i < SIZE; i++)
	{
		prices[i] = (rand() % 100) + 1;
		printf("%-3d", prices[i]);
	}

	printf("\n\n");
	index = 0;
	minimum = prices[0];
	for (i = 1; i < SIZE; i++)
	{
		if (prices[i] < minimum)
		{
			minimum = prices[i];
			index = i;
		}
	}
	printf("최솟값은 %d element인 %d 이다.", index, minimum);

	return 0;
}
