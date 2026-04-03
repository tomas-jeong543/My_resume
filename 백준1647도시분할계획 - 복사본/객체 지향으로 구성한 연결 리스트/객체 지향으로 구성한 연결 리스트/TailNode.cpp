#include"TailNode.h"
#include"InternalNode.h"

Node* TailNode::Insert(Data* theData)
{
	InternalNode* dataNode = new InternalNode(theData, this);
	return dataNode;
}