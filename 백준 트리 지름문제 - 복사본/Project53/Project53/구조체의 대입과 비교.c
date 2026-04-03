#include<stdio.h>
#include<string.h>

struct point {
	int x;
	int y;
};

int main(void)
{
	struct point p1 = { 10,20 };
	struct point p2 = { 30,40 };

	p2 = p1;
	printf("p2: x, y = %d %d\n", p2.x, p2.y);
	if (p1.x = p2.x)
		printf("Equal");
	return 0;
}