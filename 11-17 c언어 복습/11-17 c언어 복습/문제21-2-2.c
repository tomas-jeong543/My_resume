/*/#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void RemoveInputBuffer(void) {
	while (getchar() != '\n');
}

void RemoveBsn(char str[]) {

	int len = strlen(str);
	str[len - 1] = 0;
}

int main(void) {

	// 배열 3개 선언 및 덫붙이는 시작점인 str[3] 을 0 으로 초기화
	char str1[20];
	char str2[20];
	char str3[40];
	str3[0] = 0;

	//문자열을 하나 입력받고 \n문자를 삭제하고 입력버퍼를 비운 후 str3에 복사한다.
	fputs("문자열1 입력: ", stdout);
	fgets(str1, sizeof(str1) -1, stdin);
	RemoveBsn(str1);
	RemoveInputBuffer();
	strcat(str3, str1);
	//문자열을 하나 입력받고 \n문자를 삭제하고 str3에 복사한다.
	fputs("문자열2 입력: ", stdout);
	fgets(str2, sizeof(str2) - 1, stdin);
	RemoveBsn(str1);

	strcat(str3, str2);

	puts(str3);

	return 0;
}*/