#include"godgil.h"
#include"godhong.h"
#include<iomanip>
//string은 네임스페이스 필요
#include<string>
//본인만의 입출력 버퍼를 만드는 것 입력과 출력 버퍼로 사용가능
#include<sstream>
//c++에서는 변수가 사용하기 직전에만 선언되어 있으면 된다. 자유롭게 선언이 가능하다는 이야기
using namespace std;
void example01()
{
	for (int i = 1; i <= 9; i++) {
		for (int j = 2; j < 9; j++) {
			cout<< setw(2) << j << " *"<< setw(2) << i << " = " << setw(2)<< j * i << "\t";
		}
		cout << " \n";
	}
}

void example02()
{
	int start, end;
	char check;
	cout << " 구구단의 시작과 끝단을 입력하시오:";
	cin >> start >> end;

	if (start > end) {
		cout << "시작 숫자가 끝 숫자 보다 작거나 같아야 합니다 시작과 끝 값을 바꿩서 출력할까요(y,n)";
		cin >> check;
		if (check == 'y' ) { 
			int temp;
			temp = start;
			start = end;
			end = temp;
		}
		else if(check == 'n') {
			return;
		}
		else {
			cout << "잘못된 문자 입력";
			return;
		}
	}

	for (int i = 1; i <= 9; i++) {
		for (int j = start; j < end + 1; j++) {
			cout<< setw(3) << j << " * " << i << " = "<< setw(2) << i * j;
		}
		cout << endl;
	}
}

void example03()
{
	int age;
	string name, addr;
	//공백으로 문자열 여러개 입력이 가능하다 구분은 스페이스로 하고 앤터는 cin에서는 그냥 무시한다
	cout << "나이와 이름:";
	cin >> age >> name;
	//입력 버퍼를 enter가 100개의 문자가 나오기 전에 나오면 거기까지 버퍼를 비우고 아니면 100개의 문자를 비우는 함수이다
	cin.ignore(100, '\n');

	//이런 경우에는 enter가 입력 버퍼에 남아 있으면 getline이 종료된다
	//스페이스가 입력으로 들어간다는 점 주의
	getline(cin, addr);
	cout << "age: " << age << " name: " << name <<  " " << "adress: " << addr;

}

void example04()
{
	string data;
	int sum = 0;
	cout << "Enter your data(name kor eng math)";
	getline(cin, data);
	//cin에다가 원하는 값들이 담겼다고 생각하고 이 객체를 이용해서 각 변수에 원하는 값을 추출한다 주로 파일에서 정보 추출할 때 사용
	stringstream ss(data);
	string name;
	
	ss >> name;
	int tmp;
	while (ss >> tmp) {
		ss >> tmp;
		sum += tmp;
	}

	cout << "name: " << name << " " << sum << endl;
}

//문자열은 string타입 해더 파일 인클루드 필요
//size_t == unsigned int
int main()
{
	cout << "202211364 정명훈" << endl;
	
	example03();

	/*string name;
	cin >> name;
	cout << name << "님 환영합니다\n";*/


	/*/godohongNS::Show_Name();
	gdonggoNS::Show_Name();
	cout << showpoint << 1.232;*/
	return 0;
}
