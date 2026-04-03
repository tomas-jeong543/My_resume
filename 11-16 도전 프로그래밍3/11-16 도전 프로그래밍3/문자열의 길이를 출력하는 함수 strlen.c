#include<stdio.h>
#include<string.h>


void RemoveBSN(char str[])
{	
	// 길이를 제서는 int 형 변수에 저장한다.
	unsigned int len = strlen(str);
	// 함수의 배열에 널 값의 아스키 코드 값을 넣는다.
	str[len - 1] = 0;
}


int main(void) {

	char str[100];
	printf("문자열 입력: ");
	fgets(str, sizeof(str), stdin);
	printf("길이: %u 내용: %s \n", strlen(str), str);
	
	//printf("1\n");

	RemoveBSN(str);                                                            
	printf("길이: %u 내용: %s \n", strlen(str), str);
	printf("%d", str[strlen(str) - 1]);
	return 0;
}