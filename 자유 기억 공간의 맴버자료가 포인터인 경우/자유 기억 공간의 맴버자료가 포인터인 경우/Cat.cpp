#include"Cat.h"

Cat:: Cat()
{
	its_age = new int(2);
	its_weight = new int(5);
}

Cat:: ~Cat()
{
	//메모리 해제 이를 통해 우리가 객체 안에 다른 객체를 가르키는 포인터가 있을 때 설계 과정에서 부터 언제까지 유지가 되어야 하는다
	//에 대한 이해가 필요하다 예를 들면 설계한 객체가 다른 객체를 참조하는 객체라면 이 객체는 참조하려는 객체보다 나중에 만들어져도 되지만
	//참조하려는 객체가 없어질 때까지 존재해야 한다
	delete its_age;
	delete its_weight;
}