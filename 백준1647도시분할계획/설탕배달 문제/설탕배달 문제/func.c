#include<stdbool.h>
#include"func.h"


// 3kg 봉지롸 5kg봉지로 설탕을 정확히 담을 수 있는지를 통해 가능하면 true를 불가능하면 false를 반환한다.
// 모든 경우의 수에 대해서 가장 작은 비닐봉지를 사용하는 값을 구하고 그 값를 포인터 변수를 통해 전달한다.
bool Det_PossibleDivide(int n, int * num1, int * num2)
{
	//초기값 설정으로 변경되지 않으면 false반환
	*num1 = -1;
	*num2 = -1;

	//우선 먼저 5kg봉지에 설탕을 담고 3kg봉지에 설탕을 담는 모든 경우의 수를 확인해 무게가 일치하는 수가
	//있으면 기존 봉지의 개수와 비교해서 더 작으면 값을 갱신한다.
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < (5000 - 5 * i) / 3; j++) {
			if (n == 5 * i + 3 * j) {
				
				if (*num1 + *num2 > i + j || (*num1 == -1 && *num2 == -1)) {
					//printf("1 i: %d j: %d\n", i, j);
					*num1 = i;
					*num2 = j;
				}
			}
		}
	}
	
	//우선 먼저 3kg봉지에 설탕을 담고 5kg봉지에 설탕을 담는 모든 경우의 수를 확인해 무게가 일치하는 수가
	//있으면 기존 봉지의 개수와 비교해서 더 작으면 값을 갱신한다.
	for (int i = 0; i < 1666; i++) {
		for (int j = 0; j < (5000 - 3 * i) / 5; j++) {
			if (n == 3 * i + 5 * j) {
				
				if (*num1 + *num2 > i + j || (*num1 == -1 && *num2 == -1)) {
					//printf("2 i: %d j: %d\n", i, j);
					*num1 = i;
					*num2 = j;
				}
			}
		}
	}

	//가능한 경우의 수가 있으면 true 없으면 false반환
	if (*num1 == -1 && *num2 == -1)
		return false;
	else
		return true;
}


