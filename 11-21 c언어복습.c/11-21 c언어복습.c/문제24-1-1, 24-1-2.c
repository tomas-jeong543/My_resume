/*#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>


// 키보드를 통한 입력버퍼를 비워주는 함수
void RemoveLineBuffer(void) {
	while (getchar() != '\n');
}

// 사람의 정보를 저장하는 구조체 변수
typedef struct person {

	char name[20];
	char PersonId[30];
	char PhoneNum[30];
	char LikeFoods[30];
	char Hobby[30];
}Person;

int main(void) {

	// 나의 정보를 입력받을 구조체 변수 1개와 파일에 저장할 양식을 입력한 구조체 변수 선언 및 초기화
	Person me;

	Person Formfile = {
		{"#이름: "},
		{"#주민번호: "},
		{"#전화번호: "},
		{"#즐겨먹는 음식: "},
		{"#취미: "},
	};

	// 필요한 정보들 입력
	fputs("이름 입력: ", stdout);
	fgets(me.name, sizeof(me.name), stdin);
	RemoveLineBuffer();

	fputs("주민번호 입력: ", stdout);
	fgets(me.PersonId, sizeof(me.PersonId), stdin);
	RemoveLineBuffer();

	fputs("전화번호 입력: ", stdout);
	fgets(me.PhoneNum, sizeof(me.PhoneNum), stdin);
	RemoveLineBuffer();

	fputs("즐겨먹는 음식 입력: ", stdout);
	fgets(me.LikeFoods, sizeof(me.LikeFoods), stdin);
	RemoveLineBuffer();

	fputs("취미 입력: ", stdout);
	fgets(me.Hobby, sizeof(me.Hobby), stdin);
	RemoveLineBuffer();

	// 내 정보를 저장할 파일 선언
	FILE* mystory = fopen("mystory.txt", "wt");

	if (mystory == NULL) {
		puts("파일 오픈 실패!");
		return -1;
	}
	
	// 양식에 다가 내 정보를 덧붙여 양식 구조체 변수에 저장
	strncat(Formfile.name, me.name, strlen(me.name));
	strncat(Formfile.PersonId, me.PersonId, strlen(me.PersonId));
	strncat(Formfile.PhoneNum, me.PhoneNum, strlen(me.PhoneNum));
	strncat(Formfile.LikeFoods, me.LikeFoods, strlen(me.LikeFoods));
	strncat(Formfile.Hobby, me.Hobby, strlen(me.Hobby));

	// 양식 구조체 내용을 파일에 출력
	fputs(Formfile.name, mystory);
	fputs(Formfile.PersonId, mystory);
	fputs(Formfile.PhoneNum, mystory);
	fputs(Formfile.LikeFoods, mystory);
	fputs(Formfile.Hobby, mystory);
	
	// 파일 닫기
	fclose(mystory);

	printf("입력완료\n");
	return 0;
}*/