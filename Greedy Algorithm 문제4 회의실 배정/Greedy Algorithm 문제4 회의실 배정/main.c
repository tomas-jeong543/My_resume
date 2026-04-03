/*(문제
한 개의 회의실이 있는데 이를 사용하고자 하는 N개의 회의에 대하여 회의실 사용표를 만들려고 한다. 각 회의 I에 대해 시작시간과 끝나는 시간이 주어져 있고,
각 회의가 겹치지 않게 하면서 회의실을 사용할 수 있는 회의의 최대 개수를 찾아보자. 
단, 회의는 한번 시작하면 중간에 중단될 수 없으며 한 회의가 끝나는 것과 동시에 다음 회의가 시작될 수 있다. 
회의의 시작시간과 끝나는 시간이 같을 수도 있다. 이 경우에는 시작하자마자 끝나는 것으로 생각하면 된다.

입력
첫째 줄에 회의의 수 N(1 ≤ N ≤ 100,000)이 주어진다.
둘째 줄부터 N+1 줄까지 각 회의의 정보가 주어지는데 이것은 공백을 사이에 두고 회의의 시작시간과 끝나는 시간이 주어진다. 
시작 시간과 끝나는 시간은 231-1보다 작거나 같은 자연수 또는 0이다.

출력
첫째 줄에 최대 사용할 수 있는 회의의 최대 개수를 출력한다.*/
#include<stdio.h>
#include<stdlib.h>
#include"conference.h"
#include"func.h"
// 예전에 풀었던 중복되지 않는 선들의 길이의 합을 구하는 문제와 유사해 생각보다 쉽게 풀었다
//다만 개선사항으로 구조체에 겹치는 횟수까지 저장했다면 더 좋았을 것이다.
int main(void) {
	
	//회의 숫자 저장 변수 회의 정보 저장하는 구조체 변수 포인터 선언
	int Conference_NUm = 0;
	Conf * Conference_Info;
	// 각 회의가 다른 회의와 겹치는 횟수를 저장하는 포인터
	int* repeatedtime;
	// 겹치지 않는 회의의 최대 갯수
	int Max_Conference_Num;

	//회의 수 입력
	printf("회의의 수 N(1 ≤ N ≤ 100,000) 입력:");
	scanf_s("%d", &Conference_NUm);

	//회의 수 정보를 이용해 메모리 동적 할당
	Conference_Info = (Conf*)malloc(sizeof(Conf) * Conference_NUm);
	repeatedtime = (int*)malloc(sizeof(int) * Conference_NUm);
	//오류 방지 구문
	if (Conference_Info == NULL || repeatedtime == NULL) {
		puts("동적 메모리 할당 1중 오류 발생");
		return -1;
	}

	//회의의 시작 시간 및 종료 시간 입력 및 겹치는 횟수 저장하는 포인터 초기화
	for (int i = 0; i < Conference_NUm; i++) {
		printf("공백을 사이에 두고 회의의 시작시간과 끝나는 시간 입력:");
		scanf_s("%d %d", &Conference_Info[i].starttime, &Conference_Info[i].endtime);
		repeatedtime[i] = 0;
	}

	// FindMax_Conf_Time함수를 이용해 겹치지 않는 함수의 최댓값을 얻는다.
	Max_Conference_Num = FindMax_Conf_Time(Conference_Info, Conference_NUm, repeatedtime);
	//결과 출력
	printf("사용할 수 있는 회의의 최대 개수는 %d이다,\n", Max_Conference_Num);
	return 0;
}