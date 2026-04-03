#include"Cat.h"

Cat::Cat()
{
	its_age = new int;
	its_weight = new int;
	*its_age = 5;
	*its_weight = 9;
}

Cat::Cat(const Cat & rhs)
{
	//복사 생성자 생성시 자유 기억 공간에 할당된 값을 복사하는 경우에는 새롭게 공간을 다시 할당한 후에 거기에 값을 집어 넣어애 한다
	its_age = new int;
	its_weight = new int;
	//범용 접근
	*its_age = rhs.Get_Age();
	//전용 접근
	*its_weight = *(rhs.its_weight);
}

Cat::~Cat()
{
	//객체 삭제 시 자유 기억 공간에 할당된 메모리 삭제 및 가르키는 포인터 값을 널로 설정해줌
	delete its_age;
	its_age = 0;
	delete its_weight;
	its_weight = 0;
}