#include<iostream>
#include"Cat.h"
using namespace std;
//객체에 대한 다른 이름을 만들 때에는 참조자를 사용한다 또한 모든 참조자는 초기화되어야 한다
//또한 참조자를 재치환하려면 안되고 참조자와 주소 연산자를 햇갈리면 안된다
//또한 참조자는 클래스가 아닌 객체에 대해서만 만들 수 있다는 점도 유의해야 한다
void Basic_Ref()
{
	int int_One;
	//참조자의 주소는 가리키도 있는 변수의 주소이며 이는 바로 참조자의 본질이다
	int& rSome_Ref = int_One;

	int_One = 5;
	cout << "intOne: " << int_One << endl;
	cout << "rSomeRef: " << rSome_Ref << endl;

	rSome_Ref = 7;
	cout << "intOne: " << int_One << endl;
	cout << "rSome_Ref: " << rSome_Ref << endl;

	
}

void Ref_CantBe_Redefined()
{
	int  int_One;
	int& rSome_Ref = int_One;

	int_One = 5;
	cout << "intOne:\t\t" << int_One << endl;
	cout << "rSomw_ref\t" << rSome_Ref << endl;

	cout << "&int_One: \t" << &int_One << endl;
	cout << "&rSome_Ref \t" << &rSome_Ref << endl;

	int int_Two = 8;
	//참조자는 주소값을 재할당 할 수 없다 한번 정해진 주소가 계속 유지된다는 뜻이다
	//이 경우에도 값은 8로 바뀌었지만 주소는 여전히 int_One 을 가르킨다
	rSome_Ref = int_Two;
	cout << "\nintOne:\t\t" << int_One << endl;
	cout << "intTwo: \t" << int_Two << endl;
	cout << "rSomeRef:\t" << rSome_Ref << endl;

}

void Objective_Ref()
{
	Cat Frisky(5,8);
	//실제 객체에 대한 참조자 클래스에 대한 접근은 불가능 
	//추가적으로 널 참조자는 사실상 불가능하다 널 객체가 존재하기는 하지만 넣으면 오류가 발생할 수 있음으로 참조자는 늘 객체에 넣어애 한다
	Cat& rCat = Frisky;

	std::cout << "Frisky is: ";
	std::cout << Frisky.Get_Age() << "years old. \n";
	cout << "And Frisky weighs: ";
	cout << rCat.Get_Weight() << "pounds. \n";
}


void Swap_Ptr(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

//참조자에 의한 swap 가독성 그리고 오류 감소 및 내부과정이 뻔하지 않게 된다	
void Swap_Ref(int &rx, int &ry)
{
	int tmp;

	tmp = rx;
	rx = ry;
	ry = tmp;
}
//c에서와 동일하다 참조에 의한 전달을 이용해 실제로 그 객체의 내용을 변화시킨다
void Call_By_Ref()
{
	int x = 5, y = 10;

	cout << "Main before Swap x: " << x << " y: " << y << endl;
	Swap_Ref(x,y);
	cout << "Main After Swap x: " << x << " y: " << y << endl;
}



int main()
{
	Call_By_Ref();
	return 0;
}