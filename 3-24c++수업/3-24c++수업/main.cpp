#include"Memory_Leak_Cehck.h"
#include<iostream>
#include<ctime>
using namespace std;

void ex01()
{
	int arr[3][4];
	int (*ptr)[4] = arr;

	cout << typeid(arr).name() << endl; // &arr[0] 층의 시작 주소
	cout << typeid(*arr).name() << endl; // int[4] 
	cout << typeid(arr[0]).name() << endl;
	cout << typeid(*(arr + 0)).name() << endl; //int[4] &arr[0][0] 층의 시작 방의 주소 *(arr + 0)
	cout << typeid(*arr[0]).name() << endl; //int

}

void ex02()
{
	int row, col;

	cin >> row >> col;


	//가장 고차원에 해당하는 것만 포인터로 대체 가능
	int(*ptr1)[4] = new int[row][4];
	if (ptr1 == nullptr) { return; }

	for (int i = 0; i < row; i++) {
		delete[] * (ptr1 + i);
	}

	delete[] ptr1;
	ptr1 = nullptr;


	//하지만 이렇게 사용하면 둘 다 동적으로 할당 가능
	
	//1번 층의 주소값들을 저장하는 이중 포인터 사용
	int** ptr = new int* [row];
	if (ptr == nullptr) { return; }


	//각 층의 방들을 동적할당 한다
	for (int i = 0; i < col; i++){
		*(ptr + i) = new int[row];
		if (*(ptr + i) == nullptr) { return; }
	}

	cout << "sucess" << endl;

	for (int i = 0; i < row; i++) {
		delete[] *(ptr + i);
		ptr[i] = nullptr;
	}

	delete[] ptr;

	return;
}

int* makeArray(const int num) {
	int* arr = new int[num];

	//rand를 진짜 랜덤으로 만들기 위한 방법
	srand(static_cast<unsigned int>(time(NULL)));
	for (int i = 0; i < num; i++) {
		arr[i] = rand() % 100;
	}

	return arr;
}

void Showarray(int* (& array))
{
	//_msize로 heap여역에 할당된 데이터를 가져올 수 있다 
	int size = _msize(array) / sizeof(array[0]);
	for (int i = 0; i < size; i++) {
		cout << array[i] << '\t';
	}
	cout << endl;
}

//포인터 배열을 이용한 원래 배열의 변경 없는 배열의 정렬 후 출력
void sortedArray(int* (& score)) {


	//_msize함수는 c에서 사용되는 함수인데 유용함으로 기억하자 heap영역에 할당된 메모리의 관리를 한다
	int size = _msize(score) / sizeof(score[0]);
	
	int** pscore = new int *[size];
	
	for (int i = 0; i < size; i++) {
		pscore[i] = &score[i];
	}

	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (*pscore[i] < *pscore[j]) {
				int* tmp = nullptr;
				tmp = pscore[i];
				pscore[i] = pscore[j];
				pscore[j] = tmp;
			}
		}
	}

	for (int i = 0; i < size; i++) {
		cout << *pscore[i] << '\t';
	}
	cout << endl;

	delete[] pscore;
	pscore = nullptr;
}


void ex03()
{
	int * score = makeArray(10);
	Showarray(score);
	sortedArray(score);
	Showarray(score);
	
	delete[] score;
	score = nullptr;

	if (score == nullptr) {
		cout << "삭제 완료 \n";
	}
}




int main()
{
	//	메인에 한번만 실행하면된다

	/*세부 기능 설명 _CrtSetDbgFlag는
	애플리케이션이 종료될 때 메모리 누수 확인 및 발견된 경우 보고
	해제된 메모리 블록이 힙의 연결된 목록에 유지되도록 지정하여 메모리 부족 조건 시뮬레이션하며
	모든 할당 요청에서 각 메모리 블록을 검사하여 힙의 무결성을 확인합니다. 추가로 디버그 하는 경우에만 작동한다*/

	//_CRTDBG_ALLOC_MEM_DF는 힙에 할당된 메모리가 회수와 해제 정보를 가져오고 _CRTDBG_LEAK_CHECK_DF는  누수 검색 및 메모리 상태 차이을 힙 정보의 할당과 해제를 통해서 누수 정보를 알려주는 기능을한다
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//
	
	cout << "202211364 정명훈\n";
	ex03();
	return 0;
}

