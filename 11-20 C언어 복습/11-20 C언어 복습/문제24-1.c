#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

void RemoveLineBuffer(void) {
	while (getchar() != '\n');
}

void RemoveBsn(char str[]) {
	int len = strlen(str);
	str[len - 1] = 0;
}


typedef struct person {

	char name[20];
	char PersonId[20];
	char PhoneNum[20];
}Person;

int main(void) {

	Person me;

	fputs("이름 입력: ", stdout);
	fgets(me.name, sizeof(me.name), stdin);
	RemoveLineBuffer();
	//RemoveBsn(me.name);

	fputs("주민번호 입력: ", stdout);
	fgets(me.PersonId, sizeof(me.PersonId), stdin);
	RemoveLineBuffer();
	//RemoveBsn(me.PersonId);

	fputs("전화번호 입력: ", stdout);
	fgets(me.PhoneNum, sizeof(me.PhoneNum), stdin);
	RemoveLineBuffer();
	//RemoveBsn(me.PhoneNum);

	FILE* mystory = fopen("mystory.txt", "wt");
	
	if (mystory == NULL) {
		puts("파일 오픈 실패!");
		return -1;
	}

	printf("%s \n", me.name);


	fputs(me.name, mystory);
	fputs(me.PersonId, mystory);
	fputs(me.PhoneNum , mystory);

	fclose(mystory);

	printf("입력완료\n");
}