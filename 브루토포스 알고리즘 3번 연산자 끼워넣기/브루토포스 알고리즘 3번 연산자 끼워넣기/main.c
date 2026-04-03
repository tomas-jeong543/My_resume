/*문제
N개의 수로 이루어진 수열 A1, A2, ..., AN이 주어진다. 또, 수와 수 사이에 끼워넣을 수 있는 N-1개의 연산자가 주어진다. 연산자는 덧셈(+), 뺄셈(-),
곱셈(×), 나눗셈(÷)으로만 이루어져 있다.

우리는 수와 수 사이에 연산자를 하나씩 넣어서, 수식을 하나 만들 수 있다. 이때, 주어진 수의 순서를 바꾸면 안 된다.

예를 들어, 6개의 수로 이루어진 수열이 1, 2, 3, 4, 5, 6이고,
주어진 연산자가 덧셈(+) 2개, 뺄셈(-) 1개, 곱셈(×) 1개, 나눗셈(÷) 1개인 경우에는 총 60가지의 식을 만들 수 있다. 
예를 들어, 아래와 같은 식을 만들 수 있다.

1+2+3-4×5÷6
1÷2+3+4-5×6
1+2÷3×4-5+6
1÷2×3-4+5+6
식의 계산은 연산자 우선 순위를 무시하고 앞에서부터 진행해야 한다. 또, 나눗셈은 정수 나눗셈으로 몫만 취한다. 
음수를 양수로 나눌 때는 C++14의 기준을 따른다. 즉, 양수로 바꾼 뒤 몫을 취하고, 그 몫을 음수로 바꾼 것과 같다. 
이에 따라서, 위의 식 4개의 결과를 계산해보면 아래와 같다.

1+2+3-4×5÷6 = 1
1÷2+3+4-5×6 = 12
1+2÷3×4-5+6 = 5
1÷2×3-4+5+6 = 7
N개의 수와 N-1개의 연산자가 주어졌을 때,

입력
첫째 줄에 수의 개수 N(2 ≤ N ≤ 11)가 주어진다. 둘째 줄에는 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 100) 
셋째 줄에는 합이 N-1인 4개의 정수가 주어지는데, 차례대로 덧셈(+)의 개수, 뺄셈(-)의 개수, 곱셈(×)의 개수, 나눗셈(÷)의 개수이다.

출력
첫째 줄에 만들 수 있는 식의 결과의 최댓값을, 둘째 줄에는 최솟값을 출력한다. 연산자를 어떻게 끼워넣어도 항상 -10억보다 크거나 같고,
10억보다 작거나 같은 결과가 나오는 입력만 주어진다. 
또한, 앞에서부터 계산했을 때, 중간에 계산되는 식의 결과도 항상 -10억보다 크거나 같고, 10억보다 작거나 같다.*/
#include<stdio.h>
#include<stdlib.h>
#include"simplecalfunc.h"
#include"func.h"
#include"min.h"
// 정답률에 비해 상당히 까다로운 문제 처음에는 모든 경우의 수를 찾으려고 했지만 실패했고 미련을 버리지 못해 계속 시도하다가
// 그냥 연산자에 대해 모든 경우에 대해 케이스 분류하는 것이 정신건강에 이롭다는 사실을 깨닫고 모든 경우에 대한 케이스 분류를 통해
//최대 최솟값을 구했다.
int main(void)
{
	// 숫자, 연산기호 정보, 연산기호 순서를 저장할 배열을 가르키는 포인터 선언
	int* numinfo, * calsymbolptr, *sequenceptr;
	//입력 받을 숫자의 수 최대 최솟값 저장할 변수, 그리고 연산기호 종류 개수 저장 변수 선언
	int	N, max, min, symbol_num = 0;
	// 연산시호를 저장할 배열과 그 배열의 복사본 배열 생성 및 초기화
	int calsymbol[4] = { 0,0,0,0 };
	int calsymbolcopy[4] = {0,0,0,0};
	// 연산할 순서를 정하는 배열 선언
	int cal_sequence[4] = { 0,1,2,3 };
	//포인터 초기화
	calsymbolptr = &calsymbolcopy;
	sequenceptr = &cal_sequence;
	
	//입력
	printf("수의 개수 입력:");
	scanf_s("%d", &N);
	
	//동적 메모리 할당
	numinfo = (int*)malloc(sizeof(int) * N);
	//예외 처리
	if (numinfo == NULL ) {
		puts("메모리 할당 중 오류 발생1");
		return -1;
	}


	//입력
	for (int i = 0; i < N; i++) {
		printf("숫자 입력:");
		scanf_s("%d", &numinfo[i]);
	}
	printf("연산 기호 +,-,*, / 순 입력:");
	scanf_s("%d %d %d %d", &calsymbol[0], &calsymbol[1], &calsymbol[2], &calsymbol[3]);
	
	//복사본에 원본내용을 넣어준다.
	for (int i = 0; i < 4; i++) {
		*(calsymbolcopy + i) = *(calsymbol + i);
	}

	//연산 기호의 종류의 개수를 구해 저장
	symbol_num = Findcalsymbolnum(calsymbolptr);

	// 최댓값을 구하는 함수를 이용해 연산의 최댓값 구함 이 과정에서 연산기호 정보의 복사본은 내용이 모두 0으로 
	// 초기화되기 때문에 다시 원본을 복사해준다.
	max = FindMax(numinfo, calsymbolptr, cal_sequence, N - 1, symbol_num);

	for (int i = 0; i < 4; i++) {
		*(calsymbolcopy + i) = *(calsymbol + i);
	}

	//최솟값을 찯는다.
	min = FindMin(numinfo, calsymbolptr, cal_sequence, N - 1, symbol_num);
	//출력
	printf("max: %d min: %d\n", max, min);

	//동적 메오리 할당 해제
	free(numinfo);
	return 0;
}