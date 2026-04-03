#include<iostream>
//인라인 함수 c언어의 메크로와 유사하면사 약간 다른 개념 한줄이나 두 줄로 해결되는 경우에 사용된다는 점에서 유사하지만
// 메크로와는 달리 호출시 그 함수로 들어가는 게 아닌 메모리에 저장된 코드 1-2줄을 꺼내서 실행하는 방식이다 호출에 사용되는
//메모리를 획기적으로 줄일 수 있다
inline int Double(int);

int main()
{
	int target;

	using std::cout;
	using std::endl;
	using std::cin;

	cout << "Enter a number to work with";
	cin >> target;
	cout << "\n";

	target = Double(target);
	cout << "Target: " << target << endl;

	target = Double(target);
	cout << "Target: " << target << endl;

	target = Double(target);
	cout << "Target: " << target << endl;

	return 0;
}

int Double(int target)
{
	return target * 2;
}
