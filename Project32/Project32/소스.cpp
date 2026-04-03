#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(void)
{
	int x,y,answer,i,j;
	
	j = 0;
	
	srand(time (NULL));
	
	for (i = 0; i < 10; i++)
	{
		x = rand() % 10;
		y = rand() % 10;
		


		printf("%d + %d =", x, y);
		scanf("%d", &answer);
		if (x + y == answer)
		{
			printf("맞았습니다.\n");
			j++;
		}
		else
			printf("틀렸슴니다.\n");
	}
		printf("\n총 %d 문제를 맞추었습니다.\n", j);

		return 0;
}