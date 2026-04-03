#pragma once
#include<iostream>

using namespace std;

class Counter
{
private:
	int its_val;
public:
	Counter();
	//int를 counter 로 변환
	Counter(int val);
	~Counter() {}
	int Get_its_val() const { return its_val; }
	void Set_its_val(int x) { its_val = x; }
	//counter을 int로 변환
	operator unsigned short();
};