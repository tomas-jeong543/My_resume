#include"Counter.h"

Counter::Counter() :
	its_val(0)
{}

Counter:: Counter(int val):
	its_val(val)
{ }
//이 counter 객체를 양수short형으로 반환해 넘기는 함수
Counter::operator unsigned short()
{
	return (int(its_val));
}