/*/#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {

	char str[30];
	int ch;
	FILE* fp = fopen("simple.txt", "rt"); // 텍스트 읽기 모드
	if (fp == NULL) {// 파일 열기 실패 후 비정상 종료
		puts("파일오픈 실패!"); 
		return - 1;
	}
	// 문자 2개 읽고 출력
	ch = fgetc(fp);
	printf("%c \n", ch);
	ch = fgetc(fp);
	printf("%c \n", ch);
	//문자열 2개 읽어내 저장 후 출력
	fgets(str, sizeof(str), fp);
	printf("%s", str);
	fgets(str, sizeof(str), fp);
	printf("%s", str);
	// 파일 닫기 후 정상 종료
	fclose(fp);
	return 0;
	}
*/