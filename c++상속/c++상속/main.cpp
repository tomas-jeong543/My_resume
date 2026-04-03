#include"Dog.h"
#include"MAmmal.h"

int main()
{
	//여기서 알 수 있는 점은 Dog객체를 생성하기 위해서는 먼저 Mammal 객체가 생성되어야 하며 이에 따라 Mammal의 생성자가 먼저
	//호출되고 그 다음에 Dog객체가 생성되며 그리고 소멸자는 반대로 Dog객체가 먼저 삭제되고 Mammal 객체가 나중에 삭제된다
	Dog fido;
	Dog rover(5);
	Dog buster(6, 8);
	Dog yorkie(3, GOLDEN);
	Dog dobbie(4, 20, DOBERMAN);
	fido.Speak();
	rover.Wag_Tail();
	cout << "Yorkie is " << yorkie.Get_Age() << " years old\n";
	cout << "Dobbie weight" << dobbie.Get_Weight() << " pounds\n";
	return 0;
}