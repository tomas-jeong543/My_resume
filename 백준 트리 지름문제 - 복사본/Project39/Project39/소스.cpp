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
	printf("            학생0      힉생1    학생2   학생3      학생4\n");
	for (int i = 0; i < NUM_EXAM; i++)
	{
		printf("시험 %d", i);
		for (int j = 0; j < NUM_STUDENT; j++)
		{
			printf("%10d", student_test_score[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("어떤 시험인지 숫자를 입력하시오.(0,1,2중 하나 택)");
	scanf_s("%d", &n);
	min = find_min(student_test_score, n);
	max = find_max(student_test_score, n);
	avg = comp_avg(student_test_score, n);

	printf("exam %d의 최저점수, 최고점수, 평균은 각각 %d점 %d점 %f점이다", n, min, max, avg);

	return 0;
}

int find_min(int score[NUM_EXAM][NUM_STUDENT], int exam)
{
	int i,min;
	min = score[exam][0];
		for (i = 1; i < NUM_STUDENT; i++)
		{
			if (score[exam][i] < min)
				min = score[exam][i];
		}
		return min;
}
int find_max(int score[NUM_EXAM][NUM_STUDENT], int exam)
{
	int i, max;
	max = score[exam][0];
	for (i = 1; i < NUM_STUDENT; i++)
	{
		if (score[exam][i] > max)
			max = score[exam][i];
	}
	return max;
}
double comp_avg(int score[NUM_EXAM][NUM_STUDENT], int exam)
{
	int i, sum;
	double avg;
	sum = 0;
	for (i = 0; i < NUM_STUDENT; i++)
	{
		sum = sum + score[exam][i];
	}
	avg = (double)sum / NUM_STUDENT;

	return avg;
}