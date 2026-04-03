#include"Domino.h"
#include"FindleastDominoNUmfunc.h"
#include"StreamFuc.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

// 12-4 시작해 12/7 종료 총 5시간 정도 걸림

int main(void) {

	//도미노 개수,높이, 위치 정보 변수 쓰러트린 도미노 개수선언 및 초기화
	int size = 1, heightins = 0, posins = 0, dominonum = 0;

	//도미노 개수 입력 받기
	fputs("도미노 개수 입력:(1 ~ 300 사이 숫자 입력) ", stdout);
	scanf_s("%d", &size);
	RemoveLineBuf();

	// 도미노 구초체 1차원 배열을 가르키는 포인터 선언 및 초기화
	Domino* dominfo = (Domino*)malloc(sizeof(Domino) * size);
	// 도미노를 넘어트렸을 때 쓰러트릴 수 저장하는 정수형 배열 동적 메모리 할당
	int* PossibleBreakNUm = (int*)malloc(sizeof(int) * size);
	//도미노 넘어졌는지 여부를 나타내는 배열 동적 할당 넘어졌으면 0 넘어지지 않았으면 1을 넣는다.
	int* DetRemainDom = (int*)malloc(sizeof(int) * size);
	// 도미노 쓰러트린 방향 저장하는 배열 true는 오른쪽 false는 왼쪽이다.
	bool* dirptr = (bool*)malloc(sizeof(bool) * size);

	//메모리 할당 중 오류 발생 시 예외 처리
	if (PossibleBreakNUm == NULL || DetRemainDom == NULL || dirptr == NULL || dominfo == NULL) {
		puts("메모리할당 중 오류 발생2");
		return -1;
	}

	for (int i = 0; i < size; i++) {
		//도미노 넘어졌는지 여부를 나타내는 배열 초기화
		DetRemainDom[i] = 1;
		//도미노를 넘어트렸을 때 쓰러트릴 수 저장하는 정수형 배열 0으로 초기화
		PossibleBreakNUm[i] = 0;
		
		//도미노 개수 만큼 도미노의 위치 높이 정보 초기화 
		printf("도미노 %d 의 높이 입력 1 ~ 20억 사이 숫자)", i + 1);
		scanf_s("%d", &heightins);
		RemoveLineBuf();
		dominfo[i].height = heightins;
		
		printf("도미노 %d의 위치 입력1 ~ 300 사이 숫자)", i + 1);
		scanf_s("%d", &posins);
		RemoveLineBuf();
		dominfo[i].pos = posins;
		puts("");
	}
	
	//모든 도미노가 쓰러질 때까지 가장 많은 도미노를 쓰러트리는 도미노를 찾아 쓰러트리는 함수를
	//실행하고 손으로 쓰러트린 도미노 개수를 1씩 증가시킨다.
	do{
		SetImfo(dominfo, PossibleBreakNUm, DetRemainDom, size, dirptr);
		dominonum += 1;
	}while (DetEnd(DetRemainDom, size));

	printf("모든 도미노를 쓰러트리기 위한 쓰러트려야 하는 도미노의 최솟값은 %d개이다\n", dominonum);
	

	// 메모리 할당 해제
	
	return 0;
	free(dominfo);
	free(dirptr);
	free(PossibleBreakNUm);
	free(DetRemainDom);
}