/*#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

void RemoveBsn(char *str) {
	int len = strlen(str);
	str[len - 1] = NULL;
}

int main(void) {

	FILE * src = fopen("src.txt", "rt");
	FILE * des = fopen("des.txt", "wt");
	char str[20];

	if (src == NULL || des == NULL) {
		puts("파일 오픈 실패");
		return -1;
	}

	while (fgets(str, sizeof(str), src) != NULL) {
		fputs(str, des);
	}

	if (feof(src) != 0)
		puts("파일 복사 완료!");
	else
		puts("파일 복사 실패");
	
	fclose(src);
	fclose(des);

	return 0;
}*/