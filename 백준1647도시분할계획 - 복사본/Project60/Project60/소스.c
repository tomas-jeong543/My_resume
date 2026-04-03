#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>



int main(void)
{
	char s[]= "A100";
	char str[10];
	char ch;
	int value;

	sscanf(s, "%c%d", &ch, &value);
	sprintf(str, "%c%d", ch, value);
	printf("ch: %c, value %d\n", ch, value);
	printf(str);
	return 0;
}	