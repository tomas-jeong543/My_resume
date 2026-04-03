#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Circle.h"
#include<iomanip>
#include"Person.h"
#include<stdio.h>
#include<string.h>
#include"Sosimple.h"
#define _CRT_SECURE_NO_WARNINGS
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // !DBG_NEW
#endif

using namespace std;

void Your_func(const Sosimple& obj)
{
	obj.Sosimple_func();
}

int main()
{
	//main부분
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Circle creater;
	//내부 함수에서 동적 할당해 객체를 생성했을 때는 메모리 누수 방지를 위해서 참조자 기호로 반환해야 하고
	// 받을 때는 포인터로 받아서 사용 후 포인터를 이용해 동적 메모리를 나중에 꼭 해제해야 한다
	Circle *a = &creater.Create_circle(5);
	cout << "creater rad:" << setw(2) << creater.Get_circle() << " a rad:" << setw(2) << a->Get_circle() << endl;

	//이대로 프로그램이 종료되면 함수에서 메모리를 동적할당해서 넘겼기 때문에 누수가 날 수 밖에 없다. 
	// 따라서 누수를 막기 위해 동적 메모리 할당한 부분을 해제해야 한다

	delete a;

	//배열을 이렇게 선언하는 경우에는 무조건 기본 생성자가 필요하다 Circle creater가 10번 호출된 것과 같은 의미를 가진다
	Circle arr[10];
	string info = "tomas";

	//항상 마지막 요소에는 널 문자를 넣어 주어야 한다
	char name[] = { 't', 'o', 'm', 'a', 's', NULL};
	char name2[] = { 'j', 'a', 'm', 'e', 's', NULL };
	
	cout << strlen(name) << endl;
	
	Person *p1 = new Person(name, 21);
	Person p2(name2, 23);
	
	p1->Show_info();
	p2.Show_info();
	delete p1;

	//const Sosimple sim_num(5);

	//sim_num.showStatus();
	//sim_num.Add(); 상수 객체는 상수 맴버 함수를 통해서만 접근이 가능하다


	const Sosimple obj1(5);
	Sosimple obj2(3);

	obj1.Sosimple_func();
	obj2.Sosimple_func();
	//이를 통해 const가 아닌 객체가 const 참조자 변수로 인자 전달이 되서 메소드가 호출되는 경우에는 무조건 const메소드가 호출된다는 사실을 알 수 있다
	Your_func(obj1);
	Your_func(obj2);


	Sosimple* obj1ptr = static_cast<Sosimple>(obj1).GetThisPointer();
	Sosimple* obj2ptr = &obj2;

	cout  << "obj1ptr" << obj1ptr << "adress: ";
	obj1ptr->Show_adress();


	return 0;
	//종료 후 p2객체 삭제


}