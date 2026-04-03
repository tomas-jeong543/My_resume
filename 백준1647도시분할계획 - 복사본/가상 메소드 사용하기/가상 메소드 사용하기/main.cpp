#include"Dog.h"
//가상 메소드를 이용하면 부기본 클래스 포인터를 이용해 파생된 클래스의 재생 함수를 호출하는 것이 가능하다

int main()
{
	//pDog가 mammal이라는 점을 알기 때문에 
	Mammal* pDog = new Dog;
	//move를 찾을 때 mammal 내 함수를 찾는다
	pDog->Move();
	//	//move를 찾을 때 mammal 내 함수를 찾는다 하지만 speak가 가상 함수이기 때문에 그것에서 파생된 클래스인 Dog의 함수 speak를 호출한다
	pDog->Speak();
	return 0;
}