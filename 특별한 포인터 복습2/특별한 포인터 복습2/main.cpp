#include<iostream>
#include<string>
#include<memory>

using namespace std;

void unique_practice()
{
	unique_ptr<int> a = make_unique<int>();

	*a = 100;

	cout << "a: " << *a << endl;
	unique_ptr<int[]> pnum = make_unique<int[]>(10);

	//차분하게 뜯어보면 unique_ptr<int[]는 int* 이고 make_unique<unique_ptr<int[]>[]>는 new int *[]이고 뒤의 (5)는 배열 포인터의 방의 개수를 의미한다
	unique_ptr<unique_ptr<int[]>[]> b= make_unique<unique_ptr<int[]>[]>(5);
}
void addNum(shared_ptr<int> pnum) {
	(*pnum)++;
	cout << pnum.use_count() << endl;
	//이 공간을 벗어나면 스택 메모리가 해제되면서 참조 횟수가 1로 줄어든다
}
//레퍼런스 카운트 2

void shared_practice()
{
	shared_ptr<int> shptr = make_shared<int>();
	*shptr = 5;
	//아래 문장처럼 공유가 가능하며 공유 시 때마다 참조횟수가 증가한다
	shared_ptr<int> shptr2 = shptr;
	cout << "*shptr: " << *shptr << "*shptr2: " << *shptr2 << endl;

	cout << "count: " << shptr.use_count() << endl;
	
	shared_ptr<int>  pnum = make_shared<int>();
	*pnum = 3;
	//함수 호출 전후 참조횟수 비교하는 과정
	cout << pnum.use_count() << endl;
	addNum(pnum);
	cout << pnum.use_count() << endl;


	//shared_ptr<int[]> arrptr = make_shared<int[]>(10);

	//하지만 shared_pointer 사용시에는 순환 참조로 포인터가 삭제되지 않는 문제가 발생할 수 있다 이를 방지하기 위해서 필요한 것이 바로 week_ptr



}
//Shared_ptr의 참조 횟수를 증가시키지 않고 shared_ptr의 기본 개체에  액세스 할 수 있는 포인터로 Weak_ptr은 리소스를 직접 소유하지 않음
void func4(weak_ptr<string>& weakstr) {
	cout << &weakstr << endl;
	//리소스를 직접 소유하지 않기 때문에 이렇게 직접 출력을 할 수는 없다
	//cout << *(weakstr) << endl;

	//주의점으로는 lock함수 사용시 참조횟수가 증가한다는 점이다
	auto resource = weakstr.lock();
	//리소스 존재 여부에 따른 문장 출력이다
	if (resource) {
		cout << "Resource still alive." << endl;
	}
	else {
		cout << "Resource has been freed." << endl;
	}
}


void Test()
{
	int row, col;

	cin >> row >> col;

	const int ROW = as_const(row);
	const int COL = as_const(col);

	unique_ptr<unique_ptr<int[]>[]> test = make_unique<unique_ptr<int[]>[]>(ROW);
	if (test == nullptr) { cout << "memory error" << endl; return; }
	
	for (int i = 0; i < ROW; i++) {
		test[i] = make_unique<int[]>(col);
		if (test[i] == nullptr) { cout << "memory erroe" << endl; return; }
	}

	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			test[i][j] = i + j;
			cout << test[i][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < COL; i++) {
		//unique_ptr을 null로 바꿔준다는 의미이다
		//test[i].release(); 아래문장과 같은 의미 reset() ()안에 들어간 포인터로 다시 재할당한다는 의미를 같는다
		test[i].reset();
		cout << test[i] << endl;
	}

}


//void week_practice()
//{
//	/*shared_ptr<string> pstr = make_shared<string>("Hello");
//	weak_ptr<string> weakstr(pstr);*/
//
//	
//	func4(weakstr);
//	//내부 포인터 해제하고 다른것으로 바꿀 때 이용하는 기능
//	pstr.reset();
//	func4(weakstr);
//
//
//	//shared_ptr<shared_ptr<int[]>[]> share_test = make_shared<shared_ptr<int[]>[]>(5);
//}

void Const_test()
{
	int a;
	int info =  (a = 1 ,info =  a + 3);
	
	string infostr = to_string(info);

	const string& test = infostr;
	cout << " before test: " << test << endl;
	string& test2 = static_cast<string&>(infostr);
	test2 = "tomas eddison";
	cout << " after test: " << test << endl;
	cout << " after test2: " << test2 << endl;
}


//5명의 이름을 저장할 수 있는 string타입의
//배열을 선언하고, 초기화 한 후 사전 순으로
//이름을 정렬하여출력해주세요


void merge( string name[], int left, int middle, int right)
{
	int i, j ,k;

	int n1 = middle - left + 1;
	int n2 = right - middle;

	string * L = new string[n1];
	string * R = new string[n2];
	if (L == nullptr || R == nullptr) { cout << "memory error" << endl; return; }

	for (int i = 0; i < n1; i++) { L[i] = name[left + i]; }
	for (int i = 0; i < n2; i++) { R[i] = name[middle + 1 + i]; }

	i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (L[i].compare(R[j]) > 0) { name[k++] = L[i++]; }
		else { name[k++] = R[j++]; }
	}

	while (i < n1) { name[k++] = L[i++]; }
	while (j < n2) { name[k++] = R[j++]; }



	delete[] R;
	delete[] L;
}

void merge_sort(string name[], int left, int right)
{
	if (left < right) {
		int middle = left + (right - left) / 2;
		merge_sort(name,left, middle);
		merge_sort(name, middle + 1, right);
		merge(name, left, middle, right);
	}
}


void sol()
{

	cout << endl;
	string name_info[10] = { "amy", "jackson" , "alice", "tom", "charles", "steve", "daniel", "sarah", "lina", "donna" };
	for (int i = 0; i < 9; i++) {
		cout << name_info[i] << " ";
	}
	string* ptr = name_info;

	merge_sort(name_info, 0, 8);
	cout << endl;
	for (int i = 0; i < 9; i++) {
		cout << name_info[i] << " ";
	}
	
}


int main()
{
	sol();
	return 0;
}