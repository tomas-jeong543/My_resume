#include<iostream>

using namespace std;

class Rectangle
{
private:
	int its_length;
	int its_width;
public:
	Rectangle();
	~Rectangle();
	void Set_Length(int length) { its_length = length; }
	void Set_Width(int width) { its_width = width; }
	int Get_Length() const { return its_length; }
	int Get_Width() const { return its_width; }

};