// 또한 전처리계는 컴파일 이전에 라이브러리에서 제네럴 메소드나 객체를 받아오는 역할 수행
#include<iostream>
int Add(int x, int y)
{
	std::cout << "In Add(), received "<< x << " and" << y << "\n";
	return (x + y);
}
/*메인 함수의 특별한 점 바로 프로그램이 실행되면 자동으로 호출이 된다는 것이다
*다른 함수들은 그렇지 않다 또한 주로 정수를 반환하며 정상 종료인 경우에는 0을 반환한다
*/
int main() 
{
	using std::cout;
	using std::cin;

	cout << "I'm in main() ! \n";
	int a, b, c;
	cout << "Enter two numbers: ";
	cin >> a;
	cin >> b;
	cout << "calling add";
	c = Add(a, b);
	cout << "i am back to main";
	cout << "c was set to" << c << std::endl;
	cout << "exciting";
	return 0;

}