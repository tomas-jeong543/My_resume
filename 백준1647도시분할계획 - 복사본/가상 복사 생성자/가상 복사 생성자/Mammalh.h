#pragma once
#include<iostream>
using namespace std;

//가상 함수는 단지 포인터와 참조자를 사용해 가능하다
//또힌 가상 함수는 가상 함수 테이블로 관리가 되는데 이 경우에는 Mammal * pdog = new Dog인 경우에는 우선 가상 함수 테이블에
//Mammal의 모든 가상 함수를 저장하고 그리고 생성된 객체가 Mammal에서 파생된 Dog클래스이기 때문에 이 함수에 동일한 이름의 가상 함수가
//존재히면 그 함수를 가르켜서 이용한다

//기본 클래스
class Mammal
{

protected:
	int its_age;

public:
	Mammal() : its_age(1) { cout << "Mammal constructor... \n"; }
	//가상 소멸자 가상 함수가 하나라도 있으면 가상 소멸자를 사용해야 한다
	virtual ~Mammal() { cout << "Mammal distructoer ... \n"; }
	//복사 생성자 결국 가상 복사 생성자는 이 함수를 이용해 복사를 하기 때문에 꼭 필요하다
	Mammal (const Mammal & rhs );
	//가상 함수
	virtual void Speak() const { cout << "Mammal speak!\n"; }
	//가상 복사 생성자
	virtual Mammal* Clone() { return new Mammal(*this); }
	//나이를 반환하는 함수
	int Get_Age() const { return its_age; }

};