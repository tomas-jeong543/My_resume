/*#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//입력 버퍼를 지우는 함수
void RemoveLineBuf() {

	while (getchar() != '\n');
}

int main(void) {

	// 길이가 5인 int형 배열 선언
	int* numarr = (int*)malloc(sizeof(int) * 5);

	if (numarr == NULL) {
		puts("numarr 공간 할당 실패\n");
		return -1;
	}
	// 입력받을 숫자 배열의 인덱스 값, 처음 메모리 용량, 메모리공간이 부족할 때마다 늘어날 공간의 값 선언
	int num = 0;
	int arridx = 0;
	int  memsize = 3;
	int const basicmem = 5;

	// 입력받은 숫자가 -1 이 아닐 때까지 계속 숫자를 입력받는다.
	do {
		//숫자를 입력 받고 입력 버퍼를 지운다.
		printf("(종료를 원하면 -1을 누르시오) 숫자을 입력하시오:");
		scanf_s("%d", &num);
		RemoveLineBuf();
		
		//입력 빋은 숫자를 메모리공간에 저장
		numarr[arridx++] = num;

		// 만약 메모리 공간이 가득찬 경우
		if ((arridx - 5) % 3 == 0 && arridx > 4)  {

			
			// 메모리를 realloc함수를 이용해 확장한다.
			int* ins = (int*)realloc(numarr, sizeof(int) * (basicmem + memsize));
			// 메모리 손상 방지를 위한 조건
			if (ins != NULL) {
				numarr = ins;
				memsize += 3;
			}
		}
	} while (num != -1);

	// 배열 값 출력
	puts("입력한 숫자 순서대로 출력");

	for (int i = 0; i < arridx; i++)
		printf("%d ", *(numarr + i));
	
	return 0;
	//메모리 공간 해제
	free(numarr);
}*/