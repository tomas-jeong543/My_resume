//선 긋기문제(백준 코딩)
//
//매우 큰 도화지에 자를 대고 선을 그으려고 한다.선을 그을 때에는 자의 한 점에서 다른 한 점까지 긋게 된다.선을 그을 때에는 이미 선이 있는 위치에 겹쳐서 그릴 수도 있는데, 여러 번 그은 곳과 
//한 번 그은 곳의 차이를 구별할 수 없다고 하자.
//
//이와 같은 식으로 선을 그었을 때, 그려진 선(들)의 총 길이를 구하는 프로그램을 작성하시오.
//선이 여러 번 그려진 곳은 한 번씩만 계산한다.
//
//입력
//첫째 줄에 선을 그은 횟수 N(1 ≤ N ≤ 1, 000, 000)이 주어진다.
//다음 N개의 줄에는 선을 그을 때 선택한 두 점의 위치 x, y(-1, 000, 000, 000 ≤ x 
//	< y ≤ 1, 000, 000, 000)가 주어진다.
//12-7 시작
#include<stdio.h>
#include"Line.h"
#include"LineFunc.h"
#include<stdbool.h>
#include<stdlib.h>
// 12/7 ~ 12/8 3시간 정도 걸림
int main(void) {
	
	//선의 정보의 배열을 가르키는 포인터와 그 포인터에 메모리를 재할당하기 위한 포인터 선언 및 초기화 
	Lineinfo* lineinforealloc;
	// 좀 더 자세히 설명하자면 lineinfo는 중복되지 않는 선들의 정보만을 저장한다.
	Lineinfo* lineinfo;
	lineinfo  = (Lineinfo*)malloc(sizeof(Lineinfo));
	//메모리 할당 중 오류 처리
	if (lineinfo == NULL) {
		puts("메모리 할당 중 오류 발생");
		return -1;
	}
	lineinforealloc = &lineinfo;
	// 선의 정보를 입력받아 저장할 선 구조체 선언
	Lineinfo ins = { 0, 0 };
	
	lineinfo[0].startpoint = 0;
	lineinfo[0].endpoint = 0;
	//선의 시작점 끝점,입력받을 선의 개수 선언
	int startins, endins;
	int size = 0;
	//중복되지 않는 선들의 정보의 크기를 나타내는 변수와 그 변수를 가르키는 포인터 선언 및 초기화
	int datasize = 1;
	int* dataptr = &datasize;
	// 선들의 총 길이를 저장하는 변수 및 중복되지 않는 선들의 정보를 가지고 있는 포인터의 인덱스 정보 변수 선언 및 초기화
	int linelensum = 0;
	int idx = 0;
	
	//선을 그을 횟수를 입력받는다.
	printf("선을 그을 횟수를 입력하시오:(1 ~ 1,000,000 사이 정수)");
	scanf_s("%d", &size);
	RemoveLineBuf();

	// 선의 개수 만큼 선의 정보를 입력받고 선의 정보가 중복되는지를 확인해 중복되면 두 선을 병합하고 
	//중복되지 않으면 메모리 공간을 새로 할당해 새로운 선의 정보를 저장한다.
	for (int i = 0; i < size; i++) {
		// 선 정보 입력
		printf("시작점:(-10억 ~ 10억사이 정수) ");
		scanf_s("%d", &startins);
		RemoveLineBuf();

		printf("끝나는 점: (-10억 ~ 10억사이 정수)");
		scanf_s("%d", &endins);
		RemoveLineBuf();

		//처음 입력했을 때는 중복되는 것이 없음으로 그냥 lineinfo에 선 정보를 저장한다.
		if (i == 0) {
			lineinfo[0].startpoint = startins;
			lineinfo[0].endpoint = endins;
		}
		else {
			// 임시로 선 정보를 저장한다.
			ins.startpoint = startins;
			ins.endpoint = endins;
		}

		// 두 번째 선이 입력되었을 때 DetOverlap 함수를 이용해서 중복 여부를 확인하고 선이 중복되면
		// 기존의 선과 병합하고 아니면 새로운 선을 저장하기 위해 lineinfo의 realloc으로 크기를 늘리고
		//그 선을 저장하고 크기정보를 갱신한다.
		if (i != 0 && !DetOverlap(lineinfo, ins, dataptr) ) {
			lineinforealloc = (Lineinfo*)realloc(lineinfo,sizeof(Lineinfo) * (datasize + 1));
			
			if (lineinforealloc != NULL) {
				lineinfo = lineinforealloc;
				lineinfo[datasize].endpoint = ins.endpoint;
				lineinfo[datasize].startpoint = ins.startpoint;
				datasize += 1;
			}
		}
		
	}

	//중복되지 않게 선을 입력 받았지만 병합과정에서 범위가 확장되기 때문에 lineinfo 내
	//선들끼리 중복될 수 있다 따라서 CheckOverlapInsideData 함수를 이용해 lineinfo의 중복된
	//선들을 찾아 병합하고 병합된 내용에 따라 변한 lineinfo의 정보를 다시 반환받는다.
	if (datasize != 1) {
		for (int i = 0; i < datasize - 1; i++)
			lineinfo = CheckOverlapInsideData(lineinfo, dataptr, i);
	}
	
	// 서로 겹치지 않는 선들의 출력
	for (int i = 0; i < datasize; i++) {
		printf("서로겹치지 않는  line %d 의 startpoint:%d endpoint: %d\n", i + 1, lineinfo[i].startpoint,
			lineinfo[i].endpoint);
	}

	//서로 겸치지 않는 선들의 정보를 이용해 모든 선들의 길이의 총합을 구한다.
	linelensum = FindLenSum(lineinfo, datasize);
	//결과 출력
	printf("선들의 총 길이의 합은 %d이다.\n", linelensum);

	return 0;
	//메모리 할당 해제
	free(lineinfo);
}