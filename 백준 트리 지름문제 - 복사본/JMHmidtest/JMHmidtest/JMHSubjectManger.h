#pragma once
#include"JMHSubject.h"

class JMHSubjectManger
{
private:
	const int possible_classnum;
	JMHSubject** subjectinfoarr;
	int curclassnum = 0;
public:
	JMHSubjectManger(int num) :possible_classnum(num){
		subjectinfoarr = new JMHSubject*[num];
		if (subjectinfoarr == nullptr) { cout << "메모리 오류" << endl; return; }
	}
	~JMHSubjectManger() {
		for (int i = 0; i < curclassnum; i++) {
			delete[] subjectinfoarr[i];
		}
		delete[] subjectinfoarr;
	}

	void loadFromFile(const string& filename);
	void run();
	void addlec();
};

