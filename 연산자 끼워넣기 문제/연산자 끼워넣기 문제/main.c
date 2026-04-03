/*입력
첫째 줄에 수의 개수 N(2 ≤ N ≤ 11)가 주어진다. 둘째 줄에는 A1, A2, ..., AN이 주어진다. 
(1 ≤ Ai ≤ 100) 셋째 줄에는 합이 N-1인 4개의 정수가 주어지는데, 
차례대로 덧셈(+)의 개수, 뺄셈(-)의 개수, 곱셈(×)의 개수, 나눗셈(÷)의 개수이다.

출력
첫째 줄에 만들 수 있는 식의 결과의 최댓값을, 둘째 줄에는 최솟값을 출력한다. 
연산자를 어떻게 끼워넣어도 항상 -10억보다 크거나 같고, 10억보다 작거나 같은 결과가 나오는 입력만 주어진다. 또한, 
앞에서부터 계산했을 때, 중간에 계산되는 식의 결과도 항상 -10억보다 크거나 같고, 10억보다 작거나 같다.*/
#include<stdio.h>
#include"Cal.h"
#include<stdlib.h>
#include"Cal_Combination.h"

int main(void) {

	int NUm = 0;
	int* NUmarr;
	int calnum[4] = { 0,0,0,0 };
	int* calresult;
	int pacnum = 1;
	int* pacnumptr = &pacnum;
	do {
		printf("수의 개수 N(2 ≤ N ≤ 11 입력: ");
		scanf_s("%d", &NUm);
	} while (NUm < 2 || NUm > 11);

	NUmarr = (int*)malloc(sizeof(int) * NUm);
	calresult = (int*)malloc(sizeof(int) * Complex_Pactorial(NUm - 1, pacnumptr));

	if (NUmarr == NULL || calresult == NULL) {
		puts("메모리 할당 오류 발생");
		return -1;
	}

	for (int i = 0; i < NUm; i++) {
		printf("숫자입력(1 ~ 100사이 수):");
		scanf_s("%d", &NUmarr[i]);
	}

	for (int i = 0; i < Simple_Pactorial(NUm - 1); i++) {
		calresult[i] = NUmarr[0];
	}

	printf("연산 기호 입력:(차례대로 +, -, *, /순이고 네 수의 합은 숫자개수 -1개 이다. 개수는 공백으로 구분)");
	scanf_s("%d %d %d %d", &calnum[0], &calnum[1], &calnum[2], &calnum[3]);

	Save_All_Result(&calresult, calnum, NUmarr, NUmarr[1], NUm - 1, 1, Simple_Pactorial(NUm - 1));
	
		for (int i = 0; i < Simple_Pactorial(NUm - 1); i++) {
			printf("%d ", calresult[i]);
		}


	return 0;
	free(NUmarr);
	free(calresult);
}