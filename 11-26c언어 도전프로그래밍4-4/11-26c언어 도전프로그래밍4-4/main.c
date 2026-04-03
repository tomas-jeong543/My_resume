#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {
	// A와 D로 시작하는 단어 저장하는 변수선언 및 초기화 파일에서 입력받는 문자 저장하는 변수 1개 선언
	// A,와 P가 단어의 시작인지 알려주는 det변수 선언
	int Acount = 0, Pcount = 0, det = 1;
	char ch;
	// 리소스 파일에 생성된 파일을 읽기 모드로 연다.
	FILE* fp = fopen("wordcnt.txt", "rt");
	// 파일이 열리지 않는 경우에 대해 오류 처리
	if (fp == NULL) {
		puts("오류 발생");
		return -1;
	}
	else {
		puts("파일 오픈 성공");
	}
	// 파일 내의 문자를 파일의 끝까지 도달할 때까지 읽으라는 걸 break로 구현
	while (1) {

		// 문자를 문자형 변수에 저장
		ch = fgetc(fp);
		
		//문자가 A,P 이고 단어의 시작이면  A와 D로 시작하는 단어 저장하는 변수의 값을 증가시킨다.
		if (ch == 65 && det == 1) {
			Acount += 1;
		}
		else if (ch == 80 && det == 1) {
			Pcount += 1;
		}
		// 파일 끝 도달시 탈출	
		if (ch == EOF) 
					break;
		
		// 문자열을 공백문자로 구분함으로 공백문자가 입력되면 다음 문자는
		//단어의 시작임으로 det값을 1로 바꾼다
		if (ch == 9 || ch == 10 || ch == 32)
			det = 1;
		else
			det = 0;
	}

	// 각 단어의 개수를 출력한다.
	printf("A로 시작하는 단어의 수: %d\n", Acount);
	printf("P로 시작하는 단어의 수: %d\n", Pcount);
	//파일을 닫는다.
	fclose(fp);
	return 0;
}