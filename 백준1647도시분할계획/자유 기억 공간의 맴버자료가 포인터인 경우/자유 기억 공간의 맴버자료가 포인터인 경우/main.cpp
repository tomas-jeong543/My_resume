#include"Cat.h"
//new에 대한 개념 정리 자유 기억 공간에 메모리를 할당하는 과정으로 자료형을 적으면 그 만큼의 메모리를 할당한다
//예를 들면 unsigned short int* numptr = new unsigned short int(5)는 자유 기억 공간에 4바이트의 메모리를 할당하고 
//그 공간을 포인터가 가리키도록하며 그 공간에 5라는 값을 저장하라는 의미를 가진다
int main()
{
	Cat* Frisky = new Cat;
	std::cout << "Frisky is a cat who is " << Frisky->Get_Age() << " years old\n";
	Frisky->Set_Age(5);
	std::cout << "Frisky is a cat who is " << Frisky->Get_Age() << "years old\n";
	delete Frisky;
	return 0;
}