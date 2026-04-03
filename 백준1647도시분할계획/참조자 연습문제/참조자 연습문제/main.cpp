#include<iostream>
using namespace std;

void problem1()
{
	int n = 5;
	int* nptr = &n;
	int& rn = n;

	cout << "n: " << n << "\n";
	rn = 7;
	cout << "n: " << n << "\n";
	*nptr = 8;
	cout << "n: " << n << "\n";
}

void problem2()
{
	int varOne;
	const int * const ptr = &varOne;
	varOne = 6;

	//상수형 정수에 대한 포인터임으로 그 값도 변경 불가능하다
	//*ptr = 7;
	int varTwo = 10;
	//정수에 대한 상수형 포인터는 ptr은 다른 주소를 가르킬 수는 없다
	//ptr = &varTwo;
}

void problem3()
{
	int* ptr = new int(7);
	cout << *ptr << endl;
	int num2 = 5;
	//메모리는 할당 해제 되었지만 포인터는 삭제되지 않았기 때문에 포인터의 실종이 발생
	//이 상태에서 해결을 안하고 넘어가 포인터가 가르키는 값을 이용하면 심각한 오류를 발생시킬 수 있다
	delete ptr;
	//해결
	ptr = nullptr;
	ptr = &num2;
	// 이용
	*ptr = num2;
	cout << *ptr << endl;

}

int problem4()
{
	//이런 식으로 공간을 할당하고 삭제하지 않고 그 안에 있는 값을 전달하면 메모리 누출이 일어난다
	int* ptr = new int(10);
	//해결 값에 의한 전달이 가능함으로 정수형 변수에 값을 담아 복사 방식으로 전달하고 메모리 공간은 delete함수를 이용해 삭제한다 
	//또한 포인터 역시 nullptr값으로 초기화해 놓는다
	int num = *ptr;
	delete ptr;
	ptr = nullptr;

	return num;
}

int main()
{
	cout << problem4() << "\n";


	return 0;
}