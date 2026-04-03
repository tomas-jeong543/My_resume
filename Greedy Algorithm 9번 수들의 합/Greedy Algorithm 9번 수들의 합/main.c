/*문제
서로 다른 N개의 자연수의 합이 S라고 한다. S를 알 때, 자연수 N의 최댓값은 얼마일까?

입력
첫째 줄에 자연수 S(1 ≤ S ≤ 4,294,967,295)가 주어진다.

출력
첫째 줄에 자연수 N의 최댓값을 출력한다.*/
//매우 쉬운 알고리즘 문제
#include<stdio.h>
int main(void) {

	int N;
	printf("자연수 N입력:");
	scanf_s("%d", &N);
	int i = 1;
	int numcount = 0;


	while (N > 0) {
		if (N > 2 * i + 1) {
			N -= i;
			numcount += 1;
			i += 1;
		}
		else {
			numcount += 1;
			break;
		}
			
	 }

	printf("최대 갯수: %d\n", numcount);
}