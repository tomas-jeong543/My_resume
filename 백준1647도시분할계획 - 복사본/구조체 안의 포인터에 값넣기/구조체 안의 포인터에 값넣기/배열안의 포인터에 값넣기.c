#include<stdio.h>
#include<string.h>

struct student {
	int number;
	char name[20];
	double grade;
	struct date *dob;
};

struct date {
	int year;
	int month;
	int day;
};

int main(void)
{
	struct student s;
	struct date d;

	s.dob = &d;
	s.number = 20070001;
	strcpy(s.name, "ȫ�浿");
	s.grade = 4.3;
	
	

	s.dob->year = 1984;
	s.dob->month = 5;
	
	s.dob->day = 24;
}