#include<stdio.h>
#include "rect.h"
//#define DEBURG

void draw_rect(const RECT* r)
{
#ifdef DEBURG
	printf("draw_area(x = %d,y = %d,w = %d, h = %d)\n", r->x, r->y, r->w, r->h);
#endif
}
 
double calc_area(const RECT* r)
{
	double area;
	area = r->w * r->h;
#ifdef DEBURG
	printf("calc_area() = %f\n", area);
#endif
	return area;
}

void move_rect(RECT* r, int dx, int dy)
{
#ifdef DEBURG
	printf("move_rect(%d, %d)\n", dx, dy);
#endif
	r->x += dx;
	r->y += dy;
}