#include<stdio.h>
#include<stdlib.h>
//입력 버퍼를 비우는 함수
void RemoveLineBuf()
{
	while (getchar() != '\n');
}
//정수형 배열을 오름차순으로 정렳하는 함수
int* SortedUpper(int * arr, int size)
{
	int tmp;

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i] > arr[j]) {
				tmp = arr[i];
				arr[i] = arr[j];
			arr[j] = tmp;
			}
		}
	}

	return arr;
}

//오름차순으로 정렬된 배열과 기존 배열을 이용해 크기가 큰 순서대로 작은 인덱스를 부여하고 포인터에 저장
//해 이를 반환하는 함수
int* Ranknum(int * orginarr, int*sortedarr, int* rankarr, int size)
{
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			//만약 기존 배열의 값과 정렬된 배열의 값이 같으면
			if (orginarr[i] == sortedarr[j]) {
				//binfo배열에 정렬된 배열의 값의 인덱스 정보를 이용해 예를 들어 2번째로 작고 배열의 크기가 5이면
				//2를 binfo에 저장한다.
				rankarr[i] = size - 1 - j;
			}
		}
	}

	return rankarr;
}
// b의 위치에 따른 크기 정보와 A의 정보를 이용해 A값을 갱신하기
//위해 동적메오리를 할당하고 반환한다.
int* sortbyBinfo(int* binfo, int* a, int size)
{
	//동적 메모리 할당
	int *tmp = (int*)malloc(sizeof(int) * size);
	//오류 예외처리
	if (tmp == NULL) {
		puts("오류발생2");
		exit(1);
	}

	//binfo의 인덱스 정보를 이용해서 b의 정보가 클수록 곱해지는 a의 값을 작게한다.
	for (int i = 0; i < size; i++) {
		if(binfo[i] < size)
			tmp[i] = a[binfo[i]];
	}

	return tmp;

}