#include<stdio.h>
#define SIZE 10
int main(void)
{
	int list[SIZE] = { 3, 2, 9, 7, 1, 4, 8, 0, 6, 5 };
	int j, i, k, temp, least;

	
	for (i = 0; i < SIZE - 1; i++)
	{
		for (k = 0; k < SIZE; k++)
			printf("%d ", list[k]);
		printf("\n");

		least = i;
		for (j = i + 1; j < SIZE; j++)
		{
			if (list[j] < list[least])
				least = j;

			temp = list[i];
			list[i] = list[least];
			list[least] = temp;
		}
	}
	for (k = 0; k < SIZE; k++)
		printf("%d ", list[k]);
	printf("\n");

	return 0;
}