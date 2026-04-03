
// 순차 정렬 함수로 시간을 오름차순으로 정렬해 정렬한 배열을 포인터 형태를 이용해 반환한다.
int* SortTime(int* PerTime, int pernum)
{
	int temp;

	for (int i = 0; i < pernum; i++) {
		for (int j = i; j < pernum; j++) {
			if (PerTime[i] > PerTime[j]) {
				temp = PerTime[i];
				PerTime[i] = PerTime[j];
				PerTime[j] = temp;
			}
					
		}
	}

	return PerTime;
}


// 오름차순으로 정렬된 시간배열 정보를 이용해 그 순대로 ATM을 사용했을 때
//걸리는 시간을 구한다. 이 때 구한 시간의 합이 모든 사람이 ATM사용 시 걸리는 시간의 경우 중 가장 작은 경우이다.
int Get_TimeSum(int* Sorted_Pertime, int pernum)
{
	int timesum = 0;

	for (int i = 0; i < pernum; i++) {
		timesum += ((pernum - i) * Sorted_Pertime[i]);
	}

	return timesum;
}