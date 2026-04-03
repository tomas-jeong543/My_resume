/*문제
준규가 가지고 있는 동전은 총 N종류이고, 각각의 동전을 매우 많이 가지고 있다.

동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다. 이때 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 1 ≤ K ≤ 100,000,000)

둘째 줄부터 N개의 줄에 동전의 가치 Ai가 오름차순으로 주어진다. (1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수)

출력
첫째 줄에 K원을 만드는데 필요한 동전 개수의 최솟값을 출력한다.*/

#include<stdio.h>
#include<stdlib.h>
#include"func.h"
//쉬운 문제로 반복문 for과 while만 잘 중첩시키면 쉽게 원하는 값을 구할 수 있었다.
int main(void) {

	// 동전의 종류의 개수 저장 변수 동전의 합을 통해 만드려는 가치의 합 저장 변수 선언
	int cointypenum = 0, Value = 0;
	// 동전 가격을 저장하는 배열을 동적할당하기 위한 포인터 변수 선언
	int* coinprice;
	//가치를 만들기 위해 사용한 동전 개수를 저장하는 배열을 동적할당하기 위한 포인터 변수 선언
	int* coinnum;
	// 사용한 동전의 최솟값을 저장하는 변수
	int Min_coinnumsum = 0;

	//입력
	printf("동전의 종류 N과 만들려는 가치의 합 K 입력: 단 (1 ≤ N ≤ 10, 1 ≤ K ≤ 100,000,000)");
	scanf_s("%d %d", &cointypenum, &Value);

	// 입력 정보를 이용한 메모리의 동적 할당 및 오류 점검
	coinprice = (int*)malloc(sizeof(int) * cointypenum);
	coinnum = (int*)malloc(sizeof(int) * cointypenum);
	if (coinprice == NULL || coinnum == NULL) {
		puts("동적 메모리 할당 중 오류 발생");
		return -1;
	}

	// 동전의 가격 입력받고 동전의 개수 정보 초기화
	for (int i = 0; i < cointypenum ; i++) {	
		scanf_s("%d", &coinprice[i]);
		coinnum[i] = 0;
	}

	// 원하는 값을 반들기 위한 동전의 최소 개수를 이용하는 경우를 함수를 통해
	//구하고 그 값응 사용한 동전의 개수 정보에 저장되어 있다. 
	Use_Mincoin_ToMake_Value(coinnum, Value, coinprice, cointypenum);

	// 동전 개수의 정보를 이용래 동전의 최솟값을 구한다.
	for (int i = 0; i < cointypenum; i++) {
		Min_coinnumsum += coinnum[i];
	}
	//필요한 동전 개수 출력
	printf("필요한 동전의 개수의 최솟값은 %d개이다.\n", Min_coinnumsum);

	//동적 메모리 할당 해제
	free(coinprice);
	free(coinnum);
	return 0;
}
