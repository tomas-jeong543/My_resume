#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int freq[6] = { 0,0,0,0,0,0 };
	
	srand((unsigned)time(NULL));
	for (int i = 0; i < 100; i++)
	{
		freq[rand() % 6] += 1;
	}

	for (int j = 0; j < 6; j++)
		printf("주사위  면%d가 나온 횟수: %d\n", j, freq[j]);
	return 0;
}