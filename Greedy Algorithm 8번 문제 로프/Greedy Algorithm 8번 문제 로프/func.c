//내림차순 정렬 함수
int* Sortedlower(int* arr, int size)
{
	int temp;

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i] < arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	return arr;
}
//가장 많은 무게를 감당 가능한 로프부터 시작해서 그 다음 많은 무게를 감당 가능한
//로프를 추가할 때마다 감당 가능한 최대 무게를 구하는 함수
int* Find_MaxWeight(int * ropeinfo, int * weightinfo, int size)
{
	//가장 무거운 무게 감당 가능한 로프부터 시작해 가장 낮은 무게 감당 가능한
	//로프를 하니씩 추가함으로써 그 때마다 감당 가능한 무게의 총합을 구한다.
	// 그 무게는 로프 중 가장 작은 무게를 감당하는 로프가 감당하는 무게 * 로프의 개수이다.
	for (int i = 0; i < size; i++) {
		weightinfo[i] = (i + 1) * ropeinfo[i];
	}

	return weightinfo;
}