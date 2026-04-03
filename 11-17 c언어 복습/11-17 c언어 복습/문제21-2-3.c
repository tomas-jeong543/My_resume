/*#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// 나이를 구해서 반환하는 함수
int GetMyAge(char *imfo, int fulllen, int namelen) {
	// 시작지점 선언 및 초기화, 나이 저장 변수 선언, 나이를 저장할 문자배열 선언, 배열의 마지막 요소는
	//null로 초기화
	int start = 0;
	int age;
	char c[4];
	c[3] = 0;

	// 나이의 길이를 전체 길이에서 이름의 길이를 빼서 구한 후에 이에 따라 시작지점을 정한다.
	// 시작지점의 앞 칸에는 숫자 0의 아스키 코드 48을 집어 넣늗다.
	if (fulllen - namelen == 2) {
		c[0] = 48;
		start = 1;
	}
	else if(fulllen - namelen == 1) {
		c[0] = 48, c[1] = 48;
		start = 2;
	}

	// 시작 지점부터 숫자 부분의 끝가지 숫자를 배열에 복사한다.
	for (int i = namelen + 1; i < fulllen + 1; i++) {
		c[start++] = imfo[i];
	}
	//복사된 배열을 문자열을 숫자로 만드는 함수를 이용해 변환해 나이 변수에 저장한다..
	age = atoi(c);

	return age;
}


// 이름의 길이를 스페이스바의 아스키 코드를 이용해 구하는 함수
int GetNameLen(char imfo[]) {
	// 시작지점을 가르키는 변수와 이름의 길이를 나타내는 변수를 초기화한다.
	int i = 0;
	int len = 0;
	// 만약 문자열의 문자가 이름과 나이를 구분하는 스페이스바의 아스키 코드에 도달할 때까지 길이를 증가시킨다.
	while (imfo[i++] != 32) {
		len += 1;
	}

	return len;

}

// 입력 버퍼를 비우는 함수
void RemoveLinrBuffer(void) {

	while (getchar() != '\n');
}

int main(void) {

	//이름의 길이, 문자열의 총 길이 그리고 나이를 저장할 정수형 변수  2개씩 선언, 
	int namelen1, namelen2;
	int fulllen1, fulllen2;
	int age11, age22;
	// 이름을 문자열로 저장하는 배열 2개 선언
	char name1[20];
	char name2[20];

	// 이름을 입력받고 입력버퍼를 비워 오류를 방지한다.
	fputs("이름 입력1:", stdout);
	fgets(name1, sizeof(name1) - 1, stdin);
	RemoveLinrBuffer();
	// 총 길이는 strlen함수로 이름의 길이와 나이도 각각 구하는 함수를 이용해 구한다.
	fulllen1 = strlen(name1);
	namelen1 = GetNameLen(name1);
	age11 = GetMyAge(name1,fulllen1, namelen1);
	
	//위의 과정 반복
	fputs("이름 입력2:", stdout);
	fgets(name2, sizeof(name1) - 1, stdin);
	RemoveLinrBuffer();
	
	namelen2 = GetNameLen(name2);
	fulllen2 = strlen(name2);
	age22 = GetMyAge(name2, fulllen2, namelen2);

	// 이름의 길이가 같지 않는 경우와 같은 경우 분류
	if (namelen1 != namelen2) {
		//나이가 같은지에 따른 분류
		if (age11 == age22) {
			puts("이름은 다르지만 나이는 같다.");
		}
		else {
			puts("이름과 나이가 다르다.");
		}

	}// 이름의 길이가 같은 경우 문자열의 내용이 같은지를 비교해 분류
	else if (!strncmp(name1, name2, namelen1)) {
		if (age11 == age22) {
			puts("이름과 나이가 같다.");
		}
		else {
			puts("이름은 같지만 나이가 다르다.");
		}
	}
	else {
		if (age11 == age22) {
			puts("이름은 다르지만 나이는 같다.");
		}
		else {
			puts("이름과 나이가 다르다.");
		}

	}

	return 0;
}*/