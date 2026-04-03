#include<iostream>
using namespace std;


int Hanoi_Tower(int n)
{
	//base즉 재귀 종료 조건
	if (n == 1) { return 1; }
	//재귀
	return 2 * Hanoi_Tower(n - 1) + 1;
}

int main()
{
	//사실 이문제는 굳이 재귀로 풀 필요는 없다 왜냐하면 공식이 존재하기 때문인데 공식은 원판의 개수를n개라 할 때 (2 ** n ) -1이다
	//하지만 재귀로도 풀어 보았다
	int babel_num;
	cout << "하노이 타워의 원판 갯수를 입력하시오:";
	cin >> babel_num;
	if (babel_num < 1) {
		cout << "원판의 수는 적어도 하나 이상이어야 합니다";

		return -1;
	}
	
	cout << "원판을 다 옮기는 경우 필요한 이동횟수는 " << Hanoi_Tower(babel_num) << "입니다" << endl;
	return 0;
}