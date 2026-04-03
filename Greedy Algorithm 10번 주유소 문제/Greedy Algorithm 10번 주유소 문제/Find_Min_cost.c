#include<stdio.h>
//목적지 까지 갈 때 드는 돈의 최솟값을 계산하는 함수
int Find_Min_cost(int* oilprice, int* distanceinfo, int citynum)
{
	//출발 도시, 끝나는 도시, 다음 도시, 돈 값 선언 및 초기화
	int startpoint = 0, endpoint = citynum - 1,nextpoint = 1, money = 0;

	//목적지 도시에 도잘하기 전까지
	while (startpoint < endpoint) {
		
		//일단 지금 있는 도시보다 기름값이 싼 도시에 도달하기 전까지 거리는 지금
		//도시에 있는 기름으로 가야한다는 점을 이용하면 문제를 쉽게 풀 수 있다.

		//현재 도시에서 다음 도시까지 현재 도시의 주유소를 이용해 기름을 충전해간다.
		money += distanceinfo[startpoint] * oilprice[startpoint];

		//이 도시의 기름값보다 기름값이 싼 도시에 도달할 때까지 거리는 이 주유소에서
		//구매한 기름으로 간다.
		while(oilprice[startpoint] <= oilprice[nextpoint]) {
			money += distanceinfo[nextpoint] * oilprice[startpoint];
			nextpoint += 1;
			//printf("money %d, nextpoint: %d\n", money, nextpoint);
			// 만약 도시에 끝에 도달했으면 돈의 최솟값 반환
			if (nextpoint >= endpoint )
				return money;
		}
		
		//이 도시의 기름값보다 기름값이 싼 도시에 도달하면 시작점을 그 점으로 바꾼다
		startpoint = nextpoint;
		//그리고 그 점을 이용해 다음 도시 정보도 초기화한다.
		nextpoint = startpoint + 1;
	}

	
	return money;
}