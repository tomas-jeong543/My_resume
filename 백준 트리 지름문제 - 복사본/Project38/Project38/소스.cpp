#include<stdio.h>
#define NUM_EXAM 3
#define NUM_STUDENT 5


int find_min(int score[NUM_EXAM][NUM_STUDENT], int exam);
int find_max(int score[NUM_EXAM][NUM_STUDENT], int exam);
double comp_avg(int score[NUM_EXAM][NUM_STUDENT], int exam);

int main(void)
{
	
	int student_test_score[3][5] = {
		{ 60,80,43,78,93 },
		{ 75,59,81,77,81 },
		{ 83,74,97,73,81}
	};
	int min, max, n;
	double avg;
	for (int i = 0; i < NUM_EXAM; i++)
	{
		printf("시험 %d", i);
		for (int j = 0; j < NUM_STUDENT; j++)
		{
			printf("%2d", student_test_score[i][j]);
		}
	}
	printf("어떤 시험인지 숫자를 입력하시오.(0,1,2중 하나 택)");
	scanf_s("%d", &n );
	min = find_min(student_test_score, n);
	max = find_max(student_test_score, n);
	avg = comp_avg(student_test_score, n);
}