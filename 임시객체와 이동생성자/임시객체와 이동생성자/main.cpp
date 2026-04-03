#include<iostream>
#include"Temporary.h"
#include<memory>

using namespace std;




void print_message(Temporary & ins)
{
	cout << "print & ";
	ins.Showtmpval();
}
//이동 생설자 얕은 복사를 하며 기존 객체가 사용되지 않는다고 생각했을 때 사용하고 복사 생성자는 기존 객체가 이용될 때 사용된다
void print_message(Temporary && ins)
{
	cout << "print && ";
	ins.Showtmpval();
}

int main()
{
	Temporary(100, "tomas");
	cout << "after make" << endl;

	Temporary(200, "tomas2").Showtmpval();
	cout << "after make" << endl;

	//임시객체는 이동생성자로 받을 수 있다.
    Temporary && ins = Temporary(300, "tomas3");
	ins.Showtmpval();

	unique_ptr<Temporary> arr = make_unique<Temporary>(400, "tomas5");
	cout << "arr" << endl;
	arr->Showtmpval();

	unique_ptr<Temporary> arrcopy = move(arr);
	arr.release();
	cout << "arrcopy" << endl;
	arrcopy->Showtmpval();

	//이름이 없는 임시 객체 즉 r-value는 이동 생성자로
	print_message(Temporary(500, "tomas4"));
	//이름이 잇는 l-value는 찹조자로 이동한다
	print_message(*arrcopy.get());

	unique_ptr<Temporary> arrcopy2(move(arrcopy));
	cout << "arrcopy2" << endl;

	Temporary && instance = Temporary(10, "real");
	Temporary&& inscopy = move(instance);

	arrcopy2->Showtmpval();
	cout << arr << endl;

	Temporary a2 = move(Temporary(10, "real"));

	Temporary change = move(Temporary(20, "real2"));

	//이거는 l-value넘기는 것이고
	print_message(change);
	//이거는 r-value를 넘기는 것이다
	print_message(move(change));
	return 0;
}