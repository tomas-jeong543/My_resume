#include<string.h>
#include<stdio.h>

int main(void)
{
	char s1[80];
	char s2[80];
	int result;

	printf("첫 번째 단어를 입력하시오:");
	scnaf("%s", &s1);
	printf("두 번째 단어를 입력하시오:");
	scnaf("%s", &s2);

	result = strcmp(s1, s2);
	if (result == 0)
		printf("두 문자열은 같습니다.");
	else if (result > 0)
		printf("첫 번째 단어가 앞에 있습니다.");
	else
		printf("두 번째 단어가 앞에 있습니다.");
	return 0;
}