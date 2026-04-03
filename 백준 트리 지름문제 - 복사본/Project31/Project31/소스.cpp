#include<stdio.h>

#define RATE         0.034    //이율
#define INVESTMENT   10000000//초기 투자금
#define YEARS       100		 //투자 기간

int main(void)
{
	int i;
	double total = INVESTMENT;

	printf("============\n");
	printf("연도 원리금\n");
	printf("============\n");

	for (i = 1; i <= YEARS; i++)
	{
		total = total * (1 + RATE);
		printf("%4d       %.1f\n", i, total);

	}

	return 0;
}