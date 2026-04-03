#include"Cat.h"

Cat::Cat()
{
	its_age = new int;
	its_weight = new int;
	*its_age = 5;
	*its_weight = 9;
}

Cat& Cat::operator = (const Cat & rhs)
{
	if (this == &rhs)
		return *this;

	*its_age = rhs.Get_Age();
	*its_weight = rhs.Get_Weight();
	return *this;
}
//소멸자로 메모리 할당 해제
Cat::~Cat()
{
	delete its_age;
	its_age = 0;
	delete its_weight;
	its_weight = 0;
}

//복사 생성자로 새로운 공간에 메오리를 할당하고 그 공간에 복사할 값을 넣어주는 방식으로 하는 깊은 복사
Cat::Cat(const Cat& rhs)
{
	its_age = new int;
	its_weight = new int;
	*its_age = rhs.Get_Age();
	*its_weight = rhs.Get_Weight();
}