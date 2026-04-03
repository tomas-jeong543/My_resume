#include<iostream>

class Cat
{
private:
	//맴버 변수가 포인터인 경우 객체 소멸자 생성시 경우에 따라 메모리 누수 방지를 위해서 메모리를 해제해야 될 필요가 있다
	int* its_age;
	int* its_weight;
public:
	Cat();
	~Cat();
	int Get_Age() const { return *its_age; }
	int Get_Weight() const { return *its_weight; }
	void Set_Age(int age) { *its_age = age; }
	void Set_Weight(int weight) { *its_weight = weight; }
};

