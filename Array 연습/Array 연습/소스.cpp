#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main(void)
{
	int score[100];
	int  num = 0, i,sum = 0;
	double average;
	
	for (i = 0; i < 100; i++)
	{
		printf("학생들의 성적을 입력하시오(최대 100명,음수입력시 종료):");
		scanf("%d", &score[i]);
		
		if (score[i] < 0)
			break;
		num++;
	}
	for (i = 0; i < num; i++)
	{
		sum += score[i];
	}
	average = (double)sum / num;

	printf("%d 명의 학생의 평균 성적은 %lf 이다. ", num, average);
	return 0;
}