#include"jewery.h"
#include<stdio.h>
#include<stdbool.h>
#include"func.h"
//보석 가격을 높은 순서대로 정렬하는 함수
void SortedByprice(Jewery * jew, int size)
{
	Jewery temp;

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if ((jew + i)->price < (jew + j)->price) {
				temp = *(jew + i);
				*(jew + i) = *(jew + j);
				*(jew + j) = temp;
			}
		}
	}
}
// 보석을 담을 수 있는지를 파악해 담을 수 없으면 -1반환하고 아니면 가장 보석과 무게 차이가 나지 않는 가방의 인덱스 정보 반환하는 함수
int Find_Min_Weight_To_Carry_Jew(Jewery  jew, int jewsize, int bagsize, int * baginfo)
{
	//인덱스 정보와 그 때 가방과 보석의 무게차 정보 선언 및 초기화
	int idx = -1;
	int min = -1;

		//가방의ㅣ 개수 동안 반복
		for (int j = 0; j < bagsize; j++) {
			
			//가방에 보석을 담을 수 있으면
			if (jew.weight <= baginfo[j]) {
				// 이미 다른 가방에 담아져 있으면
				if (min >= 0 && baginfo[j] - jew.weight <= min) {
					//그 가방보다 담을 수 있는 무게가 적으면 가방 선택
					min = baginfo[j] - jew.weight;
					idx = j;
				}//다른 가방에 담겨 있지 않으면 가방 선택
				else if (min < 0) {
					min = baginfo[j] - jew.weight;
					idx = j;
				}
			}
		}

	//담을 수 있는 가방이 있으면 가방의 인덱스 정보 반환
	if (min != -1 && idx != -1)
		return idx;
	else//담을 수 있는 가방이 없으면 -1반환
		return -1;
}

//가방이 가득차 있으면 true아니면 false반환하는 함수
bool DetFull(bool * info, int size)
{
	for (int i = 0; i < size; i++) {
		if (info[i] == false)
			return false;
	}


	return true;
}
