#include<iostream>

int main()
{
	using namespace std;
	int counter;
	cout << "How many Hellos?";
	cin >> counter;
	//do while문을 쓰는 경우 적어도 한번은 반복문이 돌아가야 할 때
	//조건이 거짓일 때 순환문이 실행되길 바라지 않는다면 while문을 이용한다
	//또한 반복문은 내가 원하는 대로 작동하는지 늘 확인해야 한다
	do 
	{
		cout << "Hello\n";
		counter--;

	} while (counter > 0);

	cout << "counter is: " << counter << endl;
	return 0;

}