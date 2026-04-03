#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
struct student {
	int number;
	char name[20];
	double grade;
};
struct student create()
{
	struct student s;
	s.number = 3;
	strcpy(s.name, "park");
	s.grade = 4.0;
	return s;
}
int main(void)
{
	struct student s;
	s = create();
	printf("%2d %2s %2f", s.number, s.name, s.grade);

	return 0;
}