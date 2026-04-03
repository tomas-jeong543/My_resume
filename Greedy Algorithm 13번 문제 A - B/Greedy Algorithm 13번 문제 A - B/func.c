#include<stdio.h>
//연산 수의 최솟값을 계산하는 함수 만약 연산이 불가능하면 -1을 반환
int FindLeastCalNUm(int a, int b)
{
	//연산 수 변수 선언 및 초기화
	int calnum = 0;

	//A와B가 같으면 연산횟수가 0임으로 1반환
	if (a == b)
		return 1;

	//b 가 a보다 클 동안 반복
	while (b > a) {
		//b가 짝수면 나누기2
		if (b % 2 == 0) {
			b /= 2;
			//연산 횟수 증가
			calnum += 1;
		}
		else {
			//홀수면 -1하고 /10한다.
			b -= 1;
			b /= 10;
			//연산 횟수 증가
			calnum += 1;
		}
	
		//만약 a와b가 같다면 연산횟수 + 1반환
		if (a == b) {
			return calnum + 1;
		}//아니고 b가a보다 작으면 애초에 a로b를 못 만든단 소리니 -1반환
		else if (b < a) {
			return -1;
		}
	}

}