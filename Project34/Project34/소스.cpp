#include<stdio.h>

int main(void)
{
	int i;
	for (i = 0; i < 5; i++)
	{
		int temp = 1;//블록 생성시 초기화
		printf("temp = %d\n", temp);
		temp++;
	}

	return 0;
}