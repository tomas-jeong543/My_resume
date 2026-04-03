#include"Pegasus.h"

enum TYPE{ HORSE, PEGASUS};
const int Num_Horse = 5;


/*
* 공통 기능 부분을 상속 계층에서 윗부분으로 올린다 실행 시 객체형에 형 반환 사용을 피한다 가상 메소드 템플릿 다중 상속을 이용한다
* 하지 말아야 하는 것은 상호 접속 부분을 상송 계층 윗부분으로 올리지 말고 파생 클래스로 형 변환해 하향시키는 것을 피한다
*/
int main()
{
	Horse* Ranch[Num_Horse];
	Horse* pHorse;
	int choice, i;
	for (i = 0; i < Num_Horse; i++) {
		cout << "1)Horse (2)Pegasus: ";
		cin >> choice;
		if (choice == 2)
			pHorse = new Pegasus;
		else
		pHorse = new Horse;

		Ranch[i] = pHorse;
	}
	cout << "\n";

	//되게 좋지 않은 함수 객체 지향 프로그래밍의 다형성을 해친다
	for (int i = 0; i < Num_Horse; i++) {
		Pegasus* pPeg = dynamic_cast<Pegasus*>(Ranch[i]);
		if (pPeg)
			pPeg->Fly();
		else
			cout << "just a horse \n";
	}
	return 0;
}
