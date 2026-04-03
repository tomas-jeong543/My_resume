#include<iostream>

typedef unsigned long ULONG;

int main()
{
	using namespace std;
	unsigned short small;
	ULONG large;
	ULONG skip;
	ULONG target;
	const unsigned short MAXSMALL = 65535;

	cout << "Enter a small number: ";
	cin >> small;
	cout << "Enter a large number: ";
	cin >> large;
	cout << "Enter a skip number: ";
	cin >> skip;
	cout << "Enter a target number: ";
	cin >> target;

	cout << "\n";

	while (small < large && large > 0 && small < MAXSMALL)
	{
		small++;
		//작은 수가 스킵해야 하는 수의 배수이면 큰 수를 2 증가시키지 않는다
		if (small % skip == 0)
		{
			cout << "skiping on " << small << endl;
			continue;
		}
		
		//큰 수가 목표수에 도달시 반복문을 빠져나간다
		if (large == target)
		{
			cout << "Target reached";
			break;
		}
		
		//큰 수는 2 감소
		large -= 2;
	}
		
	cout << "\nsmall: " << small << " large: " << large;
	return 0;
}