#pragma once

#include<iostream>
using namespace std;

class Counter
{
private:
	int its_val;
public:
	Counter() :
		its_val(0)
	{}

	/*/Counter(int val)
	{
		its_val = val;
	}*/

	~Counter() {}
	int Get_Its_Val() const { return its_val; }
	void Set_Its_Val(int x) { its_val = x; }
	void Incresement() { ++its_val; }
	//반환되는 Counter객체는 반드시 상수여야 한다 만약 그렇지 않다면 반환된 객체에 대해 변경을 가할 수 있는 프로세스 수행이 가능하다
	const Counter& operator++()
	{
		++its_val;
		return *this;
	}
	/*Counter operator++()
	{
		
		Counter 객페의 최대 크기를 초과할 경우를 대비해서 임시 객체를 만들어 이를 반환한다
		++its_val;
		Counter temp;
		temp.Set_Its_Val(its_val);
		return temp;
		
		
		
		//이름 없는 임시 객체를 반환하는 방법
		++its_val;
		return Counter(its_val);
		//이 프로그램은 더 효과적이지만 문제는임시 객체가 생성과 소멸되어야 하는데 그 만큼 비용이 소요된다 따라서 이 문제는 다음에 해결할 것이다
	
	}*/



};