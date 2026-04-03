#include<iostream>
#include<string>
#include<fstream>
using namespace std;
void ex01(){
	const int SIZE = 5;
	string Name_Arr[SIZE]{ "홍길동", "이길동", "김길동", "고길동", "박길동"};
	/*for (int i = 0; i < Name_Arr->length(); i++) {
		cout << Name_Arr[i] << endl;
	}*/
	//for each 구문
	for (string name : Name_Arr) {
		cout << name << "\t";
	}
	cout << endl;

	//선택 정렬 사전식 정렬 오름차순
	for (int i = 0; i < SIZE - 1; i++) {
		for (int j = i + 1; j < SIZE; j++) {
			//아니면 compare를 사용해서 풀 수도 있다 하지만 그냥 비교 연산자로 해도 된다
			if (Name_Arr[i] > Name_Arr[j]) {
				Name_Arr[i].swap(Name_Arr[j]);
			}
		}
	}

	for (string name : Name_Arr) {
		cout << name << "\t";
	}
}

void example02()
{
	ifstream fin("data.txt");
	if (!fin.is_open()) {
		cerr << "파일 읽기 실패";
		return;
	}
	string data;
	string target("int");
	while (!fin.eof()) {
		string str;
		getline(fin, str);


		data += str + " \n";

	}
	cout << data << endl;
	string findStr, replaceStr;
	cout << "찾을 문자열: ";
	//cin사용시 공백을 포함하는 문자열을 받을 수 없다
	getline(cin, findStr);
	cout << "바꿀 문자열: ";
	getline(cin, replaceStr);

	int pos = data.find(findStr);
	
	while (pos != string::npos) {
		int pos = data.find(findStr);
		if (pos == string::npos) {
			//cout << findStr << "문자열이 없음" << endl;
			break;
		}
		else {
			data.replace(pos, findStr.length(), replaceStr);
		}

		pos += 1;
		
	}
	cout << endl;
	cout << data << endl;
}


int main(){
	cout << "202211364 정명훈" << endl;
	example02();


	return 0;
}