#include<stdio.h>
#include<string.h>

struct point {
	int x;
	int y;
};

struct point2 {
	int x;
	int y;
	struct point z;//deep copy는 여기까지 copy 되는 것 shallow copy는 copy가 안된다.
};

int main(void)
{
	struct point2 p1 = { 10,20,{ 30,40 } };
	struct point2 p2 = { 30,40,{ 30,40 } };
	printf("%d %d %d %d\n", p1.x, p1.y, p1.z.x, p1.z.y);
	p1 = p2; printf("%d %d %d %d\n", p1.x, p1.y, p1.z.x, p1.z.y);
	return 0;
}