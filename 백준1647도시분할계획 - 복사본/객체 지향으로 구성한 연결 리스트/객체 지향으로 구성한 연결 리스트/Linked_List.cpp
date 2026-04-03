#include"Linked_List.h"

Linked_List::Linked_List()
{
	myhead = new HeadNode;
}

void Linked_List::Insert(Data* pData)
{
	myhead->Insert(pData);
}