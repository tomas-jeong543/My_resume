#include <stdio.h>
//입력버퍼를 지우는 함수
void RemoveLineBuf(void) {
	while (getchar() != '\n');
}
// 복소수를 입력받는 함수
void GetComnum(double * realnum, double * unrealnum, int count) {

	printf("복소수입력%d[실수 허수]:", count);
	scanf_s("%lf %lf", realnum, unrealnum);
	RemoveLineBuf();
};
// 결과를 출력하는 함수
void PrintResultComnum(double* realnum, double* unrealnum) {
	printf("실수: %lf, 허수 %lf\n", *realnum, *unrealnum);
}