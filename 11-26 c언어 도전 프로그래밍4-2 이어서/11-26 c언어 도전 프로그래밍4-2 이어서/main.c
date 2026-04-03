#include<stdlib.h>
#include<stdio.h>
#include "bookinfo.h"
#include "streamfunc.h"

int main(void) {

	int booknum;
	// 입력할 책의 권수 입력
	fputs("입력할 책의 개수를 입력하시오:", stdout);
	scanf_s("%d", &booknum);
	RemoveLineBuf();
	// 이중 포인터를 통한 포인터 배열 선언
	Book** books = (Book*)malloc(sizeof(Book) * booknum);

	if (books == NULL) {
		puts("오류 발생");
		return -1;
	}
	// 입력
	for (int i = 0; i < booknum; i++) {
		GetBookinfo(&books[i]);
	}


	// 출력
	for (int i = 0; i < booknum; i++)
			PrintBookinfo(&books[i]);

	
	
	return 0;
	free(books);
}