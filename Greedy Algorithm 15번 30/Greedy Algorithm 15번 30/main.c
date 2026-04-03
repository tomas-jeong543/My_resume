/*문제
어느 날, 미르코는 우연히 길거리에서 양수 N을 보았다. 미르코는 30이란 수를 존경하기 때문에,
그는 길거리에서 찾은 수에 포함된 숫자들을 섞어 30의 배수가 되는 가장 큰 수를 만들고 싶어한다.

미르코를 도와 그가 만들고 싶어하는 수를 계산하는 프로그램을 작성하라.

입력
N을 입력받는다. N는 최대 105개의 숫자로 구성되어 있으며, 0으로 시작하지 않는다.

출력
미르코가 만들고 싶어하는 수가 존재한다면 그 수를 출력하라. 그 수가 존재하지 않는다면, -1을 출력하라.*/
#include<stdio.h>
#include<stdlib.h>
#include"func.h"
// 중간 난이도의 문제로 생각보다 여러 과정을 거쳐 데이터에서 원하는 자료를 추출해야 되서 시간이 꽤 걸렸다.
int main(void)
{
	// 숫자와 자릿수 저장 변수 및 자릿수를 저장하는 포인터 변수 선언
	int num, digits;
	int* digitsinfo;
	//숫자 입력
	printf("양수 N 입력:");
	scanf_s("%d", &num);
	//숫자의 자릿수 구함
	digits = FindLen(num);
	//자릿수 정보를 저장하는 동적 메모리 할당
	digitsinfo = (int*)malloc(sizeof(int) * digits);
	//오류 발생 시 예외 처리
	if (digitsinfo == NULL) {
		puts("동적 메모리 할당 중 오류 발생");
		return -1;
	}
	//자릿수 정보를 저장한다.
	FinddigitsInfo(digits, num, digitsinfo);
	//자릿수의 숫자를 내림차순으로 정렬한다.
	SortedLower(digitsinfo, digits);
	//숫자가 30으로 나누어 떨어지면서 가장 크게 만들어 출력 또는 30으로 나누어떨어지지 않으면 -1출력
	Find30N(digits, num, digitsinfo);
	

	return 0;
}