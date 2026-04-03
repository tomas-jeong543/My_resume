#pragma once
class Circle
{
private:
	int rad;
public:
	Circle():rad(1){}
	//생성자를 특정 함수를 통해서만 접근 가능하게 만드는 방법 원하는 생성자를  private로 설정하고 함수는 public으로 설정 
	// public부분에서 생성자를 포인터를 이용해 동적 할당을 받고 그 값을 즉 객체를 참조자로 전달한다 이러면 나중에 동적 메모리 할당 해제가 반드시 필요하다
	Circle& Create_circle(int r) {
		Circle* temp = new Circle(r);
		return *temp;
	};
	int Get_circle() { return rad; }
	
private:
	
	Circle(int r) :rad(r){}

};

