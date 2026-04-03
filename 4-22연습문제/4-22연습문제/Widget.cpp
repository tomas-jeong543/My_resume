#include "Widget.h"

Widget::Widget(string name):name(name)
{
	nextId += 1;
	this->id = nextId;
}

void Widget::display() const
{
	cout << "이름 " << this->id << " 번호: " << this->name << endl;
}

int Widget::getWidgetCount()
{
	return nextId;
}
