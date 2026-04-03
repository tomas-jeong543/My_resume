#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // !DBG_NEW
#endif

#include<iostream>
#include<string>
#include<memory>

using namespace std;


void unique_to_normal(string* name) {
	if (name == nullptr) { return; }

	cout << *name << endl;
	delete name;
}

void unique_to_normal_array(string * name, int size)
{

	if (name == nullptr) { return; }

	for (int i = 0; i < size; i++) {
		cout << name[i] << " ";
	}

	delete[] name;
}


void ex01()
{
	unique_ptr<string> ptrstr = make_unique<string>("String");

	cout << *ptrstr << endl;
	//만약 인자 전달 시에 일반 포인터처럼 사용하기 위해서는 get메소드를 이용해야 한다
	unique_to_normal(ptrstr.get());

	//unique_ptr<unique_ptr<string>> pptstr = ptrstr;
	//위의 문장은 실행가능 하지 않다 왜냐하면 unique포인터는 자신이 가르키고 있는 리소스의 공유가 불가능하기 때문이다

	//배열 선언
	unique_ptr<string[]> ptrstr2 = make_unique<string[]>(3);
	
	ptrstr2[0] = "tomas";
	ptrstr2[1] = "tomas1";
	ptrstr2[2] = "tomas2";

	cout << ptrstr2[0] << endl;
	unique_to_normal_array(ptrstr2.get(), 3);
	cin.ignore();
	return;

}




int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	ex01();
	return 0;
}