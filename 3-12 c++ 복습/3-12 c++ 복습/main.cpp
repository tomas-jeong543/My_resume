#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void Define_And_Init()
{
	//c++에서는 크게 세가지 선언방식이 존재한다

	//1번 복사형 정의 방식으로 이 방식은 c에서와 동일하다
	char c = 'c';
	//직접 초기화 하는 방식
	int num(7);
	//유니폼 초기화 방식으로 이 방식을 사용해서 초기화 방식을 통일할 수 있어 유용하게 쓰인다
	double interest_rate = { 0.05 };
	
	//유니폼 초기화의 3가지 방식
	
	double num1 = { 3.21 };
	double num2{ 3.4545 };
	//아무것도 넣지 않으면 0으로 값이 초기화된다
	double e{};

}
//c++에서는 배열 대신에 문자열을 나타낼 때 string을 이용한다 이 때 무조건 표준 스트링 해더 파일을 포함하고 있어야 한다
void Info_String()
{
	string a1 = "tomas";
	string a2 = "antttttttttttttttttttt";

	//문자열의 비교는 ,=,으로 가능하다 길이가 같으면 >,< 기호도 이용 가능하다
	//길이가 다르면 compare함수를 이용하는데 이는 c언어의 strcmp(s1,s2)와 동일하다 
	//a2가 a1 앞에 존재하는 경우에는 음수 반환 뒤에 있으면 양수를 반환한다
	if (a2.compare(a1) > 0) {
		cout << "true" << endl;
	}
	else
		cout << "false" << endl;

	//문자열을 숫자로 숫자를 문자열로 바꾸는 함수들의 예제
	double radius = 3.14;
	string radius_Str = to_string(radius);
	double radius_copy = stod(radius_Str);
	cout << radius_Str << endl;
	cout << radius_copy << endl;

	//str.length()는 문자열의 길이를 반환하는 함수 str.empty()는 문자열이 비었는지를 확인하는 함수
	string line, content;

	do {
		cout << "문자열을 입력하십시오 (종료조건 앤터키): ";
		getline(cin, line);
		content += line + " \n";
		//입력 버퍼를 비우는 함수
		//cin.ignore()

	} while (!line.empty());

	cout << content << endl;

	//문자열에 대한 접근은 str[i] 나 str.at(i)등으로 접근 가능하다
	string test_String = "s12s45";

	cout << test_String.at(3) << endl;
	cout << test_String[3] << endl;

	cout << endl;
	//또한 front 와 back은 문자열의 양 끝 부분에 대한 참조자를 전달한다
	string exstr = "my_string";
	//각 문자열의 끝과 앞 부분의 참조자를 보내기 때문에 그 문자의 주소와 값이 같다 하나의 분신인 셈
	char &a = exstr.front();
	char &b = exstr.back();

	cout << a << " " << exstr.at(0) << endl;
	cout << (void*)&a << " " << (void*)&exstr[0] << endl;
}

void Modify_String()
{
	string str = "Hello";
	string str2 = "world!";

	cout << str << endl;
	//append기능은 파이썬과 유사 하지만 뒤에 두 공간에 시작점과 끝점을 지정하는 것이 가능하다
	str.append(str2, 0, 5);
	cout << str << endl;
	//insert는 파이썬과 동일하다
	str.insert(5, " ");
	cout << str << endl;
	//erase 문자열을 지우는 함수 시작점과 끝 점을 적어야 한다
	str.erase(6, 10);
	cout << str << endl;
	//reolace 문자열 내용을 다른 문자열로 바꾸는 매소드
	str.replace(1, 4, "ELLO");
	//swap 두 문자열을 바꾸는 함수
	str.swap(str2);
	cout << str << endl;

	//find 문자열 안에 명시된 문자열을 반환하는 함수  있으면 true 없으면 flase반환
	string str_info1("There are two needles in this haystack with needles.");
	string str_info2("needle");
	size_t found = str_info1.find(str_info2); // 14
	if (found != string::npos)
		cout << "first 'needle' found at: " << found << '\n';
}


void String_info()
{
	string str = "We think in generalities, but we live in details";
	string info = str.substr(3, 5);
	cout << "info: " << info << endl;
	size_t pos = str.find("live");
	string info2 = str.substr(pos);
	cout << "info2: " << info2 << endl;
}

int main()
{

	String_info();
	return 0;
}