#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include "bookinfo.h"


void RemoveLineBuf(void) {
	while (getchar() != '\n');
}

void RemoveBsn(char * str) {
	
	int len = strlen(str);
	str[len - 1] = 0;
}

void GetBookinfo(Book * book) {
	int pagenum;
	
	puts("도서 정보 입력 ");

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

void PrintBookinfo(Book book)
{
	puts("도서 정보 출력 ");

	fputs("책 저자: ", stdout);
	puts(book.writername);
	fputs("책 제목: ", stdout);
	puts(book.bookname);
	fputs("페이지 수: ", stdout);
	printf("%d\n", book.page);
}
