#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#include"Student.h"

using namespace std;

int Get_Sum(int * (&score))
{
	int sum = 0;
	
	score[0] -= 2;

	for (int i = 0; i < _msize(score) / sizeof(score[0]); i++) {
		sum += score[i];
	}

	return sum;
}

void ex01()
{
	int num = 1;
	int i, j;
	for (  i = 0,  j = 20; i != j; i++, j--) {
		cout << setw(10) << num << endl;
		num *= 10;
	}


	int* ptr = new int[10];
	for (int i = 0; i < 10; i++) {
		*(ptr + i) = i + 1;
	}

	int sum;

	if ( sum = Get_Sum(ptr),  sum < 55) {
		cout << "false" << endl;
	}
	else {
		cout << "true" << endl;
	}


	delete[] ptr;
}


void ex02()
{
	int quantity = 0;
	int price = 0;
	string str_info;
	stringstream buf;

	cout << "가격과 수량 입력: ";
	getline(cin, str_info);

	buf.str(str_info);

	buf >> price;
	buf >> quantity;
	cout << "총 가격은 " << price * quantity << " 입니다" << endl;

	int a, b;

	a = (b = 3,b = b* b, b* b);
	cout << a << " " << b;
}


void ex03()
{
	constexpr int SIZE = 20;
	
	Student* info = new Student[20];
	if (info == NULL) { cout << "메모리 할당 중 오류"; return; }


	for (int i = 0; i < SIZE; i++) {

		int id;
		id = (id = 10000, id + 1);

		info[i].Set_Age(i);
		info[i].Set_Grade(0.1 * i);
		info[i].Set_Student_id("2025" +  to_string(id));
	}
	cout << left;
	for (int i = 0; i < SIZE; i++) {
		(cout << "age: ",cout << setw(3) , cout << info[i].Get_Age(), cout << " id: ", cout << info[i].Get_id(),cout <<  " grade: ", cout << info[i].Get_grade(), cout << endl);
	}

}


int main(){
	ex03();
	return 0;
}