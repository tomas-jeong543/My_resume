/*#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {

	FILE* fp = fopen("simple.txt", "wt"); // 쓰기 모드 스트림 생성
	if (fp == NULL) {
		puts("파일오픈 실패!");
		return -1;
	}
	// 파일에 문자 2개와 분자열 2개를 이력했음으로 이 파일을 열 때에는 택스트모드로 열어야 한다.
	fputc('A', fp);
	fputc('B', fp);
	fputs("My name is Hong \n", fp);
	fputs("Your name is Yoon \n", fp);
	fclose(fp);
	
	return 0;
}*/