#pragma once
#include<iostream>
class Cat
{
private:
	int* its_age;
	int* its_weight;

public:
	Cat();
	//복사 생성자 주로 앞에 상수형으로 선언하는 것이 좋다
	Cat(const Cat&);
	~Cat();

	int Get_Age() const { return *its_age; }
	int Get_Weight() const{ return *its_weight; }
	void Set_Age(int age) { *its_age = age; }
	void Set_Weight(int weight) { *its_weight = weight; }
};