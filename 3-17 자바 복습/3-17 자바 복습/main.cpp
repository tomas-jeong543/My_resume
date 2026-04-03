#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main()
{
	int num{ 3 };
	int zero {};
	cout << "num: " << num << endl;
	cout << "zwro: "<<   zero << endl;
	
	double ins = 3.142132;
	//문자열이 아닌 변수를 문자열로 만드는 함수
	string ins_str = to_string(ins);
	
	cout << ins_str + "r" << endl;

	string str_num = "1234";
	int num_integer = stoi(str_num);

	cout << num_integer + 12 << endl;

	return 0;
}