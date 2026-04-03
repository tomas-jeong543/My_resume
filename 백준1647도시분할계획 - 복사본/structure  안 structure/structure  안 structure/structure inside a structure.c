#include<stdio.h>
#include<string.h>

struct date {
	int year;
	int month;
	int date;
};

struct student {
	int number;
	char name[10];
	struct date dob;
	double grade;

};

int main(void)
{
	struct student s1;
	s1.dob.year = 1984;
	s1.dob.month = 12;
	s1.dob.date = 30;
	printf("s1.dob.year = %d\n", s1.dob.year);
	printf("s1.dob.month = %d\n", s1.dob.month);
	printf("s1.dob.date = %d\n", s1.dob.date);
	return 0;
}
