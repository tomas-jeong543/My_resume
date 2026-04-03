#include<stdio.h>
struct student get_max_stu(struct student list[3],int size);
struct student {
	int number;
	char name[20];
	double grade;
};

int main(void)
{
	int i, size = 3;
	struct student list[3] = {
		{ 20180001,"홍길동",3.1 },
		{ 20180002,"김철수",3.2 },
		{ 20180001,"이영희",3.9 }
	};
	struct student super_stu;

	super_stu = get_max_stu(list, size);


	
	printf("평점이 가장 높은 학생의 이름은 %s 학번은 %d 학점은 %f 입니다.", super_stu.name, super_stu.number, super_stu.grade);
	return 0;
}

struct student get_max_stu(struct student list[3], int size)
{
	struct student max_stu;
	max_stu = list[0];

	for (int i = 1; i < size; i++)
	{
		if (list[i].grade > max_stu.grade)
			max_stu = list[i];
	}
	return max_stu;
}