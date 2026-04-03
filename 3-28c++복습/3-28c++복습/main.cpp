#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>

using namespace std;

void ex01()
{
	int num;
	string inputbuf;
	stringstream buf;

	
	/*/cout << "이름과 성적을 입력하시오: ";
	getline(cin, inputbuf);

	buf.str(inputbuf);
	
	int sum = 0;
	int data;
	string name;
	int time = 4;

	buf >> name;

	while (buf >> data) {
		sum += data;
	}

	cout << name + ": " <<  sum <<  endl;*/



	stringstream sout;

	sout << "202211364" << " 정명훈" << " \n";
	sout << "2학년 " << "22학번" << " \n";
	
	string outbuf;

	while (sout >> outbuf) {
		cout << outbuf << endl;
	}
}

void ex02()
{
	cout << right;;
	float a = 100;
	float b = 0.7;
	//iomanip library + 공백 간격을 설정할 수 있다
	cout << b << setw(10) << a <<  endl;
	cout << b << endl;


	int arr[5] = { 16,17,18,19,20 };

	for (auto num : arr) {
		cout << num << setw(5) << setfill('-');
	}
	cout << endl;
	
	cout << 8 << endl;
	cout << endl;

	//진법을 바꾸는 것은 유지가 된다
	for (auto num : arr) {
		cout <<setw(5) << setfill('-');
		cout  << num ;
	}

	cout << left; // 왼쪽 정렬 설정
	cout << endl;
	// 너비를 10으로 설정하고 왼쪽 정렬된 텍스트 출력
	cout << std::setw(10) << "Hello"  << setw(10) << "World" << "and me" << endl;
	// 다른 예제
	cout << std::setw(10) << "Hello" << setw(10) << "World" << "and me" << endl;
	cout << setw(10) << "C++oo"  << setw(10) << "Program" << "class" << endl;
}

void ex03(){
	cout << right;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << i + j << setw(10) << setfill('-') << " ";
		}
		cout << "\n";
	}
}

int main()
{
	ex02();

	return 0;
}