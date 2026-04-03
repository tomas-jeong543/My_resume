#include<stdio.h>

#define YEARS 3
#define PRODUCT 5

int sum(int grade[][PRODUCT]);

int main(void)
{
	int sales[YEARS][PRODUCT] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	int total_sale;

	total_sale = sum(sales);

	printf("총매출은 %d 입니다.", total_sale);

	return 0;
}

int sum(int grade[][PRODUCT])
{
	int x, y;
	int total = 0;
	for(x=0; x<YEARS; x++)
		for (y = 0; y < PRODUCT; y++)
		{
			total += grade[x][y];
		}
	return total;
}
