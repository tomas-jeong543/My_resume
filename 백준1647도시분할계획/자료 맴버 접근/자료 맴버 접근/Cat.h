#include<iostream>

class Cat {

private:
	int its_Age;
public:
	Cat() { its_Age = 2; }
	~Cat() {}
	int Get_Age() const { return its_Age; }
	void Set_Age(int age) { its_Age = age; }
};