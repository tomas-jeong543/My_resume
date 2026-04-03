#include"linked_list.h"

//첫 번째 노드 추가
void Linked_List::addFrontNode(int n)
{
	Node* temp = new Node;

	if (temp == NULL) {
		cout << "점 만들기 실패\n";
		return;
	}
	temp->data = n;

	if (head == NULL) {
		head = temp;
		tail = temp;
	}
	else {
		temp->next_data = head;
		head = temp;
	}

}
//마지막 노드 추가
void  Linked_List::addNode(int n)
{
	Node* temp = new Node;

	if (temp == NULL) {
		cout << "점 만들기 실패\n";
		return;
	}
	
	temp->data = n;
	temp->next_data = NULL;
	

	if (head == NULL) {
		head = temp;
		tail = temp;
	}
	else {
		tail->next_data = temp;
		tail = temp;
	}
}
// 노드 삽입
void  Linked_List::insertNode(Node* prevNode, int n)
{

	Node* temp = new Node;

	if (temp == NULL) {
		cout << "점 만들기 실패\n";
		return;
	}
	else {
		temp->data = n;
	}

	//점 연결
	temp->next_data = prevNode->next_data;
	prevNode->next_data = temp;

}
//노드 삭제 이전 노드를 전달한다
void  Linked_List::deleteNode(Node* prevNode)
{
	Node* temp = prevNode->next_data;
	prevNode->next_data = temp->next_data;
	delete temp;
}

void  Linked_List::Delete_Linked_list(Linked_List* info)
{
	info->head = NULL;
	info->tail = NULL;

}

//링크드 리스트 전체 출력
void  Linked_List::display(Node* head)
{
	if (head == NULL) {
		return;
	}
	else {
		cout << head->data << " ";
		display(head->next_data);
	}
}