#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<String.h>


// 1 ~ 3 사이의 난수를 만드는 함수
int MakeRandomNum();
// 숫자에 따라 가위 바위를 반환하는 함수
char* SwitchNumtoChar(int num);
// 가위바위보 결과를 출력하고 게임의 기록을 갱신하는 함수
void ShowResult(int comnum, int mynum, char ** comchar, char ** mychar, int det[3][3], int * win, int * draw);
//내가 낼 가위 바위 보를 입력받는 함수
int GetMynum();

int main(void) {
	/* 이긴 횟수 진 횟수 변수 선언 및 초기화, 그것을 가르키는 포인터 선언, 내가 입력한 숫자, 컴퓨터가 입력할 숫자
	* 선언, 가위바위보를 가르킬 문자형 포인터 및  그 포인터를 가르키는 이중포인터 선언 및 초기화
	*/
	int  wintime = 0, drawtime = 0;
	int* wint = &wintime, * drawt = &drawtime;
	int mynum, comnum;
	char* comnumchar = "hello";
	char* mynumchar = "hi";
	
	char** comnumcha = &comnumchar;
	char** mynumcha = &mynumchar;
	
	// 결과를 알려주는 배열 선언
	int Det[3][3] = {
		{ 0, 1, -1},
		{ -1, 0, 1},
		{ 1, -1, 0}
	};
	
	// 지기 전까지 승부를 펼치고 승리와 무승부 기록 저장 및 결과를 출력한다.
	do  {
		// 컴퓨터 난수 불러오고 가위 바위 보 중 고른 것을 문자열에 저장
		comnum = MakeRandomNum();
		comnumchar = SwitchNumtoChar(comnum);
		
		// 사람의 숫자 입력하고 가위 바위 보 중 고른 것을 문자열에 저장
		mynum = GetMynum();
		*mynumcha = SwitchNumtoChar(mynum);

		//결과를 보여주는 함수 호출
		ShowResult(comnum, mynum, comnumcha, mynumcha, Det, wint, drawt);


	} while (Det[mynum - 1][comnum - 1] != -1);

	printf("게임의 결과: %d 승 %d무\n", wintime, drawtime);

	return 0;
}

int MakeRandomNum() {
	
	//1-3사이 난수 저장할 변수 선언 및 초기화
	int randomnum = 0;
	// 시간을 이용해 시드값을 랜덤하게 설정
	srand(time(NULL));
	
	//난수 값이 0이 아닌 값이 되기 하기 위한 제어문
	while (randomnum == 0) {
		//0~3 사이의  난수 생성
		randomnum = rand() % 4;
	}

	// 난수 반환
	return randomnum;

}

char* SwitchNumtoChar(int num) {
	char * str = "가위";
	
		//숫자에 따 가위,바위,보 중 하나를 Str에 담아 반환한다.
		switch (num) {
			case(1): {
				str = "바위";
				break;
			}
			case(2): {
				str = "가위";
				break;
			}
			case(3): {
				str = "보";
				break;
			}
		}

		return str;
}

void ShowResult(int comnum, int mynum, char ** comchar, char **mychar, int det[3][3], int * win, int * draw) {
	
	

	// det 값에 따라 승패무 유무를 나타내는 문자열을 result에 저장하고 이기거나 비긴 경우 그 기록을 갱신한다. 
	if (det[mynum -1][comnum-1] == -1) {
			
		printf("당신은 %s 선택, 컴퓨터는 %s 선택, 당신이 졌습니다.\n", *mychar, *comchar);
		
	}
	else if (det[mynum - 1][comnum - 1] == 0) {
		printf("당신은 %s 선택, 컴퓨터는 %s 선택, 비겼습니다.\n", *mychar, *comchar);
		*draw += 1;
	}
	else if (det[mynum - 1][comnum - 1] == 1) {
		printf("당신은 %s 선택, 컴퓨터는 %s 선택, 당신이 이겼습니다.\n", *mychar, *comchar);
		*win += 1;
	}
	
	
}
// 내가 입력할 숫자를 입력받는 함수
int GetMynum() {
	int num;
	printf("바위는 1, 가위는2, 보는 3: ");
	scanf_s("%d", &num);
	return num;
}