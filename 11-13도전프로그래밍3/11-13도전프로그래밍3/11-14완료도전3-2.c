#include<stdio.h>
#include <string.h>
#include <stdlib.h>


void Right(int** arr, int size, int row, int col, int *count, int num);
void Left(int** arr, int size, int row, int col, int *count, int num);
void Up(int** arr, int size, int row, int col, int count, int num);
void Down(int** arr, int size, int row, int col, int count  ,int num);


int main(void) {

	/*배열의 크기 시작 숫자 그리고 2차원배열을 할당할 포인터, 입력횟수, 실행함수 개수, 행과 열 정보,
	횟수 가르키는 선언*/
	int size;
	int num = 1;
	int** arr;
	int count = 0;
	int functiontime;
	int row = 0, col = 0;
	int* Ptrcount = &count;

	//배열의 크기 입력
	printf("배열의 크기를 입력:");
	scanf_s("%d", &size);
	
	functiontime = (2 * size )- 1;
	count = size -1;

	//동적 메모리 할당을 통한 배열 생성
	arr = (int**)malloc(sizeof(int*) * size);

	for (int i = 0; i < size; i++) {
		arr[i] = (int*)malloc(sizeof(int) * size);
	}


	if (size == 1)
			arr[0][0] = 1;

	if (size >= 2) 
		for (int i = 1; i < functiontime + 2; i++) {

		

			/* n* n 배열에서 이동하는 횟수는 처음에는 n - 1번으로 3회 그 이후에는 2회씩 n - 2, n - 3...로 되기 때문에
				에  반복횟수가 4 초과시 2회 마다 1씩 빼준다.
			*/
			if (i > 4 && i % 2 == 0)
				count -= 1;

			printf("row: %d col: %d, count: %d\n", row, col, count);

			/* i 값에 따라 실행되는 함수를 변화시킨다.이에 따라 배열은 오른쪽 아래쪽, 위쪽, 왼쪽 순으로 반복해
			서 채워진다.*/ 

			switch (i % 4) {
			case(1): {

				Right(arr, size, row, col, Ptrcount, num);
				
				//함수 실행 후 변화된 행과 열 그리고 숫자 정보를 추가한다.
				num += count;
				col += count;
				break;
			}
			case(2): {

				Down(arr, size, row, col, count, num);
				
				//함수 실행 후 변화된 행과 열 그리고 숫자 정보를 추가한다.
				num += count;
				row += count;
				
				
				break;
			}
			case(3): {

				Left(arr, size, row, col, Ptrcount, num);
				
				//함수 실행 후 변화된 행과 열 그리고 숫자 정보를 추가한다.
				num += count;
				col -= count;
				
				// 처음으로  3회 도달시 이동횟수를 1 줄여준다.
				if(i == 3)
					count -= 1;
				
				break;
			}
			case(0): {

				Up(arr, size, row, col, count, num);
				
				//함수 실행 후 변화된 행과 열 그리고 숫자 정보를 추가한다.
				num += count;
				row -= count;
				break;
			}
		}

			printf("row: %d col: %d, count: %d, num: %d\n\n", row, col, count, num);

		}
	

	//배열 결과 출력
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			printf("%5d ", arr[i][j]);
		printf("\n\n");
	}

	//동적 메모리 할당 해제
	free(arr);

	return 0;
}


//오른쪽으로 숫자 입력하는 함수
void Right(int** arr, int size, int row, int col, int *count, int num) {
	//입력 숫자가 배열의 마지막 숫자인 경우 count가 1이여서 마지막 배열에 숫자가 더해지지 않아 반복횟수를 1추가함 
	if (num == size * size) {
		for (int i = 0; i < *count + 1; i++)
			arr[row][col++] = num++;

	}
	else{
		for (int i = 0; i < *count; i++)
			arr[row][col++] = num++;
	}

		

	
}
//왼쪽으로 숫자 입력하는 함수
void Left(int** arr, int size, int row, int col, int *count, int num) {
	//입력 숫자가 배열의 마지막 숫자인 경우 count가 1이여서 마지막 배열에 숫자가 더해지지 않아 반복횟수를 1추가함
	if (num == size * size) {
		for (int i = 0; i < *count + 1; i++)
			arr[row][col--] = num++;

	}
	else {
		for (int i = 0; i < *count; i++)
			arr[row][col--] = num++;
	}

	
}

//위쪽으로 숫자 입력하는 함수
void Up(int** arr, int size, int row, int col, int count, int num){
	//입력 숫자가 배열의 마지막 숫자인 경우 count가 1이여서 마지막 배열에 숫자가 더해지지 않아 반복횟수를 1추가함
	if (num == size * size) {
		for (int i = 0; i < count + 1; i++)
			arr[row--][col] = num++;

	}
	else {
		for (int i = 0; i < count; i++)
			arr[row--][col] = num++;
	}
}
//아래쪽으로 숫자 입력하는 함수
void Down(int** arr, int size, int row, int col, int count, int num) {
	//입력 숫자가 배열의 마지막 숫자인 경우 count가 1이여서 마지막 배열에 숫자가 더해지지 않아 반복횟수를 1추가함
	if (num == size * size) {
		for (int i = 0; i < count + 1; i++)
			arr[row++][col] = num++;

	}
	else {
		for (int i = 0; i < count; i++)
			arr[row++][col] = num++;
	}

}