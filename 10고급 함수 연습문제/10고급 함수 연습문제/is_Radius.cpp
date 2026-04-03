#include"is_Radius.h"
//생성자
is_Radius::is_Radius()
{
	radius = new int;
	*radius = 1;
}

is_Radius::is_Radius(int r) 
{
	radius = new int;
	*radius = r;
}
// 소멸자 메모리 할당 해제
is_Radius::~is_Radius()
{
	delete radius;
	radius = 0;
}
// 증가 연산자 전위 증가
const is_Radius & is_Radius::operator++()
{
	++(*radius);
	return *this;
}

//후위증가
const is_Radius  is_Radius::operator++(int num)
{
	is_Radius temp(*this);
	++(*radius);

	std::cout << "mys: " << this << std::endl;
	
	return temp;
}
//복사 생성자
is_Radius::is_Radius(const is_Radius& rhs)
{
	radius = new int;
	*radius = rhs.Get_Radius();
}
//대입 연산자
is_Radius & is_Radius::operator= (is_Radius & rhs)
{
	//자기 자신을 대입하는 경우
	if (&rhs == this)
		return *this;

	//아닌 경우
	*radius = rhs.Get_Radius();
	//둘 다 자기 자신을 반환한다
	return *this;
}