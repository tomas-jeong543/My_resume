#include<iostream>

int fib(int position);

int main()
{
	using namespace std;
	int answer, position;
	cout << "which position? ";
	cin >> position;
	cout << "\n";

	answer = fib(position);
	cout << answer << "is the ";
	cout << position << "the Fibonacci number. \n";
	return 0;
}

int fib(int n)
{
	int Minus_Two = 1, Minus_One = 1, answer = 2;

	if (n < 3)
		return 1;
	
	for (n -= 3; n; n--)
	{
		Minus_Two = Minus_One;
		Minus_One = answer;
		answer = Minus_One + Minus_Two;
	}

	return answer;
}