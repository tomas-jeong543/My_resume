/*#include<stdio.h>

int main(void) {

	int vila[4][2];
	int popu, i, j;

	// 가구별 거주인원 받기

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%d층 %d호 인구수: ", i + 1, j + 1);
			scanf_s("%d", &vila[i][j]);
		}
	}

	// 빌라 층별 인구수 확인하기

	for (int i = 0; i < 4; i++) {

		popu = 0;
		popu += vila[i][0];
		popu += vila[i][1];
		printf("%d 층 인구수: %d \n", i + 1, popu);
	}

	return 0;
}*/