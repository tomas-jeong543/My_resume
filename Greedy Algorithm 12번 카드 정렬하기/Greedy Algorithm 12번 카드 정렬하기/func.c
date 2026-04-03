#include<stdio.h>
//카드 묶음에 있는 카드 수를 기준으로 오름차순으로 정렬하는 함수
void SortUpper(int * arr, int size)
{
	int temp;

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[i]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
//오름차순 정렬된 배열과 배열의 크기를 이용해 카드 정렬을 위한 비교횟수의 최솟값을 계산하는 함수
int Cal_Min_Comp_time(int *sortedcardinfo, int size )
{
	//비교숫자를 가장 작은 두 묶음의 카드 개수의 합으로 초기화 
	int comptime = sortedcardinfo[0] + sortedcardinfo[1];
	
	// 나머지 카드 묶음과 병합해 가면서 비교횟수를 갱신한다.
	for (int i = 2; i < size; i++) {
		comptime = (comptime * 2) + sortedcardinfo[i];
	}

	return comptime;
}