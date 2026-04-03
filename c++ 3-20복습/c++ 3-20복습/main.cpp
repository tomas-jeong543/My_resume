#include<iostream>
using namespace std;

void dynamic_memory()
{
	int* p1 = new int(5);
	cout << *p1 << " " << p1 << endl;
	delete p1;

	
	constexpr int ROW = 3;
	int** p2 = new int*[10];
	const char tab = '\t';

	for (int i = 0; i < 10; i++) {
		*(p2 + i) = new int[ROW];
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j <ROW; j++) {
			p2[i][j] = i * 3 + j;
			cout << p2[i][j] << tab;
		}
		cout << endl;
	}

	//2차원 배열의 메모리 할당 해제
	for (int i = 0; i < 10; i++) {
		delete[] * (p2 + i);
	}

	delete[] p2;
	p2 = NULL;
	//

}

int main()
{
	dynamic_memory();
	return 0;
}