#include<stdio.h>
#include<string.h>

int main(void)
{
	enum days { SUN,MON,TUE,WEN,THU,FRI,SAT };
	char days_number[7][10] = {
		"sunday","monday", "tuseday", "wensday", "thursday", "friday","saturday"
	};
	enum days today = THU;
	printf("%d번째 요일은 %s입니다.", today, days_number[today]);
	return 0;
}