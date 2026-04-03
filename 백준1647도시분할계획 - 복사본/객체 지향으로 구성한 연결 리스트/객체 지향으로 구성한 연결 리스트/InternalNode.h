#pragma once
#include"Node.h"

class InternalNode :public Node
{
private:
	Data* mydata;
	Node* mynext;

public:
	InternalNode(Data* theData, Node* next);
	~InternalNode() {delete mynext; delete mydata;}
	virtual Node* Insert(Data* theData);

	 virtual void Show() { mydata->Show(); mynext->Show(); }

};