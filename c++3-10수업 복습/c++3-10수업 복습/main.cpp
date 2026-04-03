#include<iostream>
#include<string>
#include<sstream>
using namespace std;

void ex01()
{
	string mystr;
	float price = 0;
	int quantity = 0;
	//입출력 버퍼를 통해서 문자열 배열에 있는 정보를 내가 만든 출력 버퍼로 마치 cin처럼 다른 변수에 그 값을 집어 넣을 수 있다
	//이 방법은 특히 파일에서 정보를 획득할 때 다른 함수를 선언할 필요가 없다는 점에서 상당히 유용하다
	cout << "Enter a  price: ";
	//getline은 공백이 있는 문자열을 받기 위해서 사용된다
	getline(cin, mystr);
	stringstream(mystr) >> price;
	
	cout << "Enter a quantity: ";
	getline(cin,mystr);
	stringstream(mystr) >> quantity;

	cout << "Total price: " << price * quantity << endl;

}


void ex02()
{
	string mystr;

	cout << "Enter your data: ";
	getline(cin, mystr);
	//stringstream을 선언하는 방법 또다른 방법으로는 stringstream ss(mystr)등으로 mystr에 대한 입출력 버퍼를 선언할 수 있다 
	stringstream ss;
	ss.str(mystr);

	string info;

	while (ss >> info) {
		cout << info << endl;
	}
}

void ex03()
{
	float price = 100.5f;
	int quantity = 200;
	stringstream ss;
	//버퍼에 내가 원하는 내용을 입력할 수도 있다는 것을 보여주는 예제 단 이 때 문자열의 구분은 스페이스바나 빈공간 혹은 enter키다
	ss << "price:" << price << endl;
	ss << "quantity:" << quantity << endl;

	string  data;
	//getline을 제외하고 대부분 입력과 출력에서 구분 기준은 빈 공간 스페이스와 앤터이다
	while (ss >> data) {
		cout << data;
		cout << endl;
	}
}

int main()
{
	ex03();
	return 0;
}