/*#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>


int Findlength(char arr[]);
void CheckPalinDrome(char arr[], int len);

int main(void) {

	char str[100];
	int len;
	printf("문자열 입력:");
	scanf("%s",str);

	len = Findlength(str);
	CheckPalinDrome(str, len);

	return 0;
}

int Findlength(char arr[]) {
	int len = 0;
	while (arr[len] != '\0') {
		len += 1;
	}
	return len;
}
void CheckPalinDrome(char arr[], int len) {

	int len2 = len;
	int count = len / 2;
	int det = 0;
	
	for (int i = 0; i < count; i++) {
		if (arr[i] != arr[--len2])
			break;
		
		if (i == count - 1)
			det = 1;
	}

	if (det == 0)
		printf("화문이 아닙니다.");
	else
		printf("화문입니다.");
}*/