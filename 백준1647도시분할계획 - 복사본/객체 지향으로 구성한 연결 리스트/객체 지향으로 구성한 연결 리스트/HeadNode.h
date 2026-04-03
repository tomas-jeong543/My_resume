#pragma once
#include"Node.h"

class HeadNode : public Node
{
private:
	Node* mynext;

public:
	HeadNode();
	~HeadNode() { delete mynext; }
	virtual Node* Insert(Data* theData);
	virtual void Show() { mynext->Show(); }
};