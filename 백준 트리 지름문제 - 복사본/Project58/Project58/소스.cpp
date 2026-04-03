#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>


int main(void)
{
	char str[30];
	strcpy(str, "C language is easy");

	int i = 0;

	while (str[i] != 0)
		i++;
	printf("%s 문자열의 길이는 %d 이다.", str, i);
	
	printf("\n");
	i = 0;
	strcpy(str, "C language is not easy");
	
	while (str[i] != 0)
		i++;
	printf("%s 문자열의 길이는 %d 이다.", str, i);
	return 0;
}