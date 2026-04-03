#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#define SIZE 10

int main(void)
{
	int key, i,prime = 0;
	int list[SIZE] = { 1,2,3,4,5,6,7,8,9,7 };

	printf("탐색할 값을 입력하시오:");
	scanf("%d", &key);
	
	for (i = 0; i < SIZE; i++)
	{
		if (list[i] == key)
		{
			printf("인덱스 값: %d\n", i);
			prime = prime + 1;
		}
	}
	if (prime == 0)
		printf("탐색하고 싶은 값이 이 배열에 존재하지 않습니다.");
	else
		printf("총 %d 개의 값을 찾았습니다.\n", prime);

	printf("탐색 종료");
	return 0;
}