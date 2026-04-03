#include<stdio.h>

int main(void)
{
	int i;
	int scores[5];

	for (i = 0; i < 5; i++)
	{
		scores[i] = (i+1) * 10;
		printf("scaores[%d] = %d\n", i, scores[i]);
	}
}