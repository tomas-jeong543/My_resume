#include<stdio.h>

#define YEARS 3
#define PRODUCTS 3

int sum(int b[YEARS][PRODUCTS]);

int main(void)
{
	int sales[YEARS][PRODUCTS] = {
		{ 1,2,3 },
		{ 4,5,6 },
		{ 7,8,9 }
	};

	int total_sales = sum(sales);

	printf("총매출은 %d 입니다.\n", total_sales);

} 

int sum(int b[YEARS][PRODUCTS])
{
	int total = 0;
	for (int i = 0; i < YEARS; i++)
		for (int j = 0; j < YEARS; j++)
			total = total + b[i][j];
	return total;
}
