#include "JMHSubject.h"

bool JMHSubject::registerStudent(JMHStudent& ins)
{
	if (curnum < seatnum) {
		stdinfoarr[curnum] = &ins;
		curnum += 1;
		return true;
	}
	else {
		return false;
	}
}

bool JMHSubject::cancelRegistration(const string& idinfo)
{
	for (int i = 0; i < curnum; i++) {
		if (stdinfoarr[i]->getid().compare(idinfo) == 0) {
			
			for (int j = i; j < curnum; j++) {
				stdinfoarr[j] = stdinfoarr[j + 1];
			}
			curnum -= 1;
			return true;
		}
	}
	return false;
}

bool JMHSubject::changeClassroom(const string& lecroominfo, const int seatnum)
{
	if (lecroominfo.compare(this->Lecture_room) != 0 && seatnum > this->seatnum) {
		
		JMHStudent** ins = new JMHStudent*[seatnum];

		for (int i = 0; i < curnum; i++) {
			ins[i] = stdinfoarr[i];
			delete stdinfoarr[i];
		}
	
		stdinfoarr = ins;
		this->seatnum = seatnum;
		return true;
	}
	return false;
}
