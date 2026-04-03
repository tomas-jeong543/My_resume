#include<stdio.h>

int get_line_parameter(int x1, int y1, int x2, int y2, float* s, float* y)
{
	if (x1 == x2)
		return -1;
	else
	{
		*s = (float)(y2 - y1) / (float)(x2 - x1);
		*y = y1 - (*s) * 1;
		return 0;
	}
}

int main(void)
{
	float s, y;
	if (get_line_parameter(3, 3, 6, 6, &s, &y) == -1)
		printf("애러-1");
	else
		printf("기울기는 %f y절편은 %f", s, y);
	return 0;
	}
//  p = &a == p =&a[0];