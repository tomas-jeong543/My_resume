#include"InternalNode.h"
#include"Data.h"
InternalNode::InternalNode(Data* thedata, Node* next)
	: mydata(thedata) ,mynext(next)
{

}

Node* InternalNode::Insert(Data* theData)
{
	int result =mydata->Compare(*theData);
	//int result = 1;
	switch (result) {
	case kIsSame:
		return this;

	case kIsLarger: {
		InternalNode* dataNode = new InternalNode(theData, this);
		return dataNode;
	}

	case kIsSmaller:
		mynext = mynext->Insert(theData);
		return this;

	}



}