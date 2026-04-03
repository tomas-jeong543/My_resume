/*#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main(void) {

	char name[10];
	char sex;
	int age;

	FILE* fp = fopen("friend.txt", "wt");
	int i;

	for ( i = 0; i < 3; i++) {
		printf("이름 성별 나이 순 입력: ");
		
		if (scanf("%s %c %d", name, &sex, &age) == EOF || getchar() == NULL) {
			puts("비정상 종료\n");
			return -1;
		}

		fprintf(fp, "%s %c %d\n", name, sex, age);
	}

	fclose(fp);
	return 0;
}*/
