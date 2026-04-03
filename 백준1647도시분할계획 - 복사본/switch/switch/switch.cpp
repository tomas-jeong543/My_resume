#include<iostream>

int main()
{
	using namespace std;
	unsigned short int number;
	cout << "Enter a number beteween 1 and 5: ";
	cin >> number;


	switch (number)
	{
	case 0:  cout << "Too small Sorry!";
		break;
	case 5:  cout << "Good job!\n";
	case 4:	 cout << "Nice Pick!\n";
	case 3: cout << "Excellent!\n";
	case 2: cout << "Masterful! \n";
	case 1: cout << "Incredible! \n";
		break;
	//스위치 문에서는 항상 default값을 갖는 것이 중요하다 심지어 default값을 쓸 일이 없다고 해도 오류 생각해 만들어 놓는 것은
	//버그를 찾는 데 상당히 도움이 된다

	/*
		무한 순환문은 이렇게 쓰는 프로그래머도 존재
		#define EVER;
		for (EVER)
		{
			/// 문장들
		}
		이렇게 쓰면 무조건 break문을 써야 탈출할 수 있다
	*/
	default: cout << "Too large!\n";
		break;
	}
	cout << "\n\n";
	return 0;
}