/*/카지노에서 제일 인기 있는 게임 블랙잭의 규칙은 상당히 쉽다.카드의 합이 21을 넘지 않는 한도 내에서
, 카드의 합을 최대한 크게 만드는 게임이다.블랙잭은 카지노마다 다양한 규정이 있다.

한국 최고의 블랙잭 고수 김정인은 새로운 블랙잭 규칙을 만들어 상근, 창영이와 게임하려고 한다.

김정인 버전의 블랙잭에서 각 카드에는 양의 정수가 쓰여 있다.그 다음, 딜러는 N장의 카드를 모두 숫자가 보이도록 바닥에 놓는다.
그런 후에 딜러는 숫자 M을 크게 외친다.

이제 플레이어는 제한된 시간 안에 N장의 카드 중에서 3장의 카드를 골라야 한다.블랙잭 변형 게임이기 때문에, 
플레이어가 고른 카드의 합은 M을 넘지 않으면서 M과 최대한 가깝게 만들어야 한다.

N장의 카드에 써져 있는 숫자가 주어졌을 때, M을 넘지 않으면서 M에 최대한 가까운 카드 3장의 합을 구해 출력하시오.

입력
첫째 줄에 카드의 개수 N(3 ≤ N ≤ 100)과 M(10 ≤ M ≤ 300, 000)이 주어진다.둘째 줄에는 카드에 쓰여 있는 수가 주어지며,
이 값은 100, 000을 넘지 않는 양의 정수이다.

합이 M을 넘지 않는 카드 3장을 찾을 수 있는 경우만 입력으로 주어진다.

출력
첫째 줄에 M을 넘지 않으면서 M에 최대한 가까운 카드 3장의 합을 출력한다*/
#include<stdio.h>
#include<stdlib.h>
#include"Blackjackfunc.h"
// 12-10 해결 2시간 정도 걸림 쉬운 문제지만 어렵게 풀려고 하다 보니 꼬였다.
void RemoveLineBuf() {
	while (getchar() != '\n');
}

int main(void) {
	
	// 카드 개수 저장 인수, 카드정보 저장하는 포인터, 딜러가 말하는 숫자N card를 나타내는 정수형 변수 3개와
	// 그 정수들을 가르키는 포인터 선언 및 초기화
	int Cardnnum = 0;
	int* cardinfo;
	int M;
	int cardnum1 = 1, cardnum2 = 1, cardnum3 = 1;
	int * card1ptr = &cardnum1, * card2ptr = &cardnum2, * card3ptr = &cardnum3;

	// 카드 개수와 숫자 M입력받기
	printf("카드 개수와 숫자 M을 입력하시오:");
	scanf_s("%d %d", &Cardnnum, &M);
	RemoveLineBuf();

	// 카드 정보 가르키는 메모리 동적 항당
	cardinfo = (int*)malloc(sizeof(int) * Cardnnum);

	// 카드의 숫자 입력 및 정보 저장
	for (int i = 0; i < Cardnnum; i++) {
		printf("카드 %d 입력:", i + 1);
		scanf_s("%d", &cardinfo[i]);
	}

	// 카드를 숫자에 따라 오름차순 정렬
	cardinfo = SortByNum(cardinfo, Cardnnum);
	// 원하는 블랙젝 숫자 구하기
	FindBlackJackNUm(cardinfo, card1ptr, card2ptr, card3ptr, M, Cardnnum);
	//출력
	printf("세 수의 합이 %d에 가장 가까운 세 숫자는 %d %d %d 이다.", M, *card1ptr, *card2ptr, *card3ptr);

	return 0;
}