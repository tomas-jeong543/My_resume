#include<stdio.h>

int main(void)
{
	int i, j;
	double avg;
	int* pi;
	int* pj;
	double* pavg;

	pi = &i;
	pj = &j;
	pavg = &avg;
	
	*pi = 5;
	*pj = 10;
	*pavg = (double)(*pi + *pj) / 2;
	printf("pi: %d pj:%d pavg: %f\n", *pi, *pj, *pavg);
	printf("i: %d j:%d avg: %f\n", i, j, avg);
}