#include<iostream>
#include"DynamicArray.h"
#include"Circle.h"
#include"Rectangle.h"
#include"ShapeContainer.h"
using namespace std;

template<typename T>
void findmax( DynamicArray<T> rhs) {

	double maxarea = -1;
	
	


	for (int i = 0; i < rhs.size(); i++) {
		if (rhs[i]->area() > maxarea) {
			maxarea = rhs[i]->area();
		}
	}

	cout << "도형 중 넓이의 최대값: " << maxarea << endl;
}

int main()
{
	ShapeContainer con1;

	con1.addShape(new Rectangle(2, 4));
	con1.addShape(new Rectangle(3, 4));
	con1.addShape(new Rectangle(5, 4));
	con1.addShape(new Circle(5));
	con1.addShape(new Circle(2));
	
	DynamicArray<int> ins;
	ins.push_back(3);
	ins.printArray();
	DynamicArray<int> ins2 = ins;
	ins2.printArray();

	findmax( con1.container);

	/*cout << maxshape->area() << endl;*/
	return 0;
}