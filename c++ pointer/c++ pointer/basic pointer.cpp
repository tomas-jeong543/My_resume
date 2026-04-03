#include<iostream>

typedef unsigned short int USHORT;

int main()
{
	//포인터는 늘 초기화가 되어야 한다 0은 널 포인터를 의미한다
	USHORT* page = 0;
	//포인터에 변수의 주소값을 넣는 과정
	unsigned short int howOld = 50;
	page = &howOld;

	//간접 지정 연산자 *을 붙이면 그 주소에 저장되어 있는 값을 의미
	std::cout << "howOld: " << *page;

	//포인터의 핵심은 포인터라는 변수와 그 포인터 변수에 저장된 주소값 그리고 포인터 변수에 저장된 주소값이 가리키는 메모리 주소
	//구분이 중요하다

	//포인터를 이용한 자료연산

	using std::cout;

	cout << "\n\n";
	USHORT My_Age;
	
	
	My_Age = 5;

	cout << "my age: " << My_Age << "\n";
	page = &My_Age;
	cout << "page: " << *page << "\n\n";

	cout << "Setting *page = 7.. \n";
	*page = 7;

	cout << "Page: " << *page << "\n";
	cout << "My age: " << My_Age << "\n\n";

	cout << "setiing my age = 9 ... \n";
	My_Age = 9;

	cout << "My_age: " << My_Age << "\n";
	cout << "Page: " << *page << "\n";

	// page는 가르키는 변수의 주소를 *page는 가르키는 변수의 값을 &page는 포인터 자체의 주소를 가르킨다

	return 0;
}
