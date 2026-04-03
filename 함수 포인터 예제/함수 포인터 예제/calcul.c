#include<stdio.h>
void Add(double n1, double  n2)
{
	printf("두 수 %f 와 %f의 합은 %f이다.\n", n1, n2, n1 + n2);
}

void Subtract(double  n1, double  n2)
{
	printf("두 수 %f 과 %f의 차는 %f이다.\n", n1, n2, n1 - n2);
}

void Mul(double  n1, double  n2)
{
	printf("두 수 %f 과 %f의 곱은 %f이다.\n", n1, n2, n1 * n2);
}

void Divide(double  n1, double  n2)
{
	printf("%f 을 %f로 나눈 값은 %f이다.\n", n1, n2, n1 / n2);
}


void Qution(double  n1, double  n2)
{
	printf(" %f 을 %f로 나눈 몫은  %d이다.\n", n1, n2, (int)n1 / (int)n2);
}

void Remainder(double  n1, double  n2)
{
	printf("%f 을 %f로 나눈 나머지는  %d이다\n", n1, n2, (int)n1 % (int)n2);
}

void Close() {
	puts("계산기 프로그램을 종료합니다.");
	return;
}