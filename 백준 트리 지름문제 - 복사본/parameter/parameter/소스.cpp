#include<stdio.h>

void inc();

int i;

int main(void)
{
	

	i = 10;
	printf("함수 호출전 i=%d\n", i);
	inc();
	printf("함수 호출후 i=%d\n", i); 

	return 0;
}

void inc(void)
{
	i++;
	printf("in inc(): %d\n", i);
}