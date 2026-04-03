#pragma once
#include"Bird.h"
#include"Horse.h"

class Pegasus : public Horse, public Bird
{
public:
	//다중 상속을 이용한 메소드 오버라이딩 원래는 새의 함수를 가상 함수로 받았지만 말의 함수를 실행시킨다
	void Chrip() const { Whinny(); }
	Pegasus() { cout << "Pegasus constructor... \n"; }
	~Pegasus() { cout << "Pegasus distructor... \n"; }

};