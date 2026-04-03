#include<iostream>
using namespace std;

void ex01()
{
	int arr[3][4];
	//배열의 이름은 타입 그럼으로 포인터 사용시에는 주의해야 한다 어느 배명을 가르키느냐에 따라 +1할 때마다 점프하는 크기가 달라진다
	cout << typeid(arr).name() << endl;
	cout << typeid(&arr).name() << endl;
	cout << typeid(arr[0]).name() << endl;
	cout << typeid(&arr[0]).name() << endl;
	cout << typeid(arr[0][0]).name() << endl;
	cout << typeid(&arr[0][0]).name() << endl;
}


bool Det_End( bool(*seat)[4]) {
;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (!seat[i][j])
				return false;
		}
	}
	return true;
}

void ex02()
{
	constexpr int COL = 4;
	constexpr int ROW = 6;
	const char tab = '\t';
	bool seats[ROW][COL]{};

	while (true) {
		system("cls");
		for (int j = 1; j < COL + 1L; j++)
			cout << tab << j;
		cout << endl;

		for (int i = 0; i < ROW; i++) {
			//char형태로 형변환을 하고 영어로 열을 출력하는 장면이다
			cout << static_cast<char>('A' + i) << tab;
			for (int j = 0; j < COL; j++) {
				//삼항 연산자의 사용 예시
				cout << (seats[i][j] ? "●" : "○") << tab;
			}
			cout << endl;
		}

		char x, y;
		cout << "좌석 입력(ex A1): 모든 자석이 다 예메되면 프로그램이 종료됩니다 ";
		cin >> x >> y;

		if (x == tab && y == tab) {
			break;
		}

		if (x - 'A' > 5 || x - 'A' < 0 || y - '1' > 3 || y - '1' < 0) {
			cerr << "범위내 숫자를 입력하시오\n";
			system("pause");
			continue;
		}

		if (seats[x - 'A'][y - '1']) {
			cout << "예약 불가" << endl; 
		}
		else {
			seats[x - 'A'][y - '1'] = true;
			cout << "예약 완료" << endl;
		}
		
		if (Det_End(seats)) {
			cout << "프로그램 종료" << endl;
			break;
		}

		system("pause");
	}
}

void ex03()
{

	//모든 포인터 타입은 크기가 동일하다
	/*cout << sizeof(int*) << endl;
	cout << sizeof(double*) << endl;
	cout << sizeof(char*) << endl;
	cout << sizeof(float*) << endl;*/
	
	int* ptr = new int;
	*ptr = 200;
	cout << "값: " << *ptr << "\t값이 저장된 힙의주소:" << ptr << "포인터의 주소: " << &ptr << endl;
	//힙 영역 삭제
	delete ptr;
	//ptr 출력 오류 발생이 가능함으로 주의 필요 컴퓨터 프로그램이 깨질 수 있다
	//cout << ptr << endl;
	ptr = nullptr;


	int* ptr2 = new int[3];
	*(ptr2 + 1) = 100;
	cout << ptr2[1] << '\t' << &ptr2[0]<< "\t" << ptr2 << endl;
	delete []ptr2;
	ptr2 = nullptr;

	int** ptr3 = new int*[3];

	for (int i = 0; i < 3; i++) {
		*(ptr3 + i) = new int[3];
	}

	for (int i = 0; i < 3; i++) {
		delete[] ptr3[i];
	}
	delete[] ptr3;
}

int main()
{
	cout << "202211364 정명훈\n";
	ex01();
	return 0;
}
