#include<iostream>

class Rectangle
{
private:
	int its_length;
	int its_width;
public:
	Rectangle();
	~Rectangle();
	//this는 사용하면 상당히 편한 포인터로 객체 그 자체를 가리키는 포인터이다 또한 컴파일러가 알아서 생성과 삭제를 해 주기 때문에 
	//걱정없이 사용할 수 있는 포인터이다
	void Set_Length(int length) { this->its_length = length; }
	void Set_Width(int width) { this->its_width = width; }
	int Get_Length() const { return this->its_length; }
	int Get_Width() const { return this->its_width; }

	//또한 프로그래밍을 하다 보면 포인터에 메모리를 해체한 이후에 다시 접근하려면 무조건 다시 널 포인터로 만들어 놓고 접근해야 하며
	//아닐 경우 심각한 오류를 초래해 시스템을 마비시킬 수도 있다 또한 삭제한 포인터를 또 삭제하면 심각한 오류가 발생하지만 널 포인터를
	//지우면 아무 일도 일어나지 않는다 또한 널이나 제거 포인터에 값을 할당하면 널 포인터는 간단 오류로 잡히지만 제거 포인터는 최소 프로그램
	//의 치명적 오류가 생길 수 있음으로 삭제 후에는 포인터를 널로 항상 설정해야 한다


};