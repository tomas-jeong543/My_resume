#include<iostream>
#include<string>
#include"Power.h"
using std::ostream;
using std::cout;
using std::endl;
//using namespace std;

//전역함수로 만드는 이유 앞에 내가만든 객체가 오지 않는 경우에 사용 + 접근 필요한 객체에는 friend함수로 선언이 필요하다. 전역함수는 웬만하면 cpp 파일에 작성하는 것이 좋다.
ostream& operator<<(ostream& out, const Power& p)
{
	out << "kick=" << p.kick << "," << "punch=" << p.punch << endl;
	return out;
}


int main()
{
	cout << "202211364 정명훈" << endl;
	Power a(3, 5), b(4, 6);

	Power c(0, 0);
	 c = a += b;
	 a += 1;
	//내가 만든 데이터 앞에 오고 출력 버퍼 뒤에 오게 함 하지만 사실상 이건 안 쓰는 게 맞다. 나 빼곤 이해 불가능
	//a << cout;
	//b << cout;

	//전역함수 남들도 사용 및 이해가 쉬운 코드를 작성이 가능하다 또한 cin을 이용해서 입력을 받을 수도 있다.
	cout << a;
	cout << b;
	cout << c;
	cout << "---------------------------------------------------------------------" << endl;
	Power d(0, 0);
	cout << &d << endl;
	d << 1 << cout << 2 << cout << 3 << cout << 4 << cout;
	cout << &d << endl;

	cout << "---------------------------------------------------------------------" << endl;
	Power e(0, 0);
	Power f(0, 0);
	Power g(0, 0);
	//0저장 후 -1로 바뀐다
	f = e--;
	//-1에서 -2로 바뀐 뒤에 저장된다
	g = --e;
	cout << g;
	cout << f;
	/*Power c = a + b;
	a.show();
	b.show();
	c.show();*/

	// b = a + 2는 +이항 연산자 오퍼레이터로 해결 가능   
	// 문제점 -> b = 2 + a , cout << a << b 연산자 압에 우리가 만든 클래스가 안 오는 경우
	//해결 방법 friend를 사용해서 클래스나 함수를 추가할 수 있다.

	cout << "---------------------------------------------------------------------" << endl;
	Power l(3, 5);
	int powerL = l;
	cout << powerL << endl;
	return 0;
}