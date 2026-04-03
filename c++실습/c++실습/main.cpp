
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // !DBG_NEW
#endif

//실습 shared  pointer로 바꾸어야 한다

#include<iostream>
#include<memory>
#include<string>
//파일에 읽고 쓰기를 위한 라이브러리
#include<fstream>


using namespace std;
using uniqueDptr = unique_ptr<unique_ptr<int[]>[]>;
using sharedDptr = shared_ptr<shared_ptr<int[]>[]>;

//cancel 은 좌석 번호 먼저 선택 그 이후 예약 번호 입력 받음 예약 번호가 같으면 좌석을 0으로 바꾸고 예약자 수 1 감소 
//아니면 안 함

//파일을 이용한 동적 메모리 할당 함수
sharedDptr Load_seat(const string& filename, int& row, int& col, int& reserved);

//메뉴를 출력하는 함수
void print_menu(sharedDptr(&seat), const int row, const int col, int& reserved);
// 메뉴 출력하는 함수에 포함된 세가지 기능의 함수
//1.좌석 예약 현황을 보여주는 함수
void Show_seat(sharedDptr(&seat), const int row, const int col);

//2.좌석을 예약하는 함수
void reserve_seat(sharedDptr(&seat), const int row, const int col, int & reserved);
//3.예약 번호를 통해 좌석 예약을 취소하는 함수
void cancel_seat(sharedDptr(&seat), const int row, const int col, int& reserved);
//파일에 좌석 정보를 저장하는 함수
void save_seats(const string& filename, sharedDptr(&seat), const int row, const int col);
void save_seats(const string& filename, sharedDptr(&seat), const int row, const int col);

//동적 메모리 해제 함수
//void delete_seats(uniqueDptr(&seat), const int row, const int col);
int main()
{
	//메모리 누수 체크
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// c 에서 seats로 텍스트 파일 바꾸기
	
	//기본 변수들 행과 열 그리고 예약자 숫자 정보 설정
	int row , col, reserved = 0;

	// 동적 메모리 할당하고 파일 정보와 참조자을 이용해 변수들을 초기화란다
	//데이터 반환이 가능하면 안되는데 왜 되느냐? 하지만 이는 대입 연산이 아니다 임시 변수로 의한 전달인 경우에는 얕은 복사 포인터만 연결해줌 사실상 자동으로 move
	sharedDptr seats = Load_seat("seat.txt", row, col, reserved);
	//예외 처리
	if (seats == nullptr) {
		cout << "오류 발생으로 프로그램 종료" << endl;
		exit(1);
	}

	//메뉴 실행
	print_menu(seats, row, col, reserved);
	
	//프로그램 종료 후에 데이터를 파일에 다시 저장하고 할당된 메모리를 회수한다
	save_seats("seat.txt", seats, row, col);
	//delete_seats(seats, row, col);
	
	return 0;
}

//void delete_seats(uniqueDptr(&seat), const int row, const int col)
//{
//	for (int i = 0; i < row; i++) {
//		delete[] seat[i];
//		seat[i] = nullptr;
//	}
//	delete[] seat;
//	seat = nullptr;
//}

void cancel_seat(sharedDptr(&seat), const int row, const int col, int& reserved)
{

	system("cls");
	Show_seat(seat, row, col);
	cout << "좌석 번호를 입력하시오:";
	
	char x;
	int y;
	cin >> x >> y;
	//예외처리는 하지 않음

	int r = x - 'A';
	int c = y - 1;


	if (x == '0' && y == 0) {
		cout << "메뉴로 이동합니다" << endl;
		return;
	}
	else if (r >= row || r < 0 || c >= col || c < 0) {
		cout << "잘못괸 좌석 번호를 선택햇습니다 메뉴로 이동합니다." << endl;
	}
	else if(seat[r][c] == 0){
		cout << "좌석이 예약되어 있지 않습니다\n";
	}
	else {
		//정상 좌석 위치 입력의 경우
		cin.ignore();
		int reserve_num = seat[r][c];
		int comp_num;
		cout << "예약 번호 입력: ";
		cin >> comp_num;

		//좌석의 예약 번호를 비교해 동일하면 취소 및 예약자 수를 1 감소 아니면 틀렸다는 것을 알려주고 다시 반환
		if (comp_num == reserve_num) {
			seat[r][c] = 0;
			cout << "예약이 취소되었습니다 메뉴로 이동합니다" << endl;
			reserved -= 1;
		}
		else {
			cout << "예약 번호가 틀렷습니다 메뉴로 이동합니다" << endl;
		}

		return;
	}

} 
void reserve_seat(sharedDptr(&seat), const int row, const int col, int& reserved)
{	
	while (true) {
		//좌석 상태를 먼저 출력
		system("cls");
		Show_seat(seat, row, col);
		if (reserved == row * col) {
			cout << "전 좌석이 예약 완료" << endl;
			return;
		}

		cout << "좌석을 입력해 주세요 ex)A1: " << endl << "좌석 입력: ";
		char x;
		int  y;
		cin >> x >> y;

		int r = x - 'A';
		int c = y - 1;

		if (x == '0' && y == 0) {
			cout << "메뉴로 이동합니다" << endl;
			system("pause");
			return;
		}
		else if (r >= row || r < 0 || c >= col || c < 0) {
			cout << "잘못괸 좌석 번호를 선택햇습니다 다시 입력해 주세요." << endl;
			system("pause");
		}
		else if (seat[r][c] != 0){
			cout << "이미 예약된 좌석입니다" << endl;
			system("pause");
		}
		else {

			int reserve_num = (r + 1) * 100 + (c + 1);
			seat[r][c] = reserve_num;
			reserved++;
			cout << reserve_num << "번호로 예약 완료" << endl;
			cin.ignore();
			return;
		}
	}
}

void save_seats(const string& filename, sharedDptr(&seat), const int row, const int col)
{
	ofstream  fout(filename);
	if (!fout.is_open()) {
		cout << "파일 출력 실패\n";
		return;
	}

	fout << row << " " << col << endl;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			fout << seat[i][j] << " ";
		}
		fout << endl;
	}

}


void print_menu(sharedDptr(&seat), const int row, const int col, int& reserved)
{
	int selected = 0;


	do {
		system("cls");
		cout << "202211364 정명훈\n";
		cout << "1) 좌석 현황" << '\t' << "2) 좌석 예약" << '\t' << "3) 좌석 취소" << '\t'  << "4) 종료" << endl;
		cout << "메뉴 선택: ";
		
		cin >> selected;
		
		switch (selected) 
		{
		
		case 1: Show_seat(seat, row, col); break;
		case 2:reserve_seat(seat, row, col, reserved); break;
		case 3:cancel_seat(seat, row, col, reserved);  break;
		case 4:break;
		default: {
			cout << "잘못된 값을 입력했습니다 다시 입력해주세요\n"; 
			break;
			
			}
		}
		system("pause");
	} while (selected != 4);

	
}

void Show_seat(sharedDptr(&seat), const int row, const int col)
{
	const char tab = '\t';
	for (int i = 0; i < col; i++) {
		cout << tab << i + 1;
	}

	cout << "\n";
	for (int i = 0; i < row; i++) {
		cout <<  static_cast<char>('A' + i) << tab;

		for (int j = 0; j < col; j++) {
			cout << (seat[i][j] != 0 ? "●" : "○") << tab;
		}

		cout << "\n";
	}

		
}
sharedDptr Load_seat(const string& filename, int& row, int& col, int& reserved)
{
	//객체 선언 입력을 받는 객체로 cin과 비슷하게 사용된다 유일한 차이는 파일로부터 입력을 받는다는 점이다
	ifstream fin(filename);
	if (!fin.is_open()) {
		cout << "파일 오픈 실패\n";
		return nullptr;
	}

	//입력
	fin >> row >> col;
	//입력 정보를 이용한 동적 메모리 할당과 좌석 정보 할당
	
	//new 이용한 동적할당
	//shared_ptr<shared_ptr<int[]>[]> seat(new shared_ptr<int[]>[row]); 이렇게 하지 않았어도 됬다 당시에는 내가 무지했다
	shared_ptr<shared_ptr<int[]>[]> seat = make_shared<shared_ptr<int[]>[]>(row);

	if (seat == nullptr) { return nullptr; }


	for (int i = 0; i < row; i++) {
		

		//하나 하나 다 메모리 동적 할당
		seat[i] = make_shared <int[]>(col);

		if (seat[i] == nullptr) { return nullptr; }

		for (int j = 0; j < col; j++) {
			fin >> seat[i][j];

			if (seat[i][j] != 0) reserved += 1;
		}
	}


	return seat;
}
//make_shared 컴파일러 버전 20