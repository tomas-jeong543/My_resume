
// Book 구조체가 정의되지 않았다면 정의한다
#ifndef __BOOKINFO__
#define __BOOKINFO__

typedef struct BookInfo
{
	char writername[20];
	char bookname[20];
	int page;
}Book;
#endif 
