#include<stdio.h>
//타이머 사용횟수의 최솟값을 구하는 함수
int FindTImerCount(int* timer, int* timernum, int time)
{
	//타이머 시간 정보 접근용 인덱스 선언
	int	timeridx = 0;
	//만약 시간이 타이머로 나누어떨어지지 않으면 -1반환
	if (time % 10 != 0) {
		return -1;
	}//아니면 타이머를 시간이 큰 순대로 사용해 타이머 사용횟수 정보를 갱신하고 0을 반환한다
	else {

		while (time > 0) {
			if (time / timer[timeridx] > 0) {
				timernum[timeridx] += 1;
				time -= timer[timeridx];
			}
			else
				timeridx += 1;
		}
	}

	return 0;
}