/*#include<stdio.h>
// 포인터 구조체 선언
typedef struct point {
	int xpos;
	int ypos;
}Point;

// call by reference를 이용해 두 값을 바꾸어주는 함수
void SwapPoint(Point* ptr1, Point* ptr2) {
	Point temp = { 0, 0 };
	Point * Tempptr = &temp;

	*Tempptr = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = *Tempptr;
}

// 좌표 2 개의 정보를 초기화 한 후 출력해주고 Swap후 정보를 출력해준다.
int main(void) {


	Point pos1 = { 2, 4 };
	Point pos2 = { 5, 7};
	printf("Swap 전\n");
	printf("pos1[%d %d], pos2[%d %d]\n", pos1.xpos, pos1.ypos, pos2.xpos, pos2.ypos);

	SwapPoint(&pos1, &pos2);

	printf("Swap 후\n");
	printf("pos1[%d %d], pos2[%d %d]\n", pos1.xpos, pos1.ypos, pos2.xpos, pos2.ypos);

	return 0;
}*/