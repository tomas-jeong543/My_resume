#include<stdio.h>

int main(void)
{
	int m[3][3] = { 10,20,30,40,50,60,70,80,90 };
	int i;
	printf("m = %p\n", m);
	for(i = 0; i < 3; i++)
		printf("m[%d] = %p\n", i, m[i]);
	for (i = 0; i < 3; i++)
		printf("&m[%d][0] = %p\n", i, &m[i][0]);
	return 0;
}