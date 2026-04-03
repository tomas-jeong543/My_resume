/*#include<stdio.h>

int main(void) {
	
	//배열과 90도 돌린 배열을 복사할 배열 선언
	int arr[4][4] = {
		{ 1,2,3,4},
		{ 5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};

	int arrcopy[4][4] = {
		{ 1,2,3,4},
		{ 5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};

	// 배열을 오른쪽으로 90도씩 4번 돌린다.
	for (int k = 0; k < 3; k++) {
		
		//기존 배열 출력
		printf("기존 arr배열\n");

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				printf("%2d ", arr[i][j]);
			}
			printf("\n");
		}

		//배열을 90도 돌리는 과정
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				arrcopy[j][3 - i] = arr[i][j];
			}
		}
		//90도 돌린것을 복사본에서 원본으로 이동시키는 과정
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				arr[i][j] = arrcopy[i][j];
			}
		}
		// 변화된 배열 출력
		printf("\n90도 오른쪽으로 돌린 arr배열\n");

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				printf("%2d ", arr[i][j]);
			}
			printf("\n");
		}

		printf("\n");
	}

	return 0;
}*/