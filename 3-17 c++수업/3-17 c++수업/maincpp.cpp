#include<iostream>
#include<ctime>
using namespace std;

void ex01()
{
	constexpr int SIZE = 5;
	const char tab = '\t';
	int grade[SIZE]{};
	cout << grade << tab << &grade[0] << endl;
	int j = 0;

	for (auto& i : grade) {
		i = j + 10;
		j += 10;
		cout<< i  << '\t';
	}
	cout << endl;
}

void ex03()
{
	constexpr int  SIZE = 10;
	int num[SIZE];
	//타입 캐스팅 필요 우리가 자주 사용하던 명시적 형 변환은 static_cast<자료형> 으로 한다
	srand(static_cast<unsigned int>(time(NULL)));

	cout << "------------------" << endl;
	cout << "------------------" << endl;
	cout << "인덱스 값" << endl;
	cout << "------------------" << endl;
	cout << "------------------" << endl;
	int j = 0;
	for (auto& i : num) {

		int num = rand() % 100;
		i = num;
		cout << j << "\t" << num << endl;
		j++;
	}
}

int main()
{
	ex03();
	return 0;
}