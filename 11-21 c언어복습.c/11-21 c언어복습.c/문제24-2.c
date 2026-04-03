#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>


int FindFileSize(FILE * fp) {
	
	int Fsize = 0;
	int i = 0;
	long curlocation = ftell(fp);
	long des = fseek(fp, -1, SEEK_END);
	fp = fopen("24-2.txt", "rt");

	printf("%d %d %d", seek(fp, -1, SEEK_END), seek(fp, -1, SEEK_END) ,seek(fp, 0, SEEK_END));


	 fseek(fp, 0, SEEK_SET);

	while (ftell(fp) != EOF) {
		fseek(fp, i, SEEK_CUR);
		putchar(fgetc(fp));
		Fsize += 1;
		i += 1;
	}

	
	fseek(fp, curlocation, SEEK_SET);
	return Fsize;
}

int main(void) {
	
	int size;
	FILE* fp = fopen("24-2.txt", "wt");
	if (fp == NULL) {
		puts("파일 오픈 실패");
		return -1;
	}

	fputs("123", fp);
	fclose(fp);



	size = FindFileSize(fp);

	printf("24-2.txt 파일의 크기는 %d바이트 이다.\n", size);


	fclose(fp);
	return 0;
}