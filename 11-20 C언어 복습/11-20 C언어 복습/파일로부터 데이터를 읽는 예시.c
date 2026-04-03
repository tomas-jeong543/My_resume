/*/#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {

	int ch  ,i;
	FILE* fp = fopen("data.txt", "rt"); // 두 번째 인자로 rt를 전달 해 읽기 위한 스트림 생성 
	if (fp == NULL) {
		puts("파일오픈 실패!");
		return -1;
	}

	for (i = 0; i < 3; i++) //3회 동안 파일의 글자를 하나식 입력한다.
	{
		ch = fgetc(fp);
		printf("%c \n", ch);
	}

	fclose(fp);
	return 0;
}*/