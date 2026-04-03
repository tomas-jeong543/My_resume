#pragma once
#include"Mammal.h"

class Dog : public Mammal
{
private:
	BREED its_breed;

public:
	Dog() { cout << "Dog constructor ... \n"; }
	~Dog() { cout << "Dog distructor ... \n"; }

	void Wag_Tail() const { cout << "Tail Wagging ... \n"; }
	void Beg_For_Food() const { cout << "Begging for  food... \n"; }
	//함수 재생 부분 포유류의 메소드를 개의 클래스에 맞추어 변형시킴 그냥 한마디론 메소드 오버라이딩
	void Speak() const{cout << "Woof...\n"; }
};