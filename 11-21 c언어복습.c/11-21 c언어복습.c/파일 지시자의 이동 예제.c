/*#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main(void) {
	
	// 颇老 积己
	FILE* fp = fopen("text.txt", "wt");
	fputs("123456789", fp);
	fclose(fp);

	// 颇老 俺规
	fp = fopen("text.txt", "rt");
	
	//seek end test
	fseek(fp, -2, SEEK_END);
	putchar(fgetc(fp));

	//seek set test
	fseek(fp, 2, SEEK_SET);
	putchar(fgetc(fp));
	
	//seek cur test
	fseek(fp, 2, SEEK_CUR);
	putchar(fgetc(fp));


	fclose(fp);
	return 0;
}*/