/*/#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

typedef struct fren
{
	char name[10];
	char sex;
	int age;
}Friend;

int main(void) {

	FILE* fp;
	Friend myfren1, myfren2;

	// 파일 쓰기
	fp = fopen("friend.bin", "wb");
	printf("이름, 성별, 나이 순 입력: ");
	if (scanf("%s %c %d", myfren1.name, &(myfren1.sex), &(myfren1.age)) == EOF) {
		puts("scanf 함수 진행중 오류 발생");
		return -1;
	}
	fwrite( (void*)&myfren1, sizeof(myfren1), 1, fp);
	fclose(fp);

	//파일 출력
	fp = fopen("friend.bin", "rb");
	fread( (void*)&myfren2, sizeof(myfren2), 1, fp);
	printf("%s %c %d \n", myfren2.name, myfren2.sex, myfren2.age);
	fclose(fp);
	return 0;
}*/