#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#define SIZE 3
struct student {
	int number;
	char name[20];
	double grade;
};

int main(void)
{
	struct student list[SIZE];
	int i;

	for (i = 0; i < SIZE; i++)
	{
		printf("학번을 입력하시오(정수): ");
		scanf("%d", &list[i].number);
		printf("이름: ");
		scanf("%s", list[i].name);
		printf("학점): ");
		scanf("%lf", &list[i].grade);
	}
	for (i = 0; i < SIZE; i++)
		printf("%d %s %f\n", list[i].number, list[i].name, list[i].grade);
	return 0;
}