#include "JMHSubjectManger.h"
#include<fstream>

using namespace std;
void JMHSubjectManger::loadFromFile(const string& filename)
{
	ifstream fin(filename);
	if (!fin.is_open()) {
		cerr << "파일 읽기 실패\n";
		return;
	}

	while (!fin.eof()) {
		int linenum = 0;
		string sub;
		string pname;
		string lecroomname;
		int seatinfo;

		string str;
		string target = " ";
		getline(fin, str);
		int frontpos = 0;
		int pos = str.find(target);

		while (pos < str.length()) {
			if (linenum == 0) {
				sub = str.substr(frontpos, pos);
				frontpos = pos + 1;
				pos = str.find(target, pos + 1);
			}
			else if (linenum == 1) {
				pname = str.substr(frontpos, pos);
				frontpos = pos + 1;
				pos = str.find(target, pos + 1);
			}
			else if (linenum == 2) {
				lecroomname = str.substr(frontpos, pos - frontpos);
				frontpos = pos + 1;
				pos = str.find(target, pos + 1);
				
			}
			
			linenum += 1;
		}
		seatinfo = (int)(str[str.length() - 1]);

		if (curclassnum >= this->possible_classnum) {
			return;
		}
		subjectinfoarr[curclassnum++] = new JMHSubject(sub,pname, lecroomname, seatinfo - 48);
	}
}

void JMHSubjectManger::run()
{
	system("cls");
	int opt = -1;
	while (opt != 0) {
		for (int i = 0; i < curclassnum; i++) {
			subjectinfoarr[i]->displaysubject();
		}

		cout << endl;
		cout << "1)수강신청 2)수강취소 3)강의실 이동 4)과목정보 0)종료" << endl;
		cin >> opt;
		if (opt > 4 && opt << 0) {
			cout << "잘못된 선택" << endl;
			system("pause");
		}
		else {
			switch (opt) {
			case 1:addlec(); break;
			}
		}
	}
	
	cout << "프로그램 종료" << endl;

}

void JMHSubjectManger::addlec()
{

}
