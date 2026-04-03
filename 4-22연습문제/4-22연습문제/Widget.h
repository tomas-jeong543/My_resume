#pragma once

#include<iostream>
using namespace std;

class Widget
{
private:
	string name;
	int id;
	static inline int nextId = 0;
public:
	Widget(string name);
	void display() const;
	static int getWidgetCount();
	~Widget() { cout << this->name << " °´Ã¼ ¼Ò¸ê\n"; }
};

