#pragma once
#include<iostream>

using namespace std;

class Counter
{

private:
	int its_val;
public:
	Counter();
	Counter(int inital_value);
	~Counter() {};
	int Get_Its_Val() const { return its_val; }
	void Set_Its_Val(int x) { its_val = x; }
	const Counter& operator++();
	//이 앞에 있는 인자 int을 통해서 후위 증가인지 전위 증가인지를 구분한다
	const Counter operator++(int);
	Counter operator+(const Counter& rhs);

};
