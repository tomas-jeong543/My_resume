#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // !DBG_NEW
#endif


#include<iostream>
#include<string>
#include<sstream>
#include<memory>

using namespace std;
//typedef  shared_ptr < shared_ptr<int[]>[]> Shared_Ptr;
using Shared_Ptr = shared_ptr < shared_ptr<int[]>[]>;
//원리 이해를 위한 함수 메모리 삭제하는 함수를 우리가 설정할 수도 있다는 것을 보여주는 케이스
void delete_int(int * ptr)
{
	cout << "데이터 삭제" << endl;
	delete ptr;
}

void print_int(int* ptr)
{
	cout << *ptr << endl;
}

void ex01()
{
	// 유니크 포인터
	//int* pnum = new int(10);
	// 아래 두 문장은 같은 의미
	//	unique<_ptrint> pnum = make_unique<int>(10);
	auto pnum = make_unique<int>(10);
	
	cout << *pnum << endl;
	
	//생성자를 이용해 호출하는 방법 아주 아주 복잡하다
	/*/unique_ptr<int, decltype(&delete_int)> pnum2(new int, &delete_int);
	*pnum2 = 100;
	cout << *pnum2 << endl;*/

	//에러 발생 대입 연산으로 복사 생성자 호출 불가능이 기본
	//unique_ptr<int> pnum_copy = pnum;
	// 
	//가능하게 하려면 move함수를 이용해 이전하는 것은 가능하다
	unique_ptr<int> pnum_copy = move(pnum);
	
	if (pnum.get() == nullptr) {
		cout << "널값" << endl;
	}
	
	//일반 포인터로 넘길려면  get함수를 사용해야 한다
	print_int(pnum_copy.get());

	int* pstr = pnum_copy.release();

	cout << *pstr << endl;
	//일반 포인터로 사용하는 경우에는 메모리 할당 해제는 필수다
	delete pstr;
	
	//유나크 배열을 가르키는 포인터
	/*unique_ptr<int[]> arr = make_unique<int[]>(10);
	for (int i = 0; i < 10; i++) {
		arr[i] = i;
	}

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << '\t';
	}
	cout << endl;*/

	unique_ptr<unique_ptr<int>[]> arr = make_unique<unique_ptr<int>[]>(5);

	for (int i = 0; i < 5; i++) {
		arr[i] = make_unique<int>(i + 1);
	}


	for (int i = 0; i < 5; i++) {
		cout << &arr[i] << endl;
		cout << *(arr[i]) << endl;
	}


	// 동일한 내용 auto arr = make_unique<int[]>(10);
	//2차원 배열의 동적 선언

	// int형 타입의 포인터 배열을 가르키는 이중 포인터  = int형 타입의 배열을 가르키는 포인터 배열 선언
	unique_ptr<unique_ptr<int[]>[]> arr2 = make_unique<unique_ptr<int[]>[]>(5);

	if (arr2 == nullptr) { return; }

	for (int i = 0; i < 5; i++) {
		arr2[i] = make_unique<int[]>(10);
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			arr2[i][j] = i + j;
			cout << arr2[i][j] << '\t';
		}
		cout << endl;
	}



	// 위의 문장과 같은 의미를 지니는 문장이다 int** arr = new int* [5];

	//메모리 할당 해제를 안 해도 메모리 누수가 발생하지 않는다
}



void ex02()
{
	//shared point test

	//배열 선언 20버전으로 사용하는 게 좋다
	/*shared_ptr<int[]> pnum = make_shared<int[]>(10);
	shared_ptr<shared_ptr<int[]>[]> pnum2 = make_shared<shared_ptr<int[]>[]>(10);
	auto pnum2 = make_shared<shared_ptr<int[]>[]>(10);*/

	//cout << *pnum << endl;

	//cout << pnum.use_count() << endl;

	////대입
	//{
	//	shared_ptr<int> pnum_copy = pnum;
	//	cout << pnum.use_count() << endl;
	//}

	//cout << pnum.use_count() << endl;
}

void func4(weak_ptr<string>& weakstr) {
	auto resource = weakstr.lock();
	if (resource) {
		cout << "Resource still alive." << endl;
	}
	else {
		cout << "Resource has been freed." << endl;
	}
}

void ex03()
{
	//weak pointer 상호참조로 인한 삭제 안되는 것 방지용
	shared_ptr<string>  pnum = make_shared<string>("10");

	//weak포인터의 경우에는 참조해도 참조횟수가 증가하지 않는다
	weak_ptr<string> wpnum(pnum);
	cout << pnum.use_count() << endl;
	
	//blcock 내에서 사용횟수가 증가
	{
		//lock호출 시 shared포인터가 가르키는 대상이 증가해 가르키는 수 증가
		shared_ptr<string> pnum_copy = wpnum.lock();

		cout << pnum.use_count() << endl;
	}
	
	cout << pnum.use_count() << endl;
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	cout << "202211364 정명훈 \n";
	ex03();
	return 0;
}