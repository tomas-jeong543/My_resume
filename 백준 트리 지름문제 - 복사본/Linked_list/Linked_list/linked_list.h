
#include<iostream>
using namespace std;
//단방향 링크드 리스트이다

//자신의 정보와 다음 노드를 가르키는 포인터를 가지는 노드 클래스
class Node
{
public:
	int data;
	Node* next_data;
};

class Linked_List
{
private:
	Node* head;
	Node* tail;

public:
	//생성자
	Linked_List()
	{
		head = NULL;
		tail = NULL;
	}

	//첫 번째 노드 추가
	void addFrontNode(int n);
	//마지막 노드 추가
	void addNode(int n);
	// 노드 삽입
	void insertNode(Node* prevNode, int n);
	//노드 삭제
	void deleteNode(Node* prevNode);
	//첫번째 노드 가져오기
	Node* getHead() {
		return head;
	}
	//링크드 리스트 전체 출력
	void display(Node* head);
	//모든 링크드 리스트 전체 삭제
	void  Delete_Linked_list(Linked_List * info);

};
