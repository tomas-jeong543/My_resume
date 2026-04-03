#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void RemoveLineBuffer(void) {
	while (getchar() != '\n');
}

void RemoveBsn(char str[]) {

	int len = strlen(str);
	str[len - 1] = 0;
}


struct employee
{
	char name[20];
	char PerId[17];
	int slaryinfo;

} employe1;

int main(void) {

	fputs("종업원의 이름 입력:", stdout);
	fgets(employe1.name, sizeof(employe1.name) - 1, stdin);
	RemoveBsn(employe1.name);
	RemoveLineBuffer();

	fputs("종업원의 주민번호 입력:", stdout);
	fgets(employe1.PerId, sizeof(employe1.PerId) - 1, stdin);
	RemoveBsn(employe1.PerId);
	RemoveLineBuffer();

	fputs("종업원의 연봉정보 입력:", stdout);
	scanf_s("%d", &employe1.slaryinfo);

	printf("직원의 이름 %s \n직원의 주민번호 %s \n직원의 연봉정보: %d \n", employe1.name, employe1.PerId, employe1.
		slaryinfo);

}