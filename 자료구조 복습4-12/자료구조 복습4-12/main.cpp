#include<stdio.h>

typedef struct {
	double name[20];
	int age;
	float grade;
	char gender;
}Student;


int main()
{
	double name[20];
	int age;
	float grade;
	char gender;
	Student a;
	printf("%u\n", sizeof(a));
	printf("%u\n", sizeof(name));
	printf("%u\n", sizeof(age));
	printf("%u\n", sizeof(grade));
	printf("%u\n", sizeof(gender));
	return 0;
}