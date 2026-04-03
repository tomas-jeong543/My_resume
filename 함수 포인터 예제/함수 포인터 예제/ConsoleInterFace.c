#include<stdio.h>

void RemoveLineBuf() {
	while (getchar() != '\n');
}


void Menu() {
	puts("1. 더하기");
	puts("2. 빼기");
	puts("3. 곱하기");
	puts("4. 나누기");
	puts("5. 나눗셈 몫");
	puts("6. 나눗셈 나머지");
	puts("7. 종료");
}

void ThrowAwayError() {
	fputs("오류가 발생했습니다", stderr);
}

int GetOption() {
	int n;
	fputs("1 ~ 7 사이의 정수를 입력하십시오: ", stdout);
	scanf_s("%d", &n);
	RemoveLineBuf();

	while (n > 7 || n < 1) {
		ThrowAwayError();
		puts("");
		fputs("1 ~ 7 사이의 정수를 입력하십시오: ", stdout);
		scanf_s("%d", &n);
		RemoveLineBuf();
	}

	return n;
}

double GetNum() {
	double n;
	fputs("숫자를 입력하십시오: ", stdout);
	scanf_s("%lf", &n);
	RemoveLineBuf();
	return n;
}