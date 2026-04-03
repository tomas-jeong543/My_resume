#include"Cat.h"

int main()
{
	std::cout << "Simple Cat Frisky.. \n";
	Cat Frisky;
	std::cout << "SimpleCat * pRags = new SimpleCat... \n";
	Cat* pRags = new Cat;
	std::cout << "delete rPages... \n";
	delete pRags;
	std::cout << "Exciting watch Frisky go ...\n";
	//함수 종료시에 frisky객체 역시 소멸자를 호출해 소멸한다
	return 0;
}