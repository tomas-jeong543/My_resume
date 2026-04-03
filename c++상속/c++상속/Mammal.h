#pragma once
#include<iostream>
using namespace std;
enum BREED {GOLDEN, CAIRN, DANDIE , SHETLAND, DOBERMAN, LAB};

class Mammal
{

protected:
	int its_age;
	int its_weight;

public:
	Mammal();
	Mammal(int age);
	//파생 클래스의 생성자 중첩
	~Mammal();

	int Get_Age() const  { return its_age; } ;
	void Set_Age(int x) { its_age = x;  }
	int Get_Weight() const { return its_weight; };
	void Set_Weight(int x) { its_weight = x; };
	
	void Speak() const { cout << "Mammal Sound\n"; }
	void Sleep() const { cout << "shh, I'm sleeping. \n"; }

};