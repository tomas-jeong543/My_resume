#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* GetString(int len);
void ChangeWord(char *ap, char * bp, int len);
int main(void) {

	int len;
	char * str, * strcopy;

	printf("문자열의 길이 입력: ");
	scanf_s("%d", &len);

	str = GetString(len);
	strcopy = (char*)calloc(sizeof(char) , len);

	if (strcopy == NULL) {
		printf("오류 발생");
		return NULL;
	}

	ChangeWord( str, strcopy,  len);

	for (int i = 0; i < len; i++)
			printf("%c", strcopy[i]);

	//free(strcopy);
	//free(str);
	

	return -1;
}

char* GetString(int len) {

	char* str = (char*)calloc(sizeof(char) , len);
	
	if (str == NULL) {
		printf("오류 발생");
		return NULL;
	}

	while (getchar() != '\n');

	printf("문자열입력:");
	fgets(str, sizeof(str), stdin);
	
	return str;
}

void ChangeWord( char* ap, char* bp, int len) {

	int * spacepos = (char*)calloc(sizeof(int), len);
	int spaceidx = 0;
	int count = 0;
	for (int i = 0; i < len; i++) {

		if (ap[i] == 32) {
			spacepos[spaceidx++] = i;
			count++;
		}
	}


}


