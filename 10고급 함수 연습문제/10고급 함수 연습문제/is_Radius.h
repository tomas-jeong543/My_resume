#pragma once
#include<iostream>
class is_Radius
{
private:
	int * radius;
public:
	//생성자
	is_Radius();
	is_Radius(int r);
	//소멸자
	~is_Radius();
	//복사 생성자
	is_Radius(const is_Radius &);
	//반지름 설정 및 반지름 반환하는 맴버 함수
	void Set_Radius(int x) { *radius = x; }
	int Get_Radius()const {return *radius;}
	//오버로드 함수들

	//전위 증가 참조자로 반환하는 이유는 자기 자신을 반환하기 때문이다
	const is_Radius & operator++();
	//후위 증가 복사에 의해 반환하는 이유는 자기 자신을 그대로 반환하기 위해서다
	//그리고 난 후 자기 자신의 반지름을 1 증가 시키는 후위 증가를 구현하기 위해서다
	const is_Radius operator++(int);
	//대입 연산자
	is_Radius& operator = (is_Radius&);
};
