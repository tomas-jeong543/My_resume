#include<stdio.h>

enum days { SUN,MON,TUE,WEN,THU,FRI,SAT };
char days_name[7][10] = {
	"sunday","monday","tuseday","wensday","thursday","friday","saturday"
};

int main(void)
{
	enum days d;
	d = WEN;
	printf("%d번째 요일은 %s 입니다.", d, days_name[d]);
	return 0;
}