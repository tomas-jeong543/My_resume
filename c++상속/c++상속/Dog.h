#pragma once
#include"Mammal.h"
//개 클래스는 포유류 클래스 부터 상속되었다 따라서 각 개 객체는 세 가지 맴버 변수 its_age, its_weight,its_Brees를 가진다
//이 중 두개의 맴버 변수 나이와 체중은 여기에 적혀 있지 않지만 상속 받은 것 
//ㅎ지만 생성자롸 복사 생성자 소멸자 등은 예외이다

//전용 맴버를 나타내는 private은 파생 클래스에서는 유효하지 않기 때문에 파생된 클래스에 대해서만 유효하게 protected로 선언했다

//만일 함수가  클래스 객체를 가지고 있다면 그 함수는 모든 범용 맴버와 자료에 접근 가능
//맴버함수는 그 자신의 모든 전용 자료 맴버와 함수에 접근이 가능하며 자신을 파생시킨 클래스의 모든 보호 자료 맴버와 함수에 접근 가능
class Dog :public Mammal
{

private:
	BREED its_Breed;
public:
	Dog ();
	//중첩된 생성자 구현
	Dog(int age);
	Dog(int age, int weight);
	Dog(int age, BREED breed);
	Dog(int age, int weight, BREED breed);
	~Dog();

	BREED Get_Breed() const { return its_Breed; }
	void Set_Breed(BREED breed) { its_Breed = breed; }

	void Wag_Tail() const { cout << "Tail Wagging\n"; }
	void BegFor_Food() const { cout << "Begging for Food\n"; }
};