#include<iostream>

int main()
{
	using std::cout;
	using std::endl;

	int a = 0, b = 0, x = 0, y = 35;
	cout << "a: " << a << "b: " << b;
	cout << "x: " << x << "y: " << y << endl;
	a = 9;
	b = 7;
	y = x = a + b;
	cout << "a: " << a << "b: " << b;
	cout << "x: " << x << "y: " << y << endl;

	//연산자 우선순위 똑같은 우선순위에서는 왼쪽부터 오른쪽으로
	//아니면 우선순위가 높은 것부터 진행된다
	//ex
	x = 5 + 3 + 8 * 9 + 6 * 4;
	cout << "x: " << x;
	return 0;
}
