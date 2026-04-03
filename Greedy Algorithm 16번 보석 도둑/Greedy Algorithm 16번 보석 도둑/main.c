/*문제
세계적인 도둑 상덕이는 보석점을 털기로 결심했다.

상덕이가 털 보석점에는 보석이 총 N개 있다. 각 보석은 무게 Mi와 가격 Vi를 가지고 있다. 상덕이는 가방을 K개 가지고 있고,
각 가방에 담을 수 있는 최대 무게는 Ci이다. 가방에는 최대 한 개의 보석만 넣을 수 있다.

상덕이가 훔칠 수 있는 보석의 최대 가격을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 주어진다. (1 ≤ N, K ≤ 300,000)

다음 N개 줄에는 각 보석의 정보 Mi와 Vi가 주어진다. (0 ≤ Mi, Vi ≤ 1,000,000)

다음 K개 줄에는 가방에 담을 수 있는 최대 무게 Ci가 주어진다. (1 ≤ Ci ≤ 100,000,000)

모든 숫자는 양의 정수이다.

출력
첫째 줄에 상덕이가 훔칠 수 있는 보석 가격의 합의 최댓값을 출력한다.*/
#include"jewery.h"
#include"func.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
// 상당히 난이도가 있는 문제로 보걱과 가방을 구조체로 나타내야 하는데 처음에 여기에서 실수해 가방의 구조체  변수를
//선언하지 않아 변수 종류가 많아서 힘들었다 알고리즘 파트 역시 쉽지 않은데 보석을 가격이 높은 순으로 정렬하고 그 순서대로
//가방에 담을 수 있는지 여부를 판단해 보석과 가방의 무게 차가 0에가장 가까운 음수가 나오는 가방을 골라야 하는데 생각보다
//구현하는 것이 까다롭고 가방과 보석 둘다 중복 사용 방지를 위해 bool형 변수를 선언해 사용여부를 확인 및 갱신해야
//한다. 또한 보석의 개수가 가방의 수가 많을 때 가방이 가득차면 break문을 이용해 나가야 되는데 이를 위해선 가방이 가득 찾는지
//여부를 확인하는 함수도 필요하다.
int main(void)
{

	//필요 변수 선언 보석 나타내는 구조체,가방 담을 수 있는 무게와 가방 사용 여부 나타내는 포인터 보석 가방 개수
	//훔친돈의 총합 등이 있다.
	Jewery* jew;
	int K, N, bagidx, stealmoneysum = 0;
	int* baginfo;
	bool* bagdet;
	
	//입력
	printf("보석 수, 가방 수 입력:");
	scanf_s("%d %d", &N, &K);
	//입력 정보를 이용한 동적 메모리 할당
	jew = (Jewery*)malloc(sizeof(Jewery) * N);
	baginfo = (int*)malloc(sizeof(int) * K);
	bagdet = (bool*)malloc(sizeof(bool) * K);
	//오류 발생시 예외처리
	if (jew == NULL || baginfo == NULL || bagdet == NULL) {
		puts("오류 발생 1");
		return -1;
	}

	//입력
	for (int i = 0; i < N; i++) {
		printf("보석 무게 가격을 공백을 두고 입력:");
		scanf_s("%d %d", &(jew + i)->weight, &(jew + i)->price);
		(jew + i)->stolen = false;
	}
	//보석을 가격이 높은 순으로 정렬
	SortedByprice(jew, N);

	//입력
	for (int i = 0; i < K; i++) {
		printf("가방에 담을 수 있는 무게 입력:");
		scanf_s("%d", &*(baginfo + i));
		*(bagdet + i) = false;
	}

	// 모든 보석의 개수 만큼 반복
	for (int i = 0; i < N; i++) {
		//만약 보석을 훔치지 않았고 보석을 담을 수 있는 가방이 있다면	
		if (Find_Min_Weight_To_Carry_Jew(*(jew + i), N, K, baginfo) != -1 && (jew + i)->stolen == false) {
				//보석을 담을 보석과 무게차이가 가장 적은 가방의 인덱스 정보 얻음
				bagidx = Find_Min_Weight_To_Carry_Jew(*(jew + i), N, K, baginfo);
				//가방을 사용하지 않았다면
				if (bagdet[bagidx] == false) {
					//훔친 액수 갱신 보석과 가방 상태 정보 갱신
					stealmoneysum += (jew + i)->price;
					bagdet[bagidx] = true;
					(jew + i)->stolen = true;
				}
			}
			//가방이 가득 찾다면 for문 탈ㄹ출
			if (DetFull(bagdet, K))
				break;
		}
	//출력
	printf("steal Max MOney: %d\n", stealmoneysum);

	return 0;
	//메모리 할당 해제
	free(jew);
	free(baginfo);
	free(bagdet);
}