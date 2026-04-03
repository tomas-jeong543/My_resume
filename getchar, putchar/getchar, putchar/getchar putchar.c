#include<stdio.h>

int main(void)
{
	char name[100];
	char adress[100];
	printf("이름을 입력하시오.");
	gets_s(name, 100);
	printf("사는 곳을 입력하시오.");
	gets_s(adress, 100);
	puts(name, 100);
	puts(adress, 100);
	return 0;
}