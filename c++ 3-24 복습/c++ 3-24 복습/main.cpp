#include<iostream>
#include<string>
#include<map>
using namespace std;

void ex1()
{

	constexpr int row = 7;
	constexpr int col = 5;

	int** arr = new int* [row];
	
	if (arr == nullptr) { return ; }

	for (int i = 0; i < row; i++) {
		*(arr + i) = new int[col];
		if (*(arr + i) == nullptr) { return; }
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			arr[i][j] = i + j;
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << arr[i][j] << '\t';
		}
		cout << endl;
	}



	for (int i = 0; i < row; i++) {

		delete[] arr[i];
		arr[i] = nullptr;
	}

	delete[] arr;
	arr = nullptr;


	//오류 예제 정적으로 선언된 변수를 가르키는 포인터에 동적 데이터 해제를 하면 당연히 오류가 생신다 애초에 포인터가 가르키는 주소가 스택영역에 있는데
	//힙 영역의 데이터를 삭제하려고 하면 당연히 오류가 발생할 수 밖에 없다
	int n = 5;
	int* p = &n;
	//delete p;

}

void ex2()
{
	//c++ 에는 3가지 초기화 방법이 존재한다

	//1 복사 초기화 그냥 흔히 c에서 많이 쓰는 방법이다
	
	int a = 5;

	//2 직접 초기화

	int b(7);

	//3 유니폼 초기화 장점은 축소변환시에는 경고가 아닌 오류를 발생시킨다 그리고 배열 초기화에도 사용할 수 있다
	int c = { 5 };
	cout << c << endl;
	int d = {};
	cout << d << endl;

	//경고
	int x = 3.14;
	int y(3.14);
	//오류
	//int z{ 3.14 };

	int arr[4]{ 1,2,3,4 };
	cout << sizeof(arr) << endl;


	for(auto i = 0; i < sizeof(arr) / sizeof(int); i++) {
		cout << arr[i] << " ";
	}
	
	cout << endl;

	map<string, int> smap{ {"홍길동", 1}, {"정명훈" ,2} };

	//auto를 이와 같이 for each구문으로 변형해서 사용할 수 있다
	for (auto person : smap) {
		cout << person.first << " " << person.second << "\n";
	}

}

const string& Get_String() {
	string* a = new string("green");
	return *a;
}

void ex04()
{
	auto a = Get_String();
	decltype(Get_String()) b = Get_String();


	cout << "a: " << a << " b: " << b << endl;
	cout << "typeof a:" << typeid(a).name() << "\n" << " typeof b: " << typeid(b).name();
}


void ex05() {
	//const_cast 관련된 복습 참고로 참조자는 무한대로 참조가능


	const string& str1 = "c++";
	//오류 발생str1 = "java";
	string &str2 = const_cast<string&>(str1);
	str2 = "java";


	//주의해야 할 점은 같은 주소와 변수를 같기 때문에 str2의 값이 변하면 str1의 값도 java로 바뀐다 이를 활용하면 다양한 분야에서 유용하게 쓸 수 있다
	cout << "Str2: " << str2 << endl;
	cout << "str1: " << str1 << endl;

	//이렇게 const타입이 아닌 변수를 이용해서도 const casting을 이용해서 const 타입으로 바꿀 수 있다
	const string& str3 = const_cast<const string&>(str2);
	const string& str4 = as_const(str2);

	//다 같은 주소와 같은 값을 가지고 있다는 것을 확인할 수 있다
	cout << "str1 adress and value: " << &str1 << " " << str1  << "\n" << "str2 adress and value: " << &str2 << " " << str2 << "\n" <<
		"str3 adress and value: " << &str3 << " " << str3 << "\n" << "str4 adress and value: " << &str4 << " " << str4 << endl;
}

int main()
{
	ex05();
	return 1;
}