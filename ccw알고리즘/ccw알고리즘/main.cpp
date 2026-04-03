#include<iostream>
#include<sstream>

using namespace std;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3)
{
	int a = x1 * y2 + x2 * y3 + x3 * y1;
	int b = x2 * y1 + x3 * y2 + x1 * y3;

	return a - b;
}

int main()
{
	int x1, y1, x2, y2, x3, y3;

	cin >> x1 >> y1;
	cin.ignore();

	cin >> x2 >> y2;
	cin.ignore();

	cin >> x3 >> y3;
	cin.ignore();

	cout << ccw(x1, y1, x2, y2, x3, y3) << "\n";
}