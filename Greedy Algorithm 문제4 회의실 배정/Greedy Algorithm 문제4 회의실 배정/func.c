#include"conference.h"
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
// 두 회의의 회의실 사용 시간이 겹치는지 확인하는 함수
bool DetOverlap(Conf a, Conf b)
{
	// 1번 회의의 회의실 사용 시작 시간이 2번 회의의 회의실 사용 시작과 종료 시간 사이에 있거나
	// 1번 회의의 회의실 사용 종료 시간이 2번 회의의 회의실 사용 시작과 종료 시간 사이에 있으면
	//두 회의의 회의실 사용 시간이 겹침으로 참 반환 아니면 거짓 반환
	if (a.starttime > b.starttime && a.starttime < b.endtime)
		return true;
	else if (a.endtime > b.starttime && a.endtime < b.endtime)
		return true;
	else
		return false;
}

// 회의실을 사용할 수 있는 회의의 최댓값을 구해 반환하는 함수
int FindMax_Conf_Time(Conf* Conference_Info, int Confnum, int* repeatedtime)
{
	// 회의가 겹치는 횟수가 가장 많은 회의의 인덱스 정보를 저장하는 변수이다.
	int overlapmaxidx = 0;

	// 종료 조건은 모든 회의가 겹치지 않는 상태일 때 break문을 이용해 빠져나간다.
	while (true) {
		
		// 메모리 재할당을 위한 임시변수들 선언
		Conf* Conference_Unrepeated = Conference_Info;
		Conf temp;
		

		//각각의 회의 시간을 자신을 제외한 모든 회의와 비교해 중복되면 중복되는 두 회의 모두 중복 횟수를 1증가시킨다. 
		for (int i = 0; i < Confnum; i++) {
			for (int j = 0; j < Confnum; j++) {
				if (DetOverlap(Conference_Info[i], Conference_Info[j]) && i != j) {
					repeatedtime[i] += 1;
					repeatedtime[j] += 1;
				}
			}

		}

		// 다른 회의와 중복되는 횟수가 가장 많은 회의의 인덱스 정보를 얻어내 저장
		for (int i = 0; i < Confnum; i++) {
			if (repeatedtime[i] > repeatedtime[overlapmaxidx])
				overlapmaxidx = i;
		}

		//제대로 동작하는지 확인하는 테스트 구문
		/*for (int i = 0; i < Confnum; i++) {
			printf("%d ", repeatedtime[i]);
		}*/

		//puts("");

		//만약 모든 회의가 중복되지 않는다면 while문을 탈출한다.
		if (repeatedtime[overlapmaxidx] <= 0)
							break;

		//회의 정보를 나타내는  Conference_Info 와 회의 중복횟수를 나타내는 repeatedtime 변수를 
		// 다른 회의와 중복되는 횟수가 가장 많은 회의의 인덱스 정보를 이용해 그 인덱스에 해당하는
		//회의의 정보를 맨 끝으로 옮긴다.
		temp = Conference_Info[overlapmaxidx];
		Conference_Info[overlapmaxidx] = Conference_Info[Confnum - 1];
		Conference_Info[Confnum - 1] = temp;
		// 회의의 개수를 1개 줄인다.
		Confnum -= 1;
		
		//다른 회의와 중복되는 횟수가 가장 많은 회의의 인덱스 정보를 이용해 그 인덱스에 해당하는
		//회의의 정보를 삭제하기 위해 메모리를 다시 재할당한다.
		Conference_Unrepeated = (Conf*)realloc(Conference_Unrepeated, sizeof(Conf) * Confnum);
		//오류 방지 구문
		if (Conference_Unrepeated != NULL) {
			Conference_Info = Conference_Unrepeated;
		}

		// 중복되는 횟수를 다시 0으로 리셋한다
		for (int i = 0; i < Confnum; i++) {
			repeatedtime[i] = 0;
		}

	} 
	//중복되지 않는 회의의 개수의 최댓값을 반환한다.
	return Confnum;
}

