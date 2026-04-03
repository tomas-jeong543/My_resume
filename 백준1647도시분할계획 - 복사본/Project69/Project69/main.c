/*문제
2차원 평면상에 N(3 ≤ N ≤ 10, 000)개의 점으로 이루어진 다각형이 있다.이 다각형의 면적을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다.다음 N개의 줄에는 다각형을 이루는 순서대로 N개의 점의 x, y좌표가 주어진다.좌표값은 
절댓값이 100, 000을 넘지 않는 정수이다.

출력
첫째 줄에 면적을 출력한다.면적을 출력할 때에는 소수점 아래 둘째 자리에서 반올림하여 첫째 자리까지 출력한다.
다각형 polygon*/

// 12-10 ~ 12-11 4시간 해결 정답률 보고 긴장했는데 생각보다 해결방법만 떠올리면 구현이 어렵지는 않았다.
#include<stdio.h>
#include"Point.h"
#include"Triangle.h"
#include<stdlib.h>
#include"func.h"
#include<string.h>

// 입력 버퍼를 비우는 함수
void RemoveLineBuf() {
	while (getchar() != '\n');
}

int main(void) {

	//넓이 변수와 꼭짓점 변수 개수 선언 및 초기화
	double Poly_Surface_Area = 0;
	int Polygon_Point_Num = 0;
	
	
	// 니 문제의 핵심은 다각형을 삼각형으로 쪼개서 넓이를 구하는 것이다, 따라서 삼각형 구조체와
	//점 구조체를 동적할당 하기 위해 포인터를 선언한다.
	triangle* TriangleInfo;
	pos* Polygoninfo;
	
	//개수 입력
	fputs("N 다각형의 점의 개수 N을 입력하시오:(3 ≤ N ≤ 10, 000)", stdout);
	scanf_s("%d", &Polygon_Point_Num);

	RemoveLineBuf();
	// 개수 정보를 이용한 동적 할당
	TriangleInfo = (triangle*)malloc(sizeof(triangle) * (Polygon_Point_Num - 2));
	Polygoninfo = (pos*)malloc(sizeof(pos) * Polygon_Point_Num);
	// 메모리 할당 중 오류 발샐 시 예외처리
	if (TriangleInfo == NULL || Polygoninfo == NULL) {
		puts("오류 발생");
		return -1;
	}

	// 다각형의 좌표를 순차적으로 입력받아 점의 정보를 가르키는 배열에 저장한다.
	for (int i = 0; i < Polygon_Point_Num; i++) {
		printf("다각형의 점 %d의 좌표(x, y) 입력 (공백으로 구분 다각형 순서대로 입력): ",  i + 1);
		scanf_s("%lf %lf", &Polygoninfo[i].x, &Polygoninfo[i].y);
		RemoveLineBuf();
	}

	// 점의 정보를 이용해 삼각형을 만들고 삼각형의 넓이를 구한다.
	Make_Triangle(TriangleInfo, Polygoninfo, Polygon_Point_Num);

	// 다각형을 이루는 삼각형의 넓이를 다 더해 다각형의 넓이를 구한다.
	for (int i = 0; i < Polygon_Point_Num; i++) {
		Poly_Surface_Area += TriangleInfo[i].surfce_area;
	}

	//널비을 소수점 둘째자리에서 반올림해 소수점 첫 번째 자리까지 반올림한다.
	RoundingFunc(&Poly_Surface_Area);

	//넓이 출력
	printf("다각형의 넓이는 %.1f 이다.",Poly_Surface_Area);

	return 0;
	//동적 할당 메모리 해제
	free(TriangleInfo);
	free(Polygoninfo);
}