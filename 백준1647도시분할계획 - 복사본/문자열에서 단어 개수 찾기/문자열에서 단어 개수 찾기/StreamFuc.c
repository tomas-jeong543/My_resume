#include<stdio.h>
//입력 버퍼를 비우는 함수 
void RemoveLineBuf() 
{
	while (getchar() != '\n');
}