/*#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// 입력 버퍼를 비우는 함수
void ClearLIneBuf() {
	while (getchar() != '\n');
}
// 문자열을 입력받는 함수
char* GetString(int len);

// 단어의 순서를 바꾸는 함수
char* ChangeWord(char* ap, char* bp, int len);

int main(void) {
	//문자열의 길이 정보, 문자열을 빙력 받을 배열과 단어 순서를 바꾸어 저장할 배열
	int len;
	char* str, * strcopy;
	
	printf("문자열의 길이 입력: ");
	scanf_s("%d", &len);
	
	ClearLIneBuf();
	// 문자열의 길이 만큼 문자열을 입력 받고 함수를 통해 문자열의 단어의 위치를 뒤집는다.
	str = GetString(len);
	strcopy = (char*)calloc(sizeof(char), len);

	if (strcopy == NULL) {
		printf("오류 발생");
		return -1;
	}

	strcopy = ChangeWord(str, strcopy, len);

	printf("함수 호출 완료\n");

	// 그 결과를 출력한다.
	for (int i = 0; i < len; i++)
		printf("%c", strcopy[i]);


	return 0;
	// 스택 메모리 반환
	free(strcopy);
	free(str);
}

char* GetString(int len) {

	char* str = (char*)calloc(sizeof(char) , len);

	if (str == NULL) {
		printf("오류 발생");
		return NULL;
	}

	printf("문자열입력:");
	fgets(str, sizeof(char) * len, stdin);
	return str;
	
}

char * ChangeWord(char* ap, char* bp, int len) {

	int* spacepos = (int*)calloc(sizeof(int), len);
	if (spacepos == NULL) {
		puts("오류발생");
		return -1;
	}
	// 문자의 개수, 스페이스바의 위치를 나타내는 배열 정보를 나타내는 변수, 임시 메모리 할당을 도와줄 변수
	//선언 
	int count = 0;
	int spaceidxnum = 0;
	int spaceidx = 0;
	int spacenum = 0;
	int insidx = 0;
	int copystrtpoinit;
	
	for (int i = 0; i < len; i++) {
		if (ap[i] == 32 || ap[i] == NULL) {
			spacepos[spaceidx++] = i;
			count++;
		}
	}

	for (int i = 0; i < count; i++) {
		
		insidx = 0;
		copystrtpoinit = len - spacepos[i] ;

		for (int j = spacenum; j < spacepos[i] + 1; j++) {
			
			char* ins = (char*)malloc(sizeof(char) * spacepos[i]);
			if (ins == NULL) {
				return NULL;
			}

			ins[insidx] = ap[j];
			bp[copystrtpoinit++] = ins[insidx];
			insidx += 1;

		}
		spacenum = spacepos[i] + 1;
	}

	
	return bp;

}*/


