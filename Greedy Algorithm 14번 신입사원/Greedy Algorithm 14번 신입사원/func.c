#include<stdio.h>
#include"person.h"
//합격자 수를 찾는 함수 
int FindPassedNUm(Person* attendent, int attendnum)
{
	//합격자 인원 수 0으로 초기화
	int passednum = 0;

	//모든 지원자를 자기 자신 제외 지원자와 비교해 만약 둘 중 한 면접에서라도 우위를 가진다면
	//통과 아니면 불합격 처리하는 것을 구현한 이중 FOR문과 break문이다.
	for (int i = 0; i < attendnum; i++) {
		for (int j = 0; j < attendent; j++) {	
			
			if (i != j) {
				if (attendent[i].first_test_rank > attendent[j].first_test_rank &&
					attendent[i].second_test_rank > attendent[j].second_test_rank)
					break;
			}

			if (j == attendnum - 1) {
				passednum += 1;
			}
		}
	}
	//합격자 수 반환
	return passednum;
}