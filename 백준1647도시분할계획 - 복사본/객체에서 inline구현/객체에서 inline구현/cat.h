#include<iostream>
class Cat
{
private:
	//변수는 메소드에서 이용되기 전에 선언되어야 한다
	int itsAge;
public:
	// 생성자와 소멸자
	Cat(int initalAge);
	~Cat();
	//인라인 함수는 해더 파일에 한 줄로 적을 수도 있다
	int GetAge() const { return itsAge; }
	void SetAge(int age) { itsAge = age; }
	//비맴버 함수의 경우에는 const선언이 불가능하다
	void Meow() { std::cout << "Meow. \n"; }
};