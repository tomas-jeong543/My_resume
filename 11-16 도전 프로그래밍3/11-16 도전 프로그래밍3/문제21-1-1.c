/*#include<stdio.h>

int main(void) {
	// 입출력 할 값 저장 변수 선언
	int ch;

	// 입력 값 받음
	ch = getchar();

	// 입력 값이 알파벳이 아니면 오류문자 출력 
	if (ch < 65 || (ch > 90 && ch < 97) || ch > 122)
		printf("오류가 발생했슴니다.");
	else {
		
		//알파벳이면 대문자를 소문자로 소문자를 대문자로 바꾼다.
		if (ch <= 90) {
			ch += 32;
			putchar(ch);
		}
		else {
			ch -= 32;
			putchar(ch);
		}

	}

	return 0;
}*/