#include"Rectangle.h"

Rectangle::Rectangle(int width, int height):
	its_height(height),
	its_width(width)
{
}
//중첩된 또다른 생성자이다
Rectangle::Rectangle():
//초기화 단계 주로 참조자와 상수들을 초기화하는데 이용
its_height(5),
its_width(10)
{
	//몸체 단계 나머지 대부분 초기화 시 이용가능
}

//중첩값을 사용하는 경우 합당한 디본값이 존재하지 않을 때
//전혀 다른 알고리즘을 사용할 때
//매개변수 목록에서 다른 형을 사용하기 원할 때 중첩함수를 이용한다
void Rectangle::Draw_Shape() const
{
	Draw_Shape(its_width, its_height);
}

void Rectangle::Draw_Shape(int width, int height, bool cur_value) const
{
	int use_width = width, use_height = height;

	if (!cur_value) {
		use_width = its_width;
		use_height = its_height;
	}
	

	for (int i = 0; i < use_height; i++) {
		for (int j = 0; j < use_width; j++) {
			std::cout << "*";
		}
		std::cout << "\n";
	}
}