#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // !DBG_NEW
#endif



#include<iostream>
#include<string>
#include<iomanip>
#include<ctime>
#include<memory>
using namespace std;

void uniform_practice()
{
	string a1 = "A";
	string a2("A");
	string a3{ "A" };

	cout << "a1" << setw(3) << a1 << setw(3) <<  "a2" << setw(3) << a2 << setw(3) << "a3" << setw(3) << a3 << endl;

	char idx = 'a';
	int resulidx = idx - '0';
	idx = resulidx + '0';
	cout << resulidx << endl;
	cout << idx  << endl;

	string info;
	string line;

	do {
		cout << "정보 입력: 그냥 앤터키 입력 시 종료" << endl;
		getline(cin, line);
		info += line + "\n";

	} while (!line.empty());

	cout << info;

	string word1 = "hello";
	string word2 = "world";

	cout << "before swap: " << "word1:" << setw(7) << word1 << setw(7) << "word2:" << setw(7) << word2 << endl;
	swap(word1, word2);
	cout << "after swap: " << "word1:" << setw(7) << word1 << setw(7) << "word2:" << setw(7) << word2 << endl;
}

void stri_practice()
{
	string str("There are two needles in this haystack with needles.");
	string str2("needle");
	str2 = "needle";
	size_t num = 0;
	size_t pos = 0;
	while (( num = str.find("needle", pos, 6)) != str.npos) {
		cout << num << endl;
		pos = num + 1;
		str.replace(num, str2.length(), "preposition");
	}
	cout << str << endl;

	string substr2 = str.substr(2, 7);
	cout << substr2 << endl;
}

void practice_ref()
{
	int num{3};
	int* numptr = &num;
	int** numdptr = &numptr;
	//포인터 변수도 모두다 참조자로 가르킬 수 있다
	int& numref = num;
	int* (&numptrref) = numptr;
	int** (&numdptrref) = numdptr;

	cout << numref << endl;
	cout << *numptr << endl;
	cout << **numdptr << endl;
	cout << "numref = 2;" << endl;
	numref = 2;
	cout << numref << endl;
	cout << *numptr << endl;
	cout << **numdptr << endl;

}

const string& info = "hello";
const string& get_string()
{
	//const string& info = "hello";
	return info;
}

void type_casting()
{
	//static_cast 일반적인 c에서의 형변환
	int a = 57;

	char atochar = static_cast<char>(a);
	cout << atochar << endl;

	//const_cast const없애냐 안 없애냐의 예제
	const string& subject = "c++";
	// 형에서 상수형을 지워버리는 효과
	string& subject2 = const_cast<string&>(subject);
	//auto subject2 = subject; 이 문장은 위의 문장과 다른 결과를 가져온다 직접 확인이 필요
	subject2 = "java";
	cout << "subject:" << setw(5) << subject << endl;
	cout << "subject2:" << setw(5) << subject2 << endl;
	const string& subject3 = as_const(subject2);
}

void differ_types_and_useful_method()
{
	int foo = 10;
	//이미 타입이 알려진 변수의  타입을 활용한다
	auto foo2 = foo;

	auto info = get_string();
	cout << "info: " << info << endl;
	info.replace(0, 1, "H");
	cout << "info: " << info << endl;
	decltype(get_string()) info2 = get_string();
	//info2 = "Ass"; 이 문장은 오류가 발생한다 그 이유는 auto와 다르게 declytype에서는 const와 참조자 변수 모두 다 반영되기 때문이다.

	//for each 구문 auto 활용한 예제
	string tester{ "tomas"};
	for (auto c : tester) {
		cout << "[" << c << "]";
	}
}

void array_prac()
{
	//int grade[5];

	////쓰레기값이 저장된다
	//for (int i = 0; i < 5; i++) {
	//	cout << setw(2) << grade[i];
	//}

	cout << endl;
	int grade2[5]{};

	for (int i = 0; i < 5; i++) {
		cout << setw(2) << grade2[i];
	}

	cout << endl;

	cout << size(grade2) << endl;

	for (auto i : grade2) {
		cout << setw(2) << i;
	}
}

void makerand()
{
	srand(static_cast<unsigned int>(time(NULL)));

	for (int i = 0; i < 10; i++) {
		int num = rand() % 100;
		cout << i + 1 << setw(5) << num << endl;
	}
}

void dynamic_mem()
{
	int* tmp = new int;
	*tmp = 200;
	cout << "tmp:" << setw(20) << tmp << "*tmp:" << setw(2) << *tmp << endl;
	//이 두문장은 꼭 실행하는 것 필요
	delete tmp;
	tmp = nullptr;
	
	int* tmparr = new int[10]{21,12,3223,344,3434,31223,324324,32432, 9, 21};

	for (int i = 0; i < _msize(tmparr) / sizeof(int); i++) {
		cout<< setw(5) << tmparr[i];
	}

	delete[] tmparr;
	tmparr = nullptr;
}

void two_dimension()
{
	int col, row;
	cout << "col: ";
	cin >> col;
	cout << "row: ";
	cin >> row;

	int** arr1 = new int* [row];
	int** arr2 = new int* [row];
	
	if (arr1 == nullptr || arr2 == nullptr) { cout << "memory_allocation failed" << endl; return; }

	for (int i = 0; i < row; i++) {
		arr1[i] = new int[col];
		arr2[i] = new int(i);
		if (arr1[i] == nullptr || arr2[i] == nullptr) { cout << "memory_allocation failed" << endl; return; }
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			arr1[i][j] = i + j;
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << setw(3) << arr1[i][j];
		}
		cout << endl;
	}


	cout << endl << "arr2" << endl;
	for (int i = 0; i < row; i++) {
		cout << *arr2[i] << setw(3);
	}

	for (int i = 0; i < row; i++) {
		delete[] arr1[i];
		delete[] arr2[i];
	}

	delete[] arr1;
	delete[] arr2;
	arr2 = nullptr;
	arr1 = nullptr;
}

void Test_weak(weak_ptr<string> w)
{
	auto resource = w.lock();
	if (resource) {
		cout << "자원" <<  *resource << endl;
	}
	else {
		cout << "포인터에 자원이 존재하지 않는다" << endl;
	}
}

void basic_smart_pointer()
{
	//스마트 포인터 메모리 할당 해제를 자기가 직접 해주는 포인터 하지만 그냥 동적할당하고 해제하는 게 더 쉬워 보인다.

	//1번 unique포인터 이 포인터로 가르키는 대상은 다른 포인터로는 참조가 불가능하다
	unique_ptr<int> u = make_unique<int>(10);
	//unique_ptr<int> test = u; 실행이 안되는 문장
	//일반 포인터로 사용하려면 get 메소드를 이용해야 함 이 때는 메모리 할당 해제 필요는 없다
	int* ptr = u.get();
	cout << *ptr << endl;
	//reset 과 relwase 메소드는 각각 포인터가 가르키는 값을 다른 변수를 가르키게 하거나 아니면 null포인터로 만든다

	u.reset(new int(5));
	cout << *u << endl;
	u.release();
	cout << u << endl;

	//shared_ptr 공유 가능한 포인터 대입연산이 이루어질 때마다 참조 횟수 변수 증가
	shared_ptr<string> sh = make_shared<string>("hello");
	cout << "count" << sh.use_count() << endl;
	shared_ptr<string> shcopy = sh;
	cout << "count" << sh.use_count() << endl;
	//참조한 포인터가 nullpointer로 변경되면 참조 횟수는 1감소한다
	shcopy.reset();
	cout << "count" << sh.use_count() << endl;
	//get을 사용해 일반 포인터로 사용하면 참조횟수가 증가하지 않는다
	string* test2 = sh.get();
	*test2 = "FCB";
	cout << "count" << sh.use_count() << endl;
	cout << *sh << endl;

	//week_ptr 직접 리소스 소유하지 않고 shared_ptrdl 소유한 리소스를 가르키면서도 참조횟수를 증가시키지 않는 스마트 포인터
	
	Test_weak(sh);
	sh.reset();
	Test_weak(sh);
}



void two_dimension_smart_ptr()
{
	//위의 놈은 이차원 배열을 아래는 int*타입의 shared_ptr를 가지고 있는 느낌으로 둘은 엄연히 다르고 햇갈리면 안된다
	shared_ptr<shared_ptr<int[]>[]> a1 = make_shared<shared_ptr<int[]>[]>(10);
	shared_ptr<shared_ptr<int>[]> a2 = make_shared<shared_ptr<int>[]>(10);
	if (a2 == nullptr) { cout << "heap overflow" << endl; return; }

	for (int i = 0; i < 10; i++) {
		a2[i] = make_shared<int>(i);
		a1[i] = make_shared<int[]>(10);
		for (int j = 0; j < 10; j++) {
			a1[i][j] = i + j;
		}
	}
	
	for (int i = 0; i < 10; i++) {
		cout << setw(2) << *a2[i];
	}


	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << setw(3) << a1[i][j];
		}
		cout << endl;
	}
}


int main()
{
	//main부분
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	two_dimension();
	return 0;
}


