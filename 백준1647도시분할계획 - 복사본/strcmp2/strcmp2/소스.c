#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>


char s[100] = "MAn is imortal, Because he has a seoul";
char seps[] = ",\n\t";
char* token;
	
int main(void)
{
	token = stroke(s, seps);
	while (token != 0)
	{
		printf("ÅäÅ«:%s ", token);
		token = stroke(NULL, seps);
	}
	return 0;
}