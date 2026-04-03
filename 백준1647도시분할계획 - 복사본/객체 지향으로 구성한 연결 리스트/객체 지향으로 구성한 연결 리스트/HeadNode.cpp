#include"HeadNode.h"
#include"TailNode.h"

HeadNode::HeadNode()
{
	mynext = new TailNode;
}

Node* HeadNode::Insert(Data* theData)
{
	mynext = mynext->Insert(theData);
	return this;
}