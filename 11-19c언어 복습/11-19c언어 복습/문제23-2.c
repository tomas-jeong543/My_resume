/*#include<stdio.h>

typedef struct point
{
	int xpos;
	int ypos;

}Point;

typedef struct rectangle
{
	Point pos1;
	Point pos2;

}Rectangle;

// 넓이를 찾는 함수
void FindSurfaceArea(Rectangle* rec, int *sa) {

	int height, width;
	// 좌표차의 절댓값을 이용해 높이와 너비를 구해 그것을 포인터를 이용해 넓이 변수에 저장한다.
	if ((rec->pos1).ypos - (rec->pos2).ypos > 0)
		height = (rec->pos1).ypos - (rec->pos2).ypos;
	else
		height = -1 * ((rec->pos1).ypos - (rec->pos2).ypos );

	if ((rec->pos1).xpos - (rec->pos2).xpos > 0)
		width = (rec->pos1).xpos - (rec->pos2).xpos;
	else
		width = -1 * ((rec->pos1).xpos - (rec->pos2).xpos);

	*sa = height * width;

}

// 나머지 두 좌표를 찾아 직사각형의 4개의 좌표를 다 출력하는 함수
void FindOtherDotAndPrint(Rectangle * rec) {
	
	
	Point p1, p2;

	// 좌표의 경우 서로 대각선이라는 점을 이용해 각 점의 x,y좌표를 하나씩 점에 대입하고 
	//그 다음에는 그 순서를 바꾸어서 대입한다
	p1.xpos = rec->pos1.xpos;
	p1.ypos = rec->pos2.ypos;

	p2.xpos = rec->pos2.xpos;
	p2.ypos = rec->pos1.ypos;

	printf("점 4개 [%d %d], [%d %d], [%d %d], [%d %d]\n", rec->pos1.xpos, rec->pos1.ypos,
		rec->pos2.xpos, rec->pos2.ypos, p1.xpos, p1.ypos, p2.xpos, p2.ypos);

}


int main(void) {
	//넓이, 넓이 변수를 가르키는 포인터 그리고 점을 나타내는 구조체를 두 개 선언한다.
	int sa;
	int* saptr = &sa;
	Point p1 = { 0,0 };
	Point p2 = { 100, 100 };
	//직사각형 구조체를 선언하고 구조체의 정보를 점의 구조체의 대입을 통해 초기화한다.
	Rectangle rec;
	rec.pos1 = p1;
	rec.pos2 = p2;

	FindSurfaceArea(&rec, saptr);
	printf("넓이 %d\n", sa);

	FindOtherDotAndPrint(&rec);

	return 0;
}*/