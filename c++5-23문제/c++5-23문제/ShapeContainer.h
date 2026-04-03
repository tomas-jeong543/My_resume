#pragma once
#include"DynamicArray.h"
#include"Circle.h"
#include"Rectangle.h"

class ShapeContainer
{
	
public:
	DynamicArray<Shape*> container;
	void addShape(Shape* shape);
	void removeShape(size_t index);
	~ShapeContainer();

};

