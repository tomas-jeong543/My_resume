#include"linked_list.h"
#include<deque>
#include<unordered_map>
int main()
{
	Linked_List info;

	info.addFrontNode(3);
	info.addNode(2);
	info.addNode(1);

	info.display(info.getHead());
	info.Delete_Linked_list(&info);

	cout << "\nafter delete\n";

	info.display(info.getHead());
	return 0;
}