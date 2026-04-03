#include "ShapeContainer.h"
#include<iostream>
#include<memory>

using namespace std;

void ShapeContainer::addShape(Shape* shape)
{
	this->container.push_back(shape);
}

void ShapeContainer::removeShape(size_t index)
{
	if (index >= 0 && index < this->container.size()) {
		this->container.pop(index);
	}
}

ShapeContainer::~ShapeContainer()
{
	while (container.size() > 0) {
		delete container[container.size() - 1];
		container.pop_back();
	}
	
}
