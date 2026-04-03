#include"Counter.h"

Counter::Counter():
	its_val(0)
{ }

Counter::Counter(int inital_value):
	its_val(inital_value)
{}

const Counter& Counter::operator++()
{
	++its_val;
	return *this;
}

const Counter Counter::operator++(int theFlag)
{
	Counter temp(*this);
	++its_val;
	return temp;
}

//더하기 계산을 하는 방법 상수형 참조자를 이용한다
Counter Counter::operator+(const Counter& rhs)
{
	return Counter(its_val + rhs.Get_Its_Val());
}