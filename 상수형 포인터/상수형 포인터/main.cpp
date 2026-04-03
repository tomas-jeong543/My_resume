#include"Cat.h"

/*
* 참조자와 포인터를 사용하는 경우 처음 어떤 객체를 가르키고 다른 객체를 가르키기 위해서는 포인터를 사용해야 한다
* 더 나아가 널 값이 나올 수 있는 경우에는 예방적 조치를 취하거나 아니면 참조자를 사용하면 안된다
* 또 new연산자를 이용하는 경우에는 메모리 사용해 참조자를 초기화 할 때에는 그 메모리가 널인지 아닌지를 먼저 확인해야 한다 
* 
*/

const Cat* const Function_Two(const Cat* const theCat)
{
	cout << "Function two Returning ... \n";
	cout << "Frisky is now " << theCat->Get_Age();
	cout << "Years old \n";
	// theCat->Set_Age(8); const!
	return theCat;
}

//이 방식에서는 포인터를 사용했지만 사실은 참조자를 이용하는 것이 조금 더 바람직하다
int main()
{
	cout << "Making a cat ... \n";
	Cat Frisky;
	cout << "Frisky is ";
	cout << Frisky.Get_Age();
	cout << "years old \n";
	int age = 5;
	Frisky.Set_Age(age);
	cout << "Frisky is";
	cout << Frisky.Get_Age();
	cout << "years old \n";
	cout << "Calling Function_Two ... \n";
	//비상수형 객체가 함수로 전달되었지만 function_two의 선언이 포인터를 상수형 객체에 대한 포인터로 선언하엿음으로 객체는 상수형처럼 취급된다
	Function_Two(&Frisky);
	cout << "Frisky is ";
	cout << Frisky.Get_Age();
	cout << "years old\n";
	 
	//참조자에 메모리 할당하는 방법 널 값인지를 확인해야 한다
	int* pInt = new int;
	if (pInt != nullptr)
		int& Int = *pInt;
	delete pInt;
	return 0;
}