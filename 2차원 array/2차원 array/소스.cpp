#include<stdio.h>
#include<stdlib.h>
#define ROWS 3
#define COLS 5

int main(void)
{
	int s[ROWS][COLS] = {
		{87, 98, 80, 76, 3},
		{99, 89, 90, 90, 0},
		{65, 68, 50, 49, 0}
	};
	for (int i = 0; i < ROWS; i++)
	{
		double final_score = s[i][0] * 0.3 + s[i][1] * 0.4 + s[i][2] * 0.2 + s[i][3] * 0.1 - s[i][4] ;
		printf("학생 %d의 최종성적은 %1.2f이다\n",i+1, final_score);
	}

	return 0;
}
