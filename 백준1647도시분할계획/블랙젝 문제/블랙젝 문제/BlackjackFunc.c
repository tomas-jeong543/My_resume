#include<stdbool.h> 
// 배열과 배열의 크기를 인자로 받아 오름차순으로 정리하는 함수
int* SortByNum(int* org, int size)
{
	
	int temp = 0;

	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			if (org[i] > org[j]) {
				temp = org[i];
				org[i] = org[j];
				org[j] = temp;
			}
		}
	}

	return org;

}

// 딜러가 제시한 숫자 n 이하이면서 세 수의 합이 n에 가장 가까운 세 숫자를 구하고 포인터를 이용해 저장
void FindBlackJackNUm(int * cardinfo, int* card1, int* card2, int* card3, int N, int Cardnum) 
{
	// 세 수의 총합을 저장할 변수 선언
	int maxsum = 0;
	// 세 수의 인덱스 정보 저장할 배열 선언
	int maxidx[3] = { 0,1,2 }; 

	//모든 수 비교해 가장 합이 M보다 작은 서로 다른 수 중에서 큰 세 수의 합과 인덱스 정보 저장
	for (int i = 0; i < Cardnum; i++) {
		for (int j = 0;j < Cardnum; j++) {
			for (int k = 0; k < Cardnum; k++) {
				if (i != j && i != k && j != k) {
					if (cardinfo[i] + cardinfo[j] + cardinfo[k] > maxsum && 
						cardinfo[i] + cardinfo[j] + cardinfo[k] <= N) {
						maxsum = cardinfo[i] + cardinfo[j] + cardinfo[k];
						maxidx[0] = i;
						maxidx[1] = j;
						maxidx[2] = k;
					}
				}
			}
		}
	}

	*card1 = cardinfo[maxidx[0]];
	*card2 = cardinfo[maxidx[1]];
	*card3 = cardinfo[maxidx[2]];
}