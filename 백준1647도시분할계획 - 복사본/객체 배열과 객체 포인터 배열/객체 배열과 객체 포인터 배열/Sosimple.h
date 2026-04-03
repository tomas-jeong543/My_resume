#pragma once

#include<iostream>

using namespace std;

class Sosimple
{
private:
	int sosimple_num;
public:
	Sosimple():Sosimple(0){}
	Sosimple(int x) :sosimple_num(x) { cout << "생성자 호출" << endl; }

	void display() const
	{
		cout << "numinfo: " << sosimple_num << endl;
	}

	Sosimple(Sosimple& ins) :Sosimple(ins.sosimple_num) {
		cout << "복사 생성자 호출" << endl;
	}

	Sosimple(Sosimple&& ins)noexcept :Sosimple(ins.sosimple_num) {
		
		cout << "이동 생성자 호출" << endl;
		ins.sosimple_num = -1;
	}
};

