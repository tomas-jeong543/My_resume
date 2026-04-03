#pragma once
#include"HeadNOde.h"
#include"InternalNode.h"
#include"TailNode.h"
class Linked_List
{
private:
	HeadNode* myhead;

public:
	Linked_List();
	~Linked_List() { delete myhead; }
	void Insert(Data* theData);
	void ShowAll() { myhead->Show(); }
};
