#include<stdbool.h>
#include"Domino.h"

// 도미노가 다 쓰러졌으면 true 아니면 false를 반환한다.
bool DetEnd(int* Detcopy, int size)
{
	for (int i = 0; i < size; i++) {
		if (Detcopy[i] == 1)
			return true;
	}
	
	return false;
}

// 한도미노를 오른쪽으로 쓰러트렸을 때 쓰러지는 도미노수를 개산해 포인터를 이용해 값을 집어 넣는 함수
void FindRightWay(Domino* dominfo, int* Breknuminfo, int* Detcopy, 
	int size, int startpoint, bool* dirptr, int domidx)
{	
	//끝나는 점과 새로운 끝나는 점을 저장하는 변수 선언
	int newendpoint;
	// 쓰러진 도미노 개수 저장하는 변수
	int breaksum = 0;
	//초기값 설정
	int endpoint = startpoint + dominfo[domidx].height;

	// 도미노가 오른똑으로 쓰러트릴 수 있는 구간에 도미노가 있으면 그 도미노가 쓰러트릴 수 있는 구간의
	//끝나는 지점을 기존 갑과 비교해 범위가 더 넓으면 끝나는 지점을 갱신한다.
		for (int i = 0; i < size; i++) {
			if (dominfo[i].pos >= startpoint && dominfo[i].pos <= endpoint && Detcopy[i] == 1) {
				newendpoint = dominfo[i].pos + dominfo[i].height;
				if (newendpoint > endpoint)
						endpoint = newendpoint;
			}
		} 

		//도미노가 쓰러트리는 범위 내에 있는 도미노의 개수를 위치 정보를 통해 구한다.
		for (int j = 0; j < size; j++) {
			if (dominfo[j].pos >= startpoint && dominfo[j].pos <= endpoint && Detcopy[j] == 1) {
				breaksum += 1;
			}
		}

		// 기존에 저장된 값 보다 클 때만 정보를 갱신 + 방향 정보 갱신
		if (breaksum > Breknuminfo[domidx]) {
			Breknuminfo[domidx] = breaksum;
			dirptr[domidx] = false;
		}
		
}
// 한도미노를 왼쪽으로 쓰러트렸을 때 쓰러지는 도미노수를 개산해 포인터를 이용해 값을 집어 넣는다
void FindLeftWay(Domino* dominfo, int* Breknuminfo, int* Detcopy, 
	int size, int startpoint, bool* dirptr, int domidx)
{	
	//끝나는 점과 새로운 끝나는 점을 저장하는 변수 선언
	int newendpoint;
	// 쓰러진 도미노 개수 저장하는 변수
	int breaksum = 0;
	//초기값 설정
	int endpoint = startpoint - dominfo[domidx].height;

	// 도미노를 왼쪽으로 쓰러트릴 수 있는 구간에 도미노가 있으면 그 도미노가 쓰러트릴 수 있는 구간의
	//끝나는 지점을 기존 갑과 비교해 범위가 더 넓으면 끝나는 지점을 갱신한다.
	for (int i = 0; i < size; i++) {
		if (dominfo[i].pos <= startpoint && dominfo[i].pos >= endpoint && Detcopy[i] == 1) {
			newendpoint = dominfo[i].pos - dominfo[i].height;
			if (newendpoint < endpoint)
				endpoint = newendpoint;
		}
	}
	//도미노가 쓰러트리는 범위 내에 있는 도미노의 개수를 위치 정보를 통해 구한다.
	for (int j = 0; j < size; j++) {
		if (dominfo[j].pos <= startpoint && dominfo[j].pos >= endpoint && Detcopy[j] == 1) {
			breaksum += 1;
		}
	}

	// 기존에 저장된 값 보다 클 때만 정보를 갱신 + 방향 정보 갱신
	if (breaksum > Breknuminfo[domidx]) {
		Breknuminfo[domidx] = breaksum;
		dirptr[domidx] = true;
	}
}

void ChangeDet(Domino* dominfo, int* Breknuminfo, int* Detcopy,
	int size, int startpointidx, bool* dirptr)
{

	//도미노 시작점의 도미노의 상태를 무너진 상태로 바꾼다.
	Detcopy[startpointidx] = 0;

	//끝나는 점과 새로운 끝나는 점을 저장하는 변수 선언
	int endpoint, newendpoint, startpoint;

	
	if (dirptr[startpointidx] == false) {
	
	//도미노를 오른쪽으로 무너뜨리는 경우

	//초기값 설정	
		endpoint = dominfo[startpointidx].pos + dominfo[startpointidx].height;
		startpoint = dominfo[startpointidx].pos;
	
	// 도미노가 쓰러트릴 수 있는 구간에 도미노가 있으면 그 도미노가 쓰러트릴 수 있는 구간의
	//끝나는 지점을 기존 갑과 비교해 범위가 더 넓으면 끝나는 지점을 갱신한다.
		for (int i = 0; i < size; i++) {
			if (dominfo[i].pos >= startpoint && dominfo[i].pos <= endpoint) {
				newendpoint = dominfo[i].pos + dominfo[i].height;
				
				if (newendpoint > endpoint)
						endpoint = newendpoint;
			}
		}

		//도미노가 넘어뜨리는 시작점과 끝 점사이의 도미노의 상태를 넘어진 상태로 바꾼다.
		for (int j = 0; j < size; j++) {
			if (dominfo[j].pos >= startpoint && dominfo[j].pos <= endpoint) {
				Detcopy[j] = 0;
			}
		}
	}
	else if(dirptr[startpointidx] == true) {
		//도미노를 왼쪽으로 무너뜨리는 경우

		//초기값 설정	
		endpoint = dominfo[startpointidx].pos - dominfo[startpointidx].height;
		startpoint = dominfo[startpointidx].pos;

		// 도미노가 쓰러트릴 수 있는 구간에 도미노가 있으면 그 도미노가 쓰러트릴 수 있는 구간의
		//끝나는 지점을 기존 갑과 비교해 범위가 더 넓으면 끝나는 지점을 갱신한다.	
		for (int i = 0; i < size; i++) {
			if (dominfo[i].pos <= startpoint && dominfo[i].pos >= endpoint) {
				newendpoint = dominfo[i].pos - dominfo[i].height;
				if (newendpoint < endpoint)
					endpoint = newendpoint;
			}
		}
		
		//도미노가 넘어뜨리는 시작점과 끝 점사이의 도미노의 상태를 넘어진 상태로 바꾼다.
		for (int j = 0; j < size; j++) {
			if (dominfo[j].pos <= startpoint && dominfo[j].pos >= endpoint) {
				Detcopy[j] = 0;
			}
		}
	}
	
	//도미노의 상태를 출력해 오류 발생시 디버그 위해 사용된 문장
	/*puts("DETCOPy");

	for (int i = 0; i < size; i++) {
		printf("%d\n", Detcopy[i]);
	}*/

}

// 가장 많은 도미노를 넘어뜨리는 도미노의 인덱스 정보를 반환하는 함수
int FindMaxNUmIdx(Domino* dominfo, int* Breknuminfo, int* Detcopy, int size, bool* dirptr )
{
	int maxidx = 0;
		// 최댓갑의 인덱스를 0으로 초기화 하고 배열 내 크기로 비교하고 
		//더 크면 인덱스 정보를 갱신한다
		for(int i = 1; i < size; i++) {
			if (Breknuminfo[i] > Breknuminfo[maxidx]) {
				maxidx = i;
				
			}
		}
		return maxidx;
}

void SetImfo(Domino* dominfo, int* Breknuminfo, int* Detcopy,
	int size,  bool* dirptr)
{	//가장 많은 도미노를 쓰러트리는 도미노의 인덱스 정보 저장 변수
	int maxbreaknumidx;

	//모든 도미노를 오른쪽으로 쓰러트리는 경우와 왼쪽으로 쓰러트리는 경우를 이용해
	// 쓰러트릴 수 있는 도미노 개수 쓰러트리는 도미노의 방향 정보 갱신
	for (int i = 0; i < size; i++) {
		FindRightWay(dominfo, Breknuminfo, Detcopy, size, dominfo[i].pos, dirptr, i);
		FindLeftWay(dominfo, Breknuminfo, Detcopy, size, dominfo[i].pos, dirptr, i);
	}


	puts("도미노 쓰러지는 개수");
	for (int i = 0; i < size; i++)
		printf("%d dom breaknum: %d\n", i, Breknuminfo[i]);


	//가장 많은 도미노를 쓰러트리는 도미노의 인덱스 정보를 구해 저장
	maxbreaknumidx = FindMaxNUmIdx(dominfo, Breknuminfo, Detcopy, size, dirptr);

	// 최대한 많은 도미노를 쓰러트릴 수 있는 도미노의 정보를 인수로 받아 그
	//도미노를 넘어트려 그 영향으로 넘어진 도미노의 상태를 갱신한다.
	ChangeDet(dominfo, Breknuminfo, Detcopy, size, maxbreaknumidx, dirptr);

	
	// 도미노가 쓰러트릴 수 있는 도미노의 개수를 0개로 리셋한다
	//리셋의 이유는 도미노의 상태가 위의 changeDet에 의해 변했기 때문이다.
	for (int i = 0; i < size; i++)
		Breknuminfo[i] = 0;
}
