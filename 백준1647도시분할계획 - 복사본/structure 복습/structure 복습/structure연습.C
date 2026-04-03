#include<stdio.h>
#include<string.h>

struct student {
	int number;
	char name[10];
	double grade; 
};

int main(void)
{
	struct student s1 = { 24,"kim",4.3 };
	printf("number,name,grade = %d %s %f", s1.number, s1.name, s1.grade);
	return 0;
}