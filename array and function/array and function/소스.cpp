#include<stdio.h>
#define STUDENT  5

int get_average(int scores[], int n);
int main(void)
{
	int scores[STUDENT] = { 1, 2, 3, 4, 6 };
	float avg;

	avg =(double) get_average(scores, STUDENT);

	printf("ЦђБе: %f", avg);
}

int get_average(int scores[], double n)
{
	int i;
	double sum = 0;

	for (i = 0; i < n; i++)
			sum += scores[i];
	return  sum / n;
}