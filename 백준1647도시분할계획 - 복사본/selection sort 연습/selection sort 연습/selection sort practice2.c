#include<stdio.h>
#define SIZE 10

int main(void)
{
	int list[SIZE] = { 3,2,9,7,1,4,8,0,6,5 };
	int i, j, temp, least;
	
	
	for (i = 0; i < SIZE; i++)
	{
		least = i;
		for (j = 1 + i; j <  SIZE; j++)
			if(list[j] < list[least])
			least = j;

		temp = list[i];
		list[i] = list[least];
		list[least] = temp;
	}
	
	for (i = 0; i < SIZE; i++)
		printf("%2d", list[i]);
	printf("\n");
	return 0;
}
