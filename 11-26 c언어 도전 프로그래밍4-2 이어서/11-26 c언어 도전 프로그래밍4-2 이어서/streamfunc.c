#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include "bookinfo.h"

// 입력 버퍼를 지우는 함수
void RemoveLineBuf(void) {
	while (getchar() != '\n');
}

//fgets 사용시 문자열의 끝 지정하는 함수
void RemoveBsn(char* str) {

	int len = strlen(str);
	str[len - 1] = 0;
}

// 책의 정보를 입력받는 함수
void GetBookinfo(Book* book) {
	int pagenum;

	puts("도서 정보 입력 ");
	printf("\n");
	// fgets함수를 이용해 책의 이름을 키보드로 입력받고 문자열의 끝을 null로 지정한다.
	fputs("책 저자 입력: ", stdout);
	fgets(book->writername, sizeof(book->writername), stdin);
	RemoveLineBuf();
	RemoveBsn(book->writername);

	fputs("책 제목 입력: ", stdout);
	fgets(book->bookname, sizeof(book->bookname), stdin);
	RemoveLineBuf();
	RemoveBsn(book->bookname);

	fputs("책 페이지 수 입력: ", stdout);
	scanf_s("%d", &pagenum);
	book->page = pagenum;
	RemoveLineBuf();

}
// 책의 정보를 출력하는 함수
void PrintBookinfo(Book * book )
{
	puts("도서 정보 출력 ");
	printf("\n");
	
	fputs("책 저자: ", stdout);
	puts(book->writername);
	fputs("책 제목: ", stdout);
	puts(book->bookname);
	fputs("페이지 수: ", stdout);
	printf("%d\n", book->page);
}