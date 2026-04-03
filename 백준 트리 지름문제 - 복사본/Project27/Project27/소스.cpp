#include<stdio.h>

int main(void)
{
	int x, y, r;
	printf("두 개의 정수를 입력하십시오(큰 수,작은 수):");
	scanf("%d", &x, &y);

	do
	{
		r = x % y;
	}while(y!=0)

}