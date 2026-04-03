/*#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {


	FILE* src = fopen("data.txt", "rt"); // 읽기모드
	FILE* des = fopen("des.txt", "wt"); //쓰기모드
	char str[20];

	// 둘 중 하나라도 존재하지 않으면 오픈 실패
	if (src == NULL || des == NULL) {
		puts("파일오픈 실패!");
		return -1;
	}

	// 파일 끝까지 복서
	while (fgets(str, sizeof(str), src) != NULL)
		fputs(str, des);
	// 성공 확인 여부 알려줌
	if (feof(src) != 0)
		puts("파일 복사 완료!");
	else
		puts("파일 복사 실패!");
	// 파일 닫음
	fclose(src);
	fclose(des);


	return 0;
}*/