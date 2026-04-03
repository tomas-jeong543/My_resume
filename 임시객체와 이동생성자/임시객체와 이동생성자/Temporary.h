#pragma once
#include<iostream>

using namespace std;

class Temporary
{
private:
	string* info;
	int num;
public:
	Temporary(int n, const string& name) : num(n)
	{
		info = new string(name);
		cout << "create obj: " << num << endl;
	}
	~Temporary()
	{
		cout << "destroy obj: " << num << endl;
	}

	explicit Temporary(Temporary& ins):Temporary(ins.num , *(ins.info))
	{
		
		cout << "copy obj" << endl;
	}

	Temporary(Temporary&& ins2)noexcept :Temporary(ins2.num, *(ins2.info))
	{
		this->info = ins2.info;
		ins2.info = nullptr;
		cout << "이동생성자 호출" << endl;
	}

	void Showtmpval() {
		cout << "value: " << num << endl;
		cout << "info: " << *info << endl;
	}

};


