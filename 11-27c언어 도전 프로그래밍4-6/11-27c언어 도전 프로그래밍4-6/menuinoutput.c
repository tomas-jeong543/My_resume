
#ifndef __LIBRARY2__
#define __LIBRARY2__
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#endif 
//입력 버퍼를 지우는 함수
void RemoveLineBuf(void) 
{
	while (getchar() != '\n');
}
// fgets를 사용시 개행 문자를 삭제시키는 함수
void RemoveBsn(char *str) 
{
	int len = strlen(str);
	str[len - 1] = 0;
}

// 메뉴 정보를 출력해주는 함수
void ShowMenu(void)
{
	puts("*****MENU*****");
	puts("1. Insert");
	puts("2. Delete");
	puts("3. Search");
	puts("4. Print All");
	puts("5. Exit");
}

// 선캑할 메뉴의 숫자를 입력받아 반환하는 함수
int GetMenuOption(void)
{
	int num;

	fputs("Choose the Item: ", stdout);
	scanf_s("%d", &num);
	//입력버퍼 비움
	RemoveLineBuf();
	return num;
}