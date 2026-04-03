#pragma once
#include<vector>
#include<memory>
#include"Widget.h"
#include<iostream>
using namespace std;

class WidgetManager
{
public:
	static inline vector<shared_ptr<Widget>> widgets;
	static shared_ptr<Widget> createWidget(const string& name);
	void displayAll() const;
};


