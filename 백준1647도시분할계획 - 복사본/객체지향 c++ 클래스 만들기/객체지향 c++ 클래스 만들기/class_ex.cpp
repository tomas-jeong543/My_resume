#include <iostream>

//객체 지향 언어는 복잡해지는 프로그램에 대비해서 절차지향형 프로그래밍의 한계를 느껴서 만들어짐
class Cat
{
	//따로 public을 선언하지 않는다면 다 private이다 즉 외부 접근이 불가능하다는 뜻이다
	//맴버 자료를 전용으로 만드는 방법은 일반적인 프로그래밍 방법이다 이를 위해서는 전용 변수를 선언하고 여기에 접근할 수 있는
	//전용 메소드를 만드는 것으로 이로 함으로써 자료 저장 방법과 사용 방법의 문제를 분리할 수 있게 한다

	//클래스 생성 시에는 전용 맴버 변수를 선언하고 뻠용 접근자 메소드를 
	// 사용하며 클래스 맴버 함수 안에서 부터 전용 맴버 변수에 접근한다

public:
	int GetAge();
	void SetAge(int age);
	void Meow();
private:
	int itsage;
};

int Cat::GetAge()
{
	return itsage;
}

void  Cat::SetAge(int age)
{
	itsage = age;
}

void Cat::Meow()
{
	std::cout << "Meow.\n";
}

int main()
{
	using namespace std;

	Cat frisky;
	frisky.SetAge(5);
	frisky.Meow();
	std::cout << "Frisky is a cat who is ";
	std::cout << frisky.GetAge() << " years old.. \n";
	frisky.Meow();
	return 0;
}