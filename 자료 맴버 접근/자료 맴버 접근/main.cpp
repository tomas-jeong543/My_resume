#include<iostream>
#include"Cat.h"
int main()
{
	//포인터오 객체 생성
	Cat* Frisky = new Cat;
	//포인터로 객체를 접근항 때에는 간접 연산 지정자->를 이용한다
	std::cout << "Frisky is " << Frisky->Get_Age() << " years old \n";
	Frisky->Set_Age(5);
	std::cout << "Frisky is " << Frisky->Get_Age() << " years old\n";
	//삭제
	delete Frisky;
	return 0;
}