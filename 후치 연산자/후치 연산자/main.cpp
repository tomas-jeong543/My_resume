#include"Counter.h"

/*
* 연산자 중첩에 있어서 중요한 사항 클래스 맴버가 되어야 하는 연산자는 =대입 연산자 첨자 연산자[] 함수 호출() 간접 지정 연산자-> 등이 있다
	연산자 중첩의 한계는 내장이 된 형 예를 들어 정수형에 대한 연산자는 중첩이 불가능하며 우선 순위는 바뀔 수가 없고 항의 개수를 단항에서 다항으로 이항에서 단항으로
	바꿀 수도 새로운 연산자를 만들 수도 없다  유일한 삼 항 연산자 (a > b ? x : y)와 같이 쓰인다
*/

/*
* 주의점 프로그램을 깔금하게 할 때에만 연산자를 중첩시킨다 중첩된 연산자에서는 클래스의 객체를 반환한다 
* 하지 말아야 할 껏 직관적으로 연산자를 마구 중첩시키지 말자
*/

int main()
{

	/*/Counter i;
	cout << "the value of i is " << i.Get_Its_Val() << "\n";
	i++;
	cout << "the value of i is " << i.Get_Its_Val() << "\n";
	++i;
	cout << "the value of i is " << i.Get_Its_Val() << "\n";
	Counter a = ++i;
	cout << "the value of i is " << i.Get_Its_Val() << " ";
	cout << "the value of a is " << a.Get_Its_Val() << "\n";
	//후위 증가를 통해서 i는 증가하지 않은 상태로 a에 값을 대입하고 그 후에 증가한다
	a = i++;
	cout << "the value of i is " << i.Get_Its_Val() << " ";
	cout << "the value of a is " << a.Get_Its_Val() << "\n";*/


	Counter var_one(2), var_two(4), var_three;
	//+ 역시 operator을 이용해 클래스로 나타내질 수 있다
	var_three = var_one + var_two;

	cout << "var_one: " << var_one.Get_Its_Val() << "\n";
	cout << "var_two: " << var_two.Get_Its_Val() << "\n";
	cout << "var_three: " << var_three.Get_Its_Val() << "\n";
	return 0;
}