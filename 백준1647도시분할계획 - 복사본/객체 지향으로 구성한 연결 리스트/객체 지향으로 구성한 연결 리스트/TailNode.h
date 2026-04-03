#pragma once
#include"Node.h"
class TailNode : public Node
{
private:

public:
	TailNode() {}
	~TailNode() {}
	virtual Node* Insert(Data* thedata);
	virtual void Show() {}

};