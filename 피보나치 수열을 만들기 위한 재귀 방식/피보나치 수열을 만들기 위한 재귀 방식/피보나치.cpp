#include<iostream>

//재귀함수와 메모제이션을 이용한 피보나치 수열을 구하는 과정 
int fib_num[10000] = { 0 };

int fib(int n);

int main()
{
	fib_num[1] = 1;
	fib_num[2] = 2;
	int n, answer;
	using namespace std;

	cout << "Enter the number to find:";
	cin >> n;
	cout << "\n\n";

	answer = fib(n);

	cout << answer << "is the" << n;
	cout << "the Fibonaci number\n";

	for (int i = 0; i < n; i++) {
		cout << fib_num[i] << "  ";
		if (i % 10 == 0 && i > 0)
			cout << endl;
	}

	return 0;
}

int fib(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 1;

	if (fib_num[n] != 0)
		return fib_num[n];
	else
		fib_num[n] = fib(n - 1) + fib(n - 2);
		return fib_num[n];
}