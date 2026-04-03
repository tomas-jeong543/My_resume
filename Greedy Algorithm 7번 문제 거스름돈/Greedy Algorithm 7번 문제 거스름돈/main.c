/*문제
타로는 자주 JOI잡화점에서 물건을 산다. JOI잡화점에는 잔돈으로 500엔, 100엔, 50엔, 10엔, 5엔, 1엔이 충분히 있고, 
언제나 거스름돈 개수가 가장 적게 잔돈을 준다. 타로가 JOI잡화점에서 물건을 사고 카운터에서 1000엔 지폐를 한장 냈을 때,
받을 잔돈에 포함된 잔돈의 개수를 구하는 프로그램을 작성하시오.

입력
입력은 한줄로 이루어져있고, 타로가 지불할 돈(1 이상 1000미만의 정수) 1개가 쓰여져있다.

출력
제출할 출력 파일은 1행으로만 되어 있다. 잔돈에 포함된 매수를 출력하시오.*/
//너무 너무 너무 쉬운 문제 반복문의 기초만 알아도 해결 할 수 있다.
#include<stdio.h>

int main(void) {

	//지불 비욜,나머지 변수 선언
	int payment, leftover;
	//거스름돈 정보 저장
	int Changeinfo[6] = { 500, 100, 50, 10, 5, 1 };
	//거스름돈 정보의 인덱스 정보 변수 초기화
	int Changeidx = 0;
	//거스름돈 개수 변수 선언
	int Change_Num = 0;
	//지불 비용 입력
	printf("지불 비용을 입력하시오:(1 이상 1000미만의 정수) ");
	scanf_s("%d", &payment);
	//잔돈 계산
	leftover = 1000 - payment;
	//잔돈이 없을 때까지 반복
	while (leftover > 0) {
		
		//거스름돈이 현재 인덱스에 있는 거스름돈으로 지불 가능하면 지불하고 거스름돈 액수를 줄이고 거스름돈 개수를 늘린다.
		if (leftover / Changeinfo[Changeidx] > 0) {
			leftover -= Changeinfo[Changeidx];
			Change_Num += 1;
		}
		else//아니면 거스름돈의 단위를 낮춘다.
			Changeidx += 1;
	}

	//거스름돈 출력
	printf("거스름돈 개수 %d\n", Change_Num);

	return 0;
}