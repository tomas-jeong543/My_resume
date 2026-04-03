/*#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>


int FindFileSize(FILE* fp) {
	char str[5] = { 50,51,52,53 , NULL };
	int Fsize = 0;
	int i = 0;
	long curlocation;
	long des;

	 fp = fopen("24-2.txt", "wt");

	fputs(str, fp);
	curlocation = ftell(fp);
	fseek(fp, 0, SEEK_END);
	des = ftell(fp);

	fclose(fp);

	fp = fopen("24-2.txt", "rt");
	fseek(fp, 0, SEEK_SET);

	while (ftell(fp) != des) {
		fseek(fp, i, SEEK_SET);
		Fsize += 1;
		i += 1;
	}

	Fsize = ftell(fp);

	fseek(fp, curlocation, SEEK_SET);
	return Fsize;
}

int main(void) {
	int size;

	FILE* fp = fopen("24-2.txt", "wt");


	size = FindFileSize(fp);

	printf("24-2.txt 파일의 크기는 %d바이트 이다.\n", size);


	fclose(fp);
	return 0;
}*/