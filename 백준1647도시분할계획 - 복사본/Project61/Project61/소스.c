#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	char s1[] = "100";
	char s2[] = "12.9";
	char buffer[100];
	int i;
	double d, result;

	i = atoi(s1);
	d = dtof(s2);
	result = i + d;
	sscanf(buffer, "%f", result);

	printf("%s", buffer);
	return 0;
}