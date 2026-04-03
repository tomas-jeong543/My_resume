
#include <stdio.h>
#include <string.h>
int check(char s[], char a[], char ch);
int main(void) {
	char solution[100] = "meet at midnight";
	char answer[100] = "____ __ ________";  // 위의 솔루션과 길이가 일치
	char ch;
	while (1) {
		printf("문자열을 입력하시오: %s\n", answer);
		printf("글자를 추측하시오: ");
		ch = getchar();
		if (check(solution, answer, ch) == 1) {
			printf("성공 %s \n", answer);
				break;
		}
		while (ch = getchar() != '\n' && ch != EOF) {}; // 버퍼 제거
	}
	return 0;
}