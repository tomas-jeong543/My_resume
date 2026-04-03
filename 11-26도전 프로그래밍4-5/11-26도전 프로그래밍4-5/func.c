#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 파일의 크기를 비교해 같으면 1 다르면 0을 반환하는 함수
int CompareFileLen(FILE * fp1, FILE *fp2) {

	// 파일의 위치를 가르키는 변수를 각자 파일의 끝으로 옮긴다
	fseek(fp1, -1, SEEK_END);
	fseek(fp2, -1, SEEK_END);

	// 만약 파일의 크기가 같다면 파일의 위치를 가르키는 변수를 다시 맨 앞으로 옮기고 1을 반환한다.
	if (ftell(fp1) == ftell(fp2)) {
	
		fseek(fp1, 0, SEEK_SET);
		fseek(fp2, 0, SEEK_SET);
		return 1;
	}
	else 
		return 0;
}

// 파일의 내용를 비교해 같으면 1 다르면 0을 반환하는 함수
int CompareFileInfo(FILE* fp1, FILE* fp2) {
	
	// 파일에서 문자를 입력받는 변수
	char ch1, ch2;
	//문자를 입력 받아 만약 다른 내용이 나오면 0을  파일의 내용이 완전히 같으면 1을 반환한다. 
	while (1) {
	
		ch1 = fgetc(fp1);
		ch2 = fgetc(fp2);

		if (ch1 != ch2) 
				return 0;

		if (ch1 == ch2 && ch1 == EOF && ch2 == EOF) 
							return 1;
		
	}

}