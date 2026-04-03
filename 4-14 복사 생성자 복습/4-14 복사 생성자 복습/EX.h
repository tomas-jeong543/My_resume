#pragma once
#include<iostream>
#include<string>

using namespace std;

class EX
{
private:
	string * value;
public:	
	EX(const string val) { value = new string(val); }

	EX(EX& a): EX(*(a.value))
	{
		cout << "복사 생성자 호출" << endl;
	}

	EX(EX&& a)noexcept :EX(*(a.value)) {
		this->value = a.value;
		cout << "이동 생성자 호출" << endl;
		a.value = nullptr;
	}

	void SetEx(const string x) { *value = x; }
	string& GetEx() { return *value; }

	~EX() {

		cout << *value << "객체가 소멸되었습니다" << endl;
		delete value;
		
	}
};

