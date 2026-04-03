#include<stdio.h>
#define SIZE 5
void calculate(double* e, double* m, double* e100, double* m100, double* av, int size);

int main(void)
{
	double eng[SIZE] = { 4.1,3.0,2.8,4.2,3.5 };
	double math[SIZE] = { 3.1,3.5, 3.3, 2.2,2.7 };
	double eng100[SIZE];
	double math100[SIZE];
	double avg[SIZE];

	 calculate(eng, math, eng100, math100, avg,SIZE);
	 for (int j = 0; j < SIZE; j++)
	 {
		 printf("%2f ", *(eng100 + j));
	 }
	 printf("\n");
	 for (int j = 0; j < SIZE; j++)
	 {
		 printf("%2f ", math100[j]);
	 }
	 printf("\n");
	 for (int j = 0; j < SIZE; j++)
	 {
		 printf("%2f ", avg[j]);
	 }
	 printf("\n");
	 return 0;
}

void calculate(double* e, double* m, double* e100, double* m100, double* av, int size)
{
	double sum = 0;

	for (int i = 0; i < SIZE; i++)
	{
		*(e100 + i) = *(e + i)*(double)200.0 / 9.0 ;
	}
	for (int i = 0; i < SIZE; i++)
	{
		*(m100 + i) = (double)(200.0 / 9.0) * *(m + i);
	}
	for (int i = 0; i < SIZE; i++)
	{
		*(av + i) = (double)(*(e100 + i) + *(m100 + i) )/ 2;

	}

}