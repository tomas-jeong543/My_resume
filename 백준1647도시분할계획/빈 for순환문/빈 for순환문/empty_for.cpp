#include<iostream>

int main()
{
	using namespace std;
	//몸체 부분을 비원서 아무 것도 수행하지 않도록 할 수 있다 이런 경우 널문장 으로 몸체 대신한다
	for (int i = 0; i < 5; std::cout << "i: " << i++ << std::endl)
		;

	//중첩된 순환문

	int rows, colums;
	char theChar;
	cout << "how many rows?";
	cin >> rows;
	cout << "how many colums?";
	cin >> colums;
	cout << "What chracter? ";
	cin >> theChar;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colums; j++) {
			cout << theChar;
		}
		cout << "\n";
	}
	return 0;
}