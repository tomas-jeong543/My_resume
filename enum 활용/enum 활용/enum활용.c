#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
enum tvtype{LCD, OLED};
enum tvtype code;
int main(void)
{
	
	
	printf("원하는 tv타입을 구하시오?(1:LCD,2:OLED) ");
	scanf("%d", &code);
	switch (code) {
		case (LCD+1):
			printf("LCD tv on");
			break;
		case (OLED+1):
			printf("OLED tv on");
			break;

	}
	return 0;
}