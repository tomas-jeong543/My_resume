#pragma once
#include<iostream>
#include<memory>

class Point
{
private:
	std::shared_ptr<int>  xpos;
	int* ypos;
public:
	Point() = default;
	Point(const int& x, const int& y);
	~Point() {
		delete ypos;
	}
};

