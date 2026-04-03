#include<fstream>
#include<iostream>
#include<sstream>

using namespace std;

typedef struct {

	string name;
	int age;
	double grade;

}Person;

int main() {

	int n = 0;
	Person* Stdlist;
	//fin에 data.txt파일이 들어간다
	ifstream fin("data.txt");
	
	//파일에 적는 과정 복사본 만들기
	ofstream fout("data2.txt"); //파일 생성
	fout << "202211364 정명훈" << endl;
	
	//나먼의 입출력 버퍼를 선언
	stringstream buf;
	string line;

	//만약 파일이 열린 경우에 대해
	if (fin.is_open()) {
		//파일의 끝에 도달하기 전까지
		while (!fin.eof()) {
			//줄 수 측정
			n += 1;
			//줄 정보를 string변수인 line에 저장
			getline(fin, line);
			//새로만든 복사본에 줄 정보를 저장한다.
			fout << line << endl;
		}
	}

	cout << endl;
	//구조체 변수의 선언
	Stdlist = new Person[n];
	//파일 닫기
	fin.close();
	//파일 다시 열기
	fin.open("data2.txt");

	//파일이 열렦다면
	if (fin.is_open()) {
		//파일 끝 도달할 때까지 반복
		string ins;
		while (!fin.eof()) {
			//문자열에 줄 정보 저장
			getline(fin, line);
			//문자열을 입력 버퍼에 넣어줌
			buf << line;
			//입력 버퍼에 있는 내용을 비교해 하나씩 출력
			while (buf >> ins) {
				cout << ins << endl;
			}
			//입력 버퍼 비워주기
			buf.clear();
			cout << endl;
		}
	}


	
	
	delete[] Stdlist;
}