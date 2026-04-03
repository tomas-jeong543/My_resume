/*#include<stdio.h>
#include<string.h>
// 입력 버퍼를 비우는 함수
void RemoveLineBuffer(void){
	while (getchar() != '\n');
}
// 개행을 삭제하는 함수
void RemoveBsn(char str[]) {
	
	int len = strlen(str) + 1;
	str[len - 1] = 0;

}
// 직원의 구조체의 정의
struct employee {

	char name[20];
	char phonenum[20];
	int age;
} a;

// 직원의 정보를 입력받는 함수
void GetImformation( struct  employee a[3], int i) {

	printf("직원 %d의 이름을 입력하시오:", i + 1);
	fgets(a[i].name, sizeof(a[i].name), stdin);
	RemoveBsn(a[i].name);
	RemoveLineBuffer();
	

	puts(a[i].name);

	printf("직원 %d의 전화번호를 입력하시오:", i + 1);
	fgets(a[i].phonenum, sizeof(a[i].phonenum), stdin);
	RemoveBsn(a[i].name);
	RemoveLineBuffer();
	

	printf("직원 %d의 나이를 입력하시오:", i + 1);
	scanf_s("%d", &a[i].age);
	printf("\n");
	RemoveLineBuffer();

}
// 직원의 정보를 출력하는 함수
void PrintEMployeeImfo(struct employee person[3], int i) {

	printf("직원 %d의 이름:  %s\n", i + 1, person[i].name);
	printf("직원 %d의 전화번호:  %s\n", i + 1, person[i].phonenum);
	printf("직원 %d의 나이:  %d\n\n", i + 1, person[i].age);

}


int main(void) {
	
	struct  employee str[3];

	puts("직원들의 정보 입력");

	for (int i = 0; i < 3; i++)
		GetImformation(str, i);

	puts("직원들의 정보 출력 \n\n");

	for (int i = 0; i < 3; i++)
		PrintEMployeeImfo(str, i);

}*/