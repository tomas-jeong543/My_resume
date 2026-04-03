#include"Dog.h"

Dog::Dog() :
	// 주의점 강아지의 기본 생성자가 포유류의 기본 생성자를 호출한다 이는 매개변수를 호출하지 않는 기본 생성자를 호출한다는
	//의도를 명확히 한 것

	Mammal(),
	its_Breed(GOLDEN)
{
	std::cout << "Dog constructor \n";
}

Dog::Dog(int age) :
	Mammal(age),
	its_Breed(GOLDEN)
{
	std::cout << "Dog(int) constructor \n";
}

Dog::Dog(int age, int weight) :
	//나이는 부모의 생성자를 이용해 초기화
	Mammal(age),
	its_Breed(GOLDEN)
{
	//무게는 입력받은 무게를 이용해 자체 초기화
	its_weight = weight;
	std::cout << "Dog(int, int) constructor \n";
}

Dog::Dog(int age, int weight, BREED breed) :
	//역시 나이는 부모의 생성자를 이용해 초기화 했다
	Mammal(age),
	its_Breed(breed)
{
	its_weight = weight;
	std::cout << "Dog(int, int ,BREED) constructor \n";
}

Dog::Dog(int age, BREED breed) :
	Mammal(age),
	its_Breed(breed)
{
	std::cout << "Dog(int ,BREED) constructor \n";
}


Dog::~Dog()
{
	std::cout << "Dog distructor \n";
}