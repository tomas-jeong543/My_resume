/*문제
옛날 옛적에 수학이 항상 큰 골칫거리였던 나라가 있었다. 이 나라의 국왕 김지민은 다음과 같은 문제를 내고 큰 상금을 걸었다.

길이가 N인 정수 배열 A와 B가 있다. 다음과 같이 함수 S를 정의하자.

S = A[0] × B[0] + ... + A[N-1] × B[N-1]

S의 값을 가장 작게 만들기 위해 A의 수를 재배열하자. 단, B에 있는 수는 재배열하면 안 된다.

S의 최솟값을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. 둘째 줄에는 A에 있는 N개의 수가 순서대로 주어지고, 셋째 줄에는 B에 있는 수가 순서대로 주어진다.
N은 50보다 작거나 같은 자연수이고, A와 B의 각 원소는 100보다 작거나 같은 음이 아닌 정수이다.

출력
첫째 줄에 S의 최솟값을 출력한다.*/
#include<stdio.h>
#include<stdlib.h>
#include"func.h"
//쉬운 문제 그냥 A를 오름차순 정렬하고 B도 오름차순 정렬해 다른 포인터에 저장한 후에 B의 숫자 크기 순서를 정하는
//함수를 이용해 B의 순서정보를 알려주는 배열에 순서 정보를 저장하고 순서 정보 배열과 오름차순 정렬된 A배열을 
//이용해 A배열의 순서를 S값이 최솟값이 나오도록 바꾸고 갱신된 A배열과 기존 B배열의 곱을 통해 최솟값을 구하면 된다.
int main(void) {
	
	//배열 크기와 계산의 합 저장할 변수 선언
	int size, S = 0;
	//A,B와 B를 오름차순 정렬해 저장할 포인터, 
	//그리고 이를 이용해 B포인터의 숫자 크기에 따른 순위를
	//인덱스로 저장하는 포인터 선언 
	int* A,* B, * Bsorted, * Binfo;

	//배열 크기 입력
	fputs("배열의 크기를 입력하시오:", stdout);
	scanf_s("%d", &size);
	RemoveLineBuf();

	//동적 메모리 할당
	A = (int*)malloc(sizeof(int) * size);
	B = (int*)malloc(sizeof(int) * size);
	Bsorted = (int*)malloc(sizeof(int) * size);
	Binfo = (int*)malloc(sizeof(int) * size);

	//오류 체크
	if (A == NULL || B == NULL || Bsorted == NULL || Binfo == NULL){
		puts("동적 메모리 할당 중 오류 발생");
			return -1;
	}

	//A입력
	for (int i = 0; i < size; i++) {
		printf("a[%d]", i + 1);
		scanf_s("%d", &A[i]);
		RemoveLineBuf();
	}
	//A오름차순 정렬
	A = SortedUpper(A, size);
	
	//B입력
	for (int i = 0; i < size; i++) {
		printf("b[%d]", i + 1);
		scanf_s("%d", &B[i]);
		RemoveLineBuf();
	}
	//B를 Bsorted에 복사
	for (int i = 0; i < size; i++) {
		Bsorted[i] = B[i];
	}

	// Bsorted를 오름차순 정렬
	Bsorted = SortedUpper(Bsorted, size);
	//Binfo를 Bsorted와 B를 이용해서 초기화
	Binfo = Ranknum(B, Bsorted, Binfo, size);
	//BInfo를 이용해 A값 갱신
	A = sortbyBinfo(Binfo, A, size);


	//A와 B배열의 값이 잘바뀌었는지 확인하는 구문 
	/*for (int i = 0; i < size; i++) {
		printf("A: %d  B: %d  Bcopy: %d, Binfo: %d\n", A[i], B[i], Bsorted[i], Binfo[i]);
		S += A[i] * B[i];
	}*/
	// 계산 결과 합 계산
	for (int i = 0; i < size; i++) {
		S += A[i] * B[i];
	}
	//출력
	printf("계산의 최솟값은 %d이다\n", S);

	return 0;
	free(A);
	free(B);
	free(Bsorted);
	free(Binfo);
}