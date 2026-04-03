//삼각형의 정보를 나타내는 구조체로 삼각형을 구성하는 점 3개와 넓이 정보로 이루어져 있다.
#include"Point.h"
#ifndef Triangle
#define Triangle

typedef struct Triangle
{
	pos pos1;
	pos pos2;
	pos pos3;
	double surfce_area;

}triangle;

#endif // !Triangle

