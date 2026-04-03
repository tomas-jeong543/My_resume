#pragma once
#include<iostream>
#include<iomanip>
using namespace std;

class Sosimple
{
private:
	int num;
	mutable int num2;
public:
	Sosimple(int n) :Sosimple(n, 0) {}
	Sosimple(int n, int m) :num(n), num2(m) { Copy_to_Num2(); }

	void showStatus() const{
		cout << num << endl;
	}
	
	void Show_adress() const {
		cout << this << endl;
	}

	//이 함수는 const 객체로는 접근이 불가능하다
	Sosimple& Add(int n) {
		this->num += n;
		return *this;
	}

	void Copy_to_Num2() const
	{
		//mutable 변수는 const 함수에도 변경이 가능하다
		num2 = num;
	}

	void Sosimple_func() {
		cout << "Sosimple_func:" << num << "num2:"<< setw(2) << num2 << endl;
	}

	void Sosimple_func() const{
		cout << "const Sosimple_func:" << num << "num2:"<< setw(2) << num2 << endl;
	}

	Sosimple* GetThisPointer() {
		return this;
	}	

};

