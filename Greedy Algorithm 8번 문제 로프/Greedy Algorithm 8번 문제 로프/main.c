/*문제
N(1 ≤ N ≤ 100,000)개의 로프가 있다. 이 로프를 이용하여 이런 저런 물체를 들어올릴 수 있다. 
각각의 로프는 그 굵기나 길이가 다르기 때문에 들 수 있는 물체의 중량이 서로 다를 수도 있다.

하지만 여러 개의 로프를 병렬로 연결하면 각각의 로프에 걸리는 중량을 나눌 수 있다.
k개의 로프를 사용하여 중량이 w인 물체를 들어올릴 때, 각각의 로프에는 모두 고르게 w/k 만큼의 중량이 걸리게 된다.

각 로프들에 대한 정보가 주어졌을 때, 이 로프들을 이용하여 들어올릴 수 있는 물체의 최대 중량을 구해내는 프로그램을 작성하시오. 
모든 로프를 사용해야 할 필요는 없으며, 임의로 몇 개의 로프를 골라서 사용해도 된다.

입력
첫째 줄에 정수 N이 주어진다. 다음 N개의 줄에는 각 로프가 버틸 수 있는 최대 중량이 주어진다. 이 값은 10,000을 넘지 않는 자연수이다.

출력
첫째 줄에 답을 출력한다.*/
#include"func.h"
#include<stdio.h>
#include<stdlib.h>
//이 문제는 복잡해 보이지만 간단하다. 로프가 들 수 있는 무게를 내림차순으로 정렬하고
//그 후에는 그 순서대로 로프를 추가해가며 그 경우마다 들 수 있는 무게의 값을 구하고 그
//중 가장 큰 값을 반환하면된다.
int main(void) {

	//로프 개수와 로프들을 이용해 들 수있는 최대 무게를 저장하는 변수 선언
	int ropenum, maxweight;
	// 로프가 들 수 있는 무게 저장하는 동적 메모리 할당할 포인터
	int* rope_weight_info;
	//로프의 개수에 따라 들 수 있는 최대 무게 정보를 저장하는  동적 메모리 할당할 포인터
	int* maxhold_weight_info;
	//로프의 개수 입력
	printf("로프의 개수N을 입력하시오:(1 ≤ N ≤ 100,000):");
	scanf_s("%d", &ropenum);
	//동적 메모리 할당
	rope_weight_info = (int*)malloc(sizeof(int) * ropenum);
	maxhold_weight_info = (int*)malloc(sizeof(int) * ropenum);
	//오류 점검
	if (rope_weight_info == NULL || maxhold_weight_info == NULL) {
		puts("동적 메모리 할당 중 오류 발생");
		return -1;
	}
	//로프별 들 수 있는 최재 무게 입력
	for (int i = 0; i < ropenum; i++) {
		printf("로프 %d가 들수 있는 최대무게를 입력: 단 최대무게는10,000을 넘지 않는 자연수", i + 1);
		scanf_s("%d", &*(rope_weight_info + i));
	}
	//그 무게를 기준으로 내림차순으로 정렬
	rope_weight_info = Sortedlower(rope_weight_info, ropenum);

	//초기화
	for (int i = 0; i < ropenum; i++) {
		*(maxhold_weight_info+ i) = 0;
	}

	//가장 많은 무게를 감당 가능한 로프부터 시작해서 그 다음 많은 무게를 감당 가능한
	//로프를 추가할 때마다 감당 가능한 최대 무게를 함수를 이용해 구함
	maxhold_weight_info = Find_MaxWeight(rope_weight_info, maxhold_weight_info, ropenum);

	//최댓값 초기화
	maxweight = maxhold_weight_info[0];
	//최댓값 얻는 과정
	for (int i = 1; i < ropenum; i++) {
		if (maxhold_weight_info[i] > maxweight) {
			maxweight = maxhold_weight_info[i];
		}
	}
	//결과 출력
	printf("로프가 들 수 있는 최대 무게: %d\n", maxweight);

	return 0;
	free(rope_weight_info);
	free(maxhold_weight_info);
}