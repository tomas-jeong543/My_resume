#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // !DBG_NEW
#endif

#include"JMHSubjectManger.h"
#include<memory>

using namespace std;
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	cout << "202211364 정명훈" << endl;
	//JMHStudent greenjoa1;
	JMHStudent greenjoa2("2022", "아이유");

	//JMHSubject subject1;
	JMHSubject subject2("이산수학","홍길동", "401호",3);
	subject2.printinfo();

	if (subject2.registerStudent(greenjoa2)) {
		cout << "등록 성공" << endl;
	}
	else {
		cout << "정원 초과로 등록 불가" << endl;
	}
	subject2.printinfo();

	if (subject2.cancelRegistration(greenjoa2.getid())) {
		cout << "취소 성공" << endl;
	}
	else {
		cout << "등록된 학생이 아님" << endl;
	}
	subject2.printinfo();

	if (subject2.changeClassroom("404호", 6)) {
		cout << "강의실 이동 완료" << endl;
	}
	else {
		cout << "강의실 이동 실패" << endl;
	}
	subject2.printinfo();

	JMHSubjectManger mgr(5);
	mgr.loadFromFile("subjectdata.txt");

	mgr.run();
}