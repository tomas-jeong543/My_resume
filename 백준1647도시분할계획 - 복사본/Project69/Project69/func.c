#include"Point.h"
#include"Triangle.h"
#include<math.h>
#include<stdlib.h>
// 삼각형의 널이를 구하는 함수
double Get_Surface_Area(triangle* TriangleInfo)
{

	//신발끈 공식과 절대값 함수를 이용한 삼각형 넓이 구하기
	double surface_area = 0.5 * (fabs((TriangleInfo->pos1.x * TriangleInfo->pos2.y) +
		(TriangleInfo->pos2.x * TriangleInfo->pos3.y) + (TriangleInfo->pos3.x * TriangleInfo->pos1.y)
	- (TriangleInfo->pos2.x * TriangleInfo->pos1.y) - (TriangleInfo->pos3.x * TriangleInfo->pos2.y)
	- (TriangleInfo->pos1.x * TriangleInfo->pos3.y)));

	return surface_area;
}

// 삼각형 정보를 입력 받은 점을 통해 입력하는 함수
void Make_Triangle(triangle* TriangleInfo, pos* Polygoninfo, int pointnum)
{
	int posidx2 = 1, posidx3 = 2;


	for (int i = 0; i < pointnum - 2; i++) {
		// 점 정보를 점 정보가 담긴 구조체를 통해 입력 받음
		//이 때 다각형을 이루는 순서대로 N개의 점의 x, y좌표가 주어진다는 조건을 이용해
		//다각형을 삼각형으로 나눌 때 기준 점을 하나 설정하고 나머지 두 점을 바꾼다.
		TriangleInfo[i].pos1 = Polygoninfo[0];
		TriangleInfo[i].pos2 = Polygoninfo[posidx2];
		TriangleInfo[i].pos3 = Polygoninfo[posidx3];
		// 넓이 정보를 위의 넓이를 구하는 함수를 통해 입력 받음
		TriangleInfo[i].surfce_area = Get_Surface_Area(&TriangleInfo[i]);

		posidx2++;
		posidx3++;
	}

}

//다각형의 넓이를 소숫점 두자리 숫자에서 반올림해 소수점 한자리 수까지 표현하게 하는 함수
void RoundingFunc(double * surf_area)
{
	// 일단 곱하기 100을 하고 정수형 변수로 바꾼다. 
	double ins = (*surf_area) * 100;
	int ins2 = (int)ins;

	// 구 후 일의 자리 숫자를 나머지 연산을 이용해 구한다.
	int leftover = ins2 % 10;

	// 일의 자리 숫자가 5이상이면 반올림 해 십의 자리까지 표현한다.
	if (leftover >= 5) {
		ins2 += 10;
		ins2-= leftover;
	}

	// 십의 자리까지 표현된 수를 100으로 나눈다. 그러면 결과적으로 소수점 둘째 자리 숫자를 반올림 한것과 같다.
	*surf_area = (double)ins2 / 100.0;
}