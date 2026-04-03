#pragma once
#include"Data.h"
class Node
{
private:

public:
	Node() {};
	virtual ~Node() {}
	virtual Node* Insert(Data* theData) = 0;
	virtual void Show() = 0;
};