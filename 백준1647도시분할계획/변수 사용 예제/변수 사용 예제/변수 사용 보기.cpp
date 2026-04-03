#include <iostream>
//형 변환으로 복잡한 단위 단순화
typedef unsigned  short int USHORT;

int main()
{
	using std::cout;
	using std::endl;
	using std:: cin;
	USHORT width = 5, length;
	length = 10;

	USHORT Area = (width * length);

	cout << "weight: " << width << endl;
	cout << "length: " << length << endl;
	cout << "Area: " << Area << endl;
	
	// 숫자 범위가 넘어가면 0부터 다시 시작한다
	unsigned short limiter = 65535;
	cout << limiter << endl;
	// ++을 cout 중 너으면 연산자 우선순위에 의해 뒤에 있는 내용부터 출력됨
	cout << limiter << " a " << limiter++ << "b" << limiter++ << endl;
	return 0;
}