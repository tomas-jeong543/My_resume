#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

struct student {
	int number;
	char name[20];
	double grade;
};

int main(void)
{
	struct student list[100];
	list[2].number = 202211364;
	strcpy(list[2].name, "ȫ�浿");
	list[2].grade = 4.1;

	printf("%2d %2s %2f", list[2].number, list[2].name, list[2].grade);
	return 0;
}