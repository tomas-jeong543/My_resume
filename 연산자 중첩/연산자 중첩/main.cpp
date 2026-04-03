#include"Counter.h"

int main()
{
	Counter i;
	//더 나아간 생각 counter이 최대 크기를 초과할 경우에는 증가연산자가 잘못 사용되는 경우에는 치면적 오류 발생
	//ex Counter a = ++i 이 코드는 새로운 COunter a을 만든 후에 증가된 i값을 대입하려 하는데 내장된 복사 생성자가 대입을 처리해야 하지만
	// 현재의 증가 연산자는 counter객체를 반환하지 않고 void형을 반환한다 이러한 void객체를 Counter객체에 대입할 수 없다;
	cout << "The value of i is " << i.Get_Its_Val() << endl;
	i.Incresement();
	cout << "The value of i is " << i.Get_Its_Val() << endl;
	++i;
	cout << "the Value of i is " << i.Get_Its_Val() << endl;
	Counter a = ++i;
	cout << "the value of a is " << a.Get_Its_Val() << endl;
	cout << "the Value of i is " << i.Get_Its_Val() << endl;
	return 0;

}