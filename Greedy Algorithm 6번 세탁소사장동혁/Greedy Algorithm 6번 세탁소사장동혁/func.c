#include<stdio.h>

// 포인터를 이용해 거스름돈을 지불하기 위한 동전의 최소개수를 계산하고 저장해 반환한다.
int* Reurn_Leftover_result(int * money, int c)
{
	//동전의 가격 정보 설정
	int moneyinfo[4] = { 25,10,5,1 };
	//while문에서 돌기 때문에 가격 정보 접근 인덱스 설정
	int i = 0;

	//거스름돈이 다 지불되기 전까지 반복하라는 뜻
	while (c > 0) {
		// 만약 지금 동전의 단위로 지불이 가능하면 지불하고 지불할 동전개수 갱신
		if (c / moneyinfo[i] > 0) {
			c -= moneyinfo[i];
			money[i] += 1;
		}//아니면 동전의 단위를 하나 낮춘다.
		else
			i += 1;
	}

	return money;
}