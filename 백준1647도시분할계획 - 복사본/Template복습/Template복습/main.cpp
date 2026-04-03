#include<iostream>
#include<list>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

template<typename T>
void printArr(T arr) {
	for (auto info : arr) {
		cout << info << "\t";
	}
}

list<string> getStudent(list<list<string>> std, list<string> droplist) {
	list<string> ans{};
	
	for (auto info : std) {
		auto it = ans.cbegin();
		ans.splice(it, move(info));
	}


	for (auto drop : droplist) {
		ans.remove(drop);
	}
	ans.sort();
	ans.unique();

	return ans;
}

void prac1() {
	list<list<string>> std;
	std.push_back({ "greenjoa1", "bluejoa1", "greenjoa3" });
	std.push_back({ "greenjoa1", "greenjoa3" });
	std.push_back({ "redjoa1", "greenjoa2", "bluejoa2" });
	list<string> droplist({ "greenjoa2", "bluejoa1" });

	auto student = getStudent(std, droplist);
	printArr(student);
}

void prac2() {
	plus<int> myplus;
	int res = myplus(4, 5);
	cout << res << endl;

	list<int> mylist = { 20,40,30,70,50,60 };
	mylist.sort(less<int>());
	printArr(mylist);

	priority_queue<int, vector<int>, greater<>> myqueue;
	myqueue.push(3);
	myqueue.push(2);
	myqueue.push(5);
	myqueue.push(4);
	myqueue.push(1);
	
	cout << endl;

	while (!myqueue.empty()) {
		cout << myqueue.top() << endl;
		myqueue.pop();
	}

}


void prac3() {
	auto func1 = [] {cout << "Lambda function" << endl;};
	func1();

	auto func2 = [](int value) {cout << "value: " << value << endl;};
	func2(10);

	auto func3 = [](int num1, int num2) {return num1 + num2;};

	cout << func3(2, 3) << endl;


	double data = 3.13;

	auto func4 = [&data] {data += 1; cout << data << endl;};
	func4();
	
	list<int> mylist = { 20,40,30,70,50,60 };
	cout << "before" << endl;
	printArr(mylist);
	cout << endl;
	mylist.remove_if([](auto i) {return i < 40;});
	cout << "after" << endl;
	printArr(mylist);
}


bool checkKim(string s) {
	if (s.find("김") != string::npos)
		return true;
	else
		return false;
}

void prac4() {
	vector<string> names{ "홍길동", "김길동", "이길동", "고길동", "박길동" };

	auto it = find(names.begin(), names.end(), "구길동");
	if (it != names.end()) {
		cout << distance(names.begin(), it) << "에" << *it << "이 존재함" << endl;
	}
	else {
		cout << "존재하지 않음" << endl;
	}
	string target = "박길동";
	auto it2 = find_if(names.begin(), names.end(), [target](auto name) {return name == target;});
	//auto it2 = find_if(names.begin(), names.end(), checkKim);
	if (it2 != names.end()) {
		cout << distance(names.begin(), it2) << "에" << *it2 << "이 존재함" << endl;
	}
	else {
		cout << "존재하지 않음" << endl;
	}
}


void prac5() {
	vector<string> names{ "홍길동", "김길동", "이길동", "고길동", "고길동", "박길동","고길동", "박길동" };
	vector<string> target{"고길동", "박길동" };

	auto it1 = search(names.begin(), names.end(), target.begin(), target.end());

	if (it1 != names.end()) {
		cout << "시퀀스 존재" << endl;
	}
	else {
		cout << "시퀀스 존재하지 않음" << endl;
	}
	//복수 개수의 요소를 찾을 때 사용
	auto it2 = search_n(names.begin(), names.end(), 2, "고길동");

	if (it2 != names.end()) {
		cout << "시퀀스 존재" << endl;
	}
	else {
		cout << "시퀀스 존재하지 않음" << endl;
	}
}

void prac6() {
	vector<int> vec(100);
	int value = 0;

	generate(vec.begin(), vec.end(), [&value] {value += 1; return value;});
	int num = 0;

	for_each(vec.begin(), vec.end(), [&num](auto i) { cout << i << "\t"; if (num % 10 == 0 && num != 0) { cout << endl; } });
}


int main()
{
	prac6();
	return 0;
}