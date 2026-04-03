/*#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void) {

	//난수 저장 배열
	int num[2] = { 0, 0 };

	// 시간을 이용한 난수의 시드 값 생성
	srand( (int)time(NULL));

	//주사위 값은 1~6임으로 0인 경우 0 ~ 7 사이의 난수를 다시 생성하는 제어문 생성
	while (num[0] == 0 || num[1] == 0) {
		num[0] = rand() % 7;
		num[1] = rand() % 7;
	}

	//저장된 난수의 배열을 주사위에 결과에 출력
	for (int i = 0; i < 2; i++)
		printf("주사위 %d의 결과: %d \n", i, num[i]);

	return 0;
}*/