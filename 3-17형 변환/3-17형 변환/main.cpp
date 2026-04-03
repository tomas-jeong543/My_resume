#include<iostream>
#include<string>

using namespace std;

void ex01()
{
	//const cast는 const자료형을 없애거나 const자료형을 만들 수 있다
	const string &  a = "c++";
	string& b = const_cast<string&>(a);
	b = "java";
	cout << "A: " << a << " B: " << b;

	const string& c = b;
	//형을 상수형으로 만드는 방법은 직접적인 타입 캐스팅과 as_const을 이용한 방법이 있다
	const string& d = const_cast<const string&>(b);
	const string& e = as_const(b);
	
	cout << "C: " << c << endl;

	//이를 통해 세 참조자 모두다 같은 값과 주소를 갖고 있음을 알 수 있다
	cout << "adress\n";
	cout << "A: " << &a << " B: " << &b << " C: " << &c << endl;

	//static_cast 우리가 흔히 c에서 다루던 명시적인 형 변환이다 이를 조금 더 안전하게 사용하기 위한 방법이라고 생각하면 된다
	double radius = 3.14;
	int num = static_cast<int>(radius);
	//비록 소수점 아래 부분이 삭제 되었지만 그 값이 int로 형 변환이 잘 이루어졌음을 알 수 있다
	cout << "radius(double): " << radius << " radius(int): " << num << endl;

	//reinterpret_cast()가장 강한 형변환 기능으로 웬만한 형변환은 다 해주지만 그에 따른 큰 부작용은 프로그래머 본인이 감당해야 한다 따라서 void포인터를 명시적으로
	//나타내는 경우와 같이 제한적인 상황을 제외하고는 거의 사용되지 않는다
	
	//아래와 갗이 static_cast에서는 허용되지 않는 형 변환이 가능하다 하지만 안 하는 것이 더 낳다
	//char* ptr = reinterpret_cast<char*>( &num);

}

//auto와 decltype의 차이를 알기 위해 만든 함수
const string& getString() {
	const string message = "Greenjoa";
	return message;
}

void ex02()
{

	//auto는 컴파일러가 자동으로 형식을 규정하는 자료형이다 초기값에 맞추어 인스턴스 값이 정해진다 하지만 그 과정에서 찹조 연산자나 const 는 반영되지 않는다
	int num_num = 5;
	auto num2 = num_num;
	cout << "type(num2): " << typeid(num2).name() << endl;
	//decltype(expr) : Expr과 동일한 자료형으로 선언한다는 의미로 const와 참조자 역시 포함이 된다 
	
	auto var1 = getString();
	decltype(getString()) var2 = getString();
	var1 = "Greenbad";
	//아래 문장은 실행가능하지 않다 왜냐하면 상수형 참조자 변수이기 때문에 내용을 변경할 수 없기 때문이다
	//var2 = "greenbad";
}

void ex03()
{
	//콤마 연산자 마지막 가장 오른쪽에 있는 값만 반환이 된다
	int a, b;
	a = (b = 3, b + 7);
	cout << "a: " << a << " b: " << b << endl;

	//c++에는 두가지 상수형 변수가 존재하는 데 const는 runtime 때 정해지면 되는 상수이고 constexpr은 컴파일 시간에 정해져야 되는 상수이다
	//안정성은 constexpr이 당연히 더 높고 배열의 크기를 설정하는 등 미리 정해져야 할 때 사용된다
}


void ex04()
{
	constexpr int row = 6;
	constexpr int col = 4;
	int musem[row][col]{};

	string seat = "0";

	while (seat != "종료") {
		cout << "좌석을 선택하세요 예(A1): ";
		getline(cin, seat);
		
		int row_info = int(seat[0]);
		row_info -= 65;
		int col_info = seat[1] - '0';

		cout << row_info << endl;
		cout << col_info << endl;
		if (row_info > 5 || row_info < 0 || col_info >= 4 || col_info < 0) {
			cerr << "잘못된 형식입니다 다시 입력해주세요" << endl;
			continue;
		}

		if (musem[row_info ][col_info] == 0) {
			cout << "예약 완료\n";
			musem[row_info][col_info] = 1;
		}
		else
			cout << "예약 불가\n";
	}

}

int main()
{
	ex01();
	return 0;

}