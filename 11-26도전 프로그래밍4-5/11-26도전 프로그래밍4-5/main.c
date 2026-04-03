#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"func.h"

int main(void) {

	// 비교할 2개의 파일을 읽기 모드로 불러온다.
	FILE* fp1 = fopen("d1.txt", "rt");
	FILE* fp2 = fopen("d2.txt", "rt");
	// 파일 오픈 실패 관련 예외처리
	if (fp1 == NULL || fp2 == NULL) {
		puts("파일 오픈 실패");
		return -1;
	}
	else
		puts("파일 오픈 성공");

	// 만약 파일의 크기와 파일의 정보가 완정히 일치하면 일치한다고 알려주고 아니면 아니라고 알려준다.
	if (CompareFileLen(fp1, fp2)  == 1&& CompareFileInfo(fp1, fp2) == 1) {
			puts("두 파일은 완전히 일치합니다.");
	}
	else
		puts("두 파일은  일치하지 않습니다.");

	//파일을 닫는다.
	fclose(fp1);
	fclose(fp2);
	return 0;
}
