#include<stdio.h>
#include"complexnum.h"
#include"calculator.h"
#include"inoput.h"

int main(void) {
	
	// 두 복소수의 실수와 허수 부분을 넣을 배열 2개 결과를 나타내는 실수와 허수부분 변수 2개와
	// 그 변수를 가르키는 포인터 변수 2개 선언 및 초기화, 입력 회수를 정해주는 변수 초기화
	double realnumf[2], unrealnumf[2];
	double resulrealnumf, resulunrealnumf;
	double* resulrealnumptrf = &resulrealnumf, * resulunrealnumptrf = &resulunrealnumf;
	int count = 2;

	// 2개의 복소수를 입력받음
	for (int i = 0; i < count; i++)
		GetComnum(&realnumf[i], &unrealnumf[i], i + 1);

	// 두 복소수를 call by reference를 이용해서 더하고 곱한 후 그 결과를 출력한다.
	ComNUmPlus(realnumf, unrealnumf, resulrealnumptrf, resulunrealnumptrf);
	ComNUmMul(realnumf, unrealnumf, resulrealnumptrf, resulunrealnumptrf);

	return 0;
}