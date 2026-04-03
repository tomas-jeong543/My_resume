#include<stdio.h>

int main(void)
{
	int a[5] = {1, 2, 3, 4, 5};
	int b[5] = {1, 2, 3, 4, 5};
	int i,j = 0;
	for (i = 0; i < 5; i++)
	{
		if (a[i] != b[i])
		{
			printf("a[]와 b[]는 같지 않습니다.");
			return 0;

		}
	}
	printf("a[]와 b[]는 같습니다.");
	
	return 0;
	
}