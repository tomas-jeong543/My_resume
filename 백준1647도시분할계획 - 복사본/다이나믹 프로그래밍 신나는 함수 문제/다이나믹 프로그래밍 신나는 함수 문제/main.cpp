#include<iostream>
#include<string>
#include<sstream>
#include<unordered_map>
//쉬운 난이도의 동적할당 문제 메모제이션만 해시맵을 이용해 잘구현 하면된다
using namespace std;
long callstack = 0;
unordered_map<string, long long> info;

long long w(int a, int b, int c)
{
	//메모제이션을 구현 하는 파트 숫자를 문자로 바꾸고 그 문자사이에 구분자 문자를 넣어 키가 중복되지 않도록 만들고 만약 해시 맵에 그 키가 존재하면 그 키의 value값을 반환한다
	string as , bs, cs;
	as = a + '0';
	bs = b + '0';
	cs = c + '0';
	string key = as + ":" + bs + ":" + cs;
	
	if (info.count(key) != 0)
		return info[key];

	if (a <= 0 || b <= 0 || c <= 0) {
		info[key] = 1;
		return 1;
	}
	else if (a > 20 || b > 20 || c > 20) {
		info[key] = w(20, 20, 20);
		return info[key];
	}
	else if (a < b && b < c) {
		info[key] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
		return info[key];
	}
	else {
		info[key] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
		return info[key];
	}


}

int main()
{
	string str_info;
	int a, b, c;
	cin >> a >> b >> c;

	while (a != -1 || b != -1 || c != -1) {
		
		cout << "w(" << a << "," << b << "," << c << ") = " << w(a, b, c) << endl;
		cout << callstack << endl;
		cin >> a >> b >> c;
	}
	return 0;
}