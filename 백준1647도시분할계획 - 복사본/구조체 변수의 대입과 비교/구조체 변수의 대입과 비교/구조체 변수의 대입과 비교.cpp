#include<stdio.h>

struct point
{
	int x;
	int y;
};
int main(void)
{
	int i;
	
	struct point p1 = { 10,20 };
	struct point p2 = { 30,40 };
	
	printf("Before p2.x, p2.y = %d  %d\n", p2.x, p2.y);
	p2 = p1;
	printf("After p2.x, p2.y = %d  %d\n", p2.x, p2.y);

	if (p1.x == p2.x)
		printf("p1과 p2는 같습니다.");
	/*if (p1 == p2)
		printf("p1과 p2는 같습니다.");*/
	return 0;
}
