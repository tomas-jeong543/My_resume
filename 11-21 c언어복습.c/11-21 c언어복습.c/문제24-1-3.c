/*#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main(void) {
	
	//출력할 파일을 가르키는 구조체 및 파일의 문자열을 복사할 배열 선언
	FILE* mystory = fopen("mystory.txt", "rt");
	char str[30];
	
	//파일 열기 실패시 알려주고 비전상종료
	if (mystory == NULL) {
		puts("파일 오픈 실패");
		return -1;
	}

	// 파일의 끝까지 도달할 때까지 계속 문자열을 읽고 콘솔로 출력한다.
	while (fgets(str, sizeof(str), mystory) != NULL) {
		printf("%s", str);
	}
	
	// 파일의 끝까지 읽었는지 여부를 알려주는 함수
	if (feof(mystory) != 0) {
	
		puts("파일 출력 성공");
	}
	else {
		puts("파일 출력 실패");
	}
	// 파일 닫기
	fclose(mystory);
	return 0;
}*/