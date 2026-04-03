/*#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// 컴퓨터 숫자를 저장하는 배열에 0 ~ 9 사이의 난수를 집어넣는 함수
void MakeRandomNUm(int *ptr);
// 유저의 도전 회수와 스트라이크 볼의 개수를 출력해주는 함수
void ShowBallStrike(int my[3], int com[3], int* strike, int* ball, int time);
// 스트라이크 개수를 찾는 함수
void FindStrike(int my[3], int com[3], int* strike);
//볼의 개수를 찾는 함수
void FindBall(int my[3], int com[3], int* ball);
// 나의 숫자를 입력받아 배열에 저장하는 함수
void GetMynum(int *ptr);

int main(void) {
	
	// 컴퓨터와 나의 숫자를 저장하는 배열, strike, ball, 그리고 시행 횟수를 저장하는 변수 선언
	int comnum[3] = { 0, 0, 0 }, mynum[3] = { 0, 0, 0 };
	int strike = 0, ball = 0, time  = 0;

	// strike ,ball 을 저장하는 변수를 가르키는 함수
	int * ptrstrike = &strike, * ptrball = &ball;

	// 세 개의 숫자 중 서로 같은 수가 한 쌍이라도 있을 때 반복하는 제어문
	while (comnum[0] == comnum[1] || comnum[0] == comnum[2] || comnum[1] == comnum[2]) {
		MakeRandomNUm(comnum);
	}

	printf("Start Game!\n\n");
	
	// strike가 3이 될 때까지 반복하는 제어문
	do {

		// 시행횟수는 실행할 때마다 1증가 strike, ball 값은 0 으로 초기화
		time += 1;
		strike = 0, ball = 0;

		// 나의 숫자를 입력받고 볼과 스트라이크 개수를 찾고 그 결과를 출력하는 과정
		GetMynum(mynum);
		FindBall( mynum, comnum, ptrball );
		FindStrike(mynum, comnum, ptrstrike);
		ShowBallStrike(mynum, comnum, ptrstrike, ptrball, time);


	} while (strike != 3);


	printf("Game Over!\n");

	return 0;
}

void MakeRandomNUm(int *ptr) {
	
	// 현재시간을 숫자로 시드 값으로 받는다.
	srand((int)time(NULL));

	// 0~9 사이의 난수 발생 및 배열에 저장
	for (int i = 0; i < 3; i++)
		ptr[i] = rand() % 10;
}

void ShowBallStrike(int my[3], int com[3], int* strike, int* ball, int time) {
	// ball과 strike 개수를 출력한다.
	printf("%d번째 도전 결과: %d strike, %dball!\n\n", time, *strike, *ball);
}


void FindStrike(int my[3], int com[3], int* strike) {
	
	// 위치와 숫자가 동시할때 pointer값을 이용해 변수의 값을 증가시킨다.
	for (int i = 0; i < 3; i++) {
		if (my[i] == com[i])
			*strike += 1;
	}

}

void FindBall(int my[3], int com[3], int* ball) {
	
	//위치는 다르지만 나의 숫자와 컴퓨터에 있는 숫자가 같으면 변수의 값 증가시킨다.
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (my[i] == com[j] && i != j)
				*ball += 1;
		}
	}

}

void GetMynum(int *ptr) {
	// pointer을 통해 직접 함수 내에서 변화시킨다.
	printf("3개의 숫자 선택: ");
	scanf_s("%d %d %d", &ptr[0], &ptr[1], &ptr[2]);
	
	printf("\n");
}*/