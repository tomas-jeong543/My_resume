#pragma once
#include<iostream>

using namespace std;

enum { kIsSmaller, kIsLarger, kIsSame };

class Data
{
	//데이터 객체는 값을 가질 수 있으며 자신을 다른 객체와 비교 가능하며 객체값을 출력할 수 있는 메소드도 존재한다
private:
	int myvalue;
public:
	Data(int val) : myvalue(val) {};
	~Data() {}
	int Compare(const Data&);
	void  Show() { cout << myvalue << endl; }
};