#pragma once
// 에너지를 표현하는 파워 클래스
#include<iostream>
using namespace std;

class Power
{
private:

	int kick; // 발로 차는 힘
	int punch; // 주먹으로 치는 힘
public:
	//default 설정하는 이유는 몸통을 안 만들기 위함
	Power() = default;
	Power(const int& kick = 0, const int& punch = 0) :kick(kick), punch(punch)
	{
	}

	Power(Power& ins) :Power(ins.kick, ins.punch)
	{
	}
	friend ostream& operator<< (ostream& out, const Power& p);
	//우리가 만든 데이터 타입이 앞에 오는 경우
	Power& operator<< (ostream& out);
	void show() const;

	Power operator+ (Power op2);
	bool operator== (Power op2);
	Power& operator+= (Power op2);
	Power& operator+= (int num);
	Power operator<< (int num);
	Power& operator-- ();
	Power operator-- (int x);
	operator int() {
		return kick + punch;
	}
};
