#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<math.h>

struct point {
	int x;
	int y;
};
struct rectangle
{
	struct point leftlow;
	struct point righthigh;
}; 


int main(void)
{
	struct rectangle s;
	double xdiff, ydiff;
	double circumfe, width;
	
	printf("왼쪽 하단의 좌표를 입력하시오:");
	scanf("%d %d", &s.leftlow.x, &s.leftlow.y);

	printf("오른쪽 상단의 좌표를 입력하시오:");
	scanf("%d %d", &s.righthigh.x, &s.righthigh.y);

	xdiff = (double)(s.righthigh.x - s.leftlow.x);
	ydiff = (double)(s.righthigh.y - s.leftlow.y);
	circumfe = (double)(2 * (xdiff + ydiff));
	width = ((double)(xdiff * ydiff ));
	printf("면적은 %f이고 둘레는 %f입니다.", width, circumfe);
	return 0;
}