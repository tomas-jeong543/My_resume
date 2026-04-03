/*#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//입력 버퍼를 제거하는 함수
void RemoveBSN(void) {
	while (getchar() != '\n');
}

int main(void) {
	
	// 만약 배열의 있는 문자를 저장할 배열과 총합을 나타내는 변수 그리고 입력받을 문자열을 저장할 배열 선언
	char instant[2];
	int sum = 0;
	char String[20];

	//문자열을 입력받고 입력 버퍼를 비움
	fgets(String, sizeof(String), stdin);
	RemoveBSN();

	// 입력받은 길이 만큼 만약 문자열의 문자가 숫자로 변환될 수 있으면 그것을 다른 배열에 저장하고 아니면 0을 저장
	for (int i = 0; i < strlen(String) - 1; i++) {
		if (String[i] >= 48 && String[i] <= 57) {
			instant[0] = String[i];
		}
		else
			instant[0] = 0;

		instant[1] = 0;
		// 저장된 값을 int형 변수로 바꾸어 총합에 더해준다.
		sum += atoi(instant);
	}
	
	printf("sum: %d\n", sum);

	return 0;
}*/