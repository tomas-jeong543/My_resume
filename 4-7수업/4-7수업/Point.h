#pragma once
class Point
{
private:
	int x, y;
public:
	Point() = delete;
	Point(int x);
	Point(int x, int y);
	void DrawPoint();
	int Getx() { return x; }
	int Gety() { return y; }
	~Point();

};

