#include"Cat.h"
#include"Dog.h"
#include"Horse.h"
#include"Pig.h"
#include"Mammal.h"

//가상 함수는 virtual 함수는 자바의 추상 클래스와 상당히 유사하다 반환형과 원형부는 동일하지만 그 안에서
//실행되는 기능은 전혀 다르고 이로 다형성을 구현할 수 있다 이 예제에서는 다양한 클래스를 부모로 둔 포유류 기본 클래스
//의 말하기 함수를 가상으로 만들고 이를 이용해서 각자 다양한 파생 클래스의 서로 다른 함수를 만들고 이를 포유류 객체 포인터오
// 각 파생된 클래스를 가르키고 speak함수를 호출해 다형성이 구현되는 모습을 확인했다


// 추가적인 정보 맴버 메소드를 가상으로 만들었으면 파생 클래스에서는 가상으로 만들 필요는 없지만 가상으로 표시하는 것이 이해하기 쉽다
int main()
{
	Mammal* theArray[5];
	Mammal* ptr;
	int choice, i;
	for (i = 0; i < 5; i++) {
		cout << "(1)dog (2)cat (3)horse (4)pig: ";
		cin >> choice;
		switch (choice)
		{
		case 1: ptr = new Dog;
			break;
		case 2:ptr = new Cat;
			break;
		case 3:ptr = new Horse;
			break;
		case 4:ptr = new Pig;
			break;
		default:ptr = new Mammal;

		}
		theArray[i] = ptr;
	}

	for (int i = 0; i < 5; i++) {
		theArray[i]->Speak();
		cout << "distructor" << endl;
		//이렇게 가상 메소드로만 Mammal에만 구현된 경우에는 실행되지 않는다
		theArray[i]->~Mammal();
	}	
	return 0;
}