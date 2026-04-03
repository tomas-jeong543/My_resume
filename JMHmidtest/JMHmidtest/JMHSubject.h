#pragma once
#include"JMHStudent.h"

using namespace std;

class JMHSubject
{
private:
	string Subjectname;
	string  Pname;
	string  Lecture_room;
	int seatnum;
	JMHStudent** stdinfoarr;
	int curnum = 0;
public:
	JMHSubject() = delete;
	JMHSubject(string sub, string pname, string lecroom, int seat) :Subjectname(sub), Pname(pname), Lecture_room(lecroom), seatnum(seat)
	{
		stdinfoarr = new JMHStudent*[seat];
	}

	void printinfo()const {
		cout << "[" << Subjectname << "]" << " " << Pname << " (" << curnum << "/" << seatnum << ")" << "Room: " << Lecture_room << endl;
		cout << "<<수강생 목록>>" << endl;
		if (curnum == 0) {
			cout << "등록한 학생이 없습니다" << endl;
		}
		else {
			for (int i = 0; i < curnum; i++) {
				stdinfoarr[i]->display();
			}
		}
	}
	~JMHSubject() {
		for (int i = 0; i < curnum; i++) {
			if (stdinfoarr[i] != nullptr) {
				delete stdinfoarr[i];
			}
			
		}
		delete[] stdinfoarr;
	}

	bool registerStudent(JMHStudent& ins);

	bool cancelRegistration(const string& idinfo);

	bool changeClassroom(const string& lecroominfo, const int seatnum);
	void displaysubject() {
		cout << "[" << Subjectname << "]" << " " << Pname << " (" << curnum << "/" << seatnum << ")" << "Room: " << Lecture_room << endl;
	}
};

