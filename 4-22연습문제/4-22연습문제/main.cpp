#include<iostream>
#include"WidgetManager.h"
int main()
{
	WidgetManager manger;
	manger.createWidget("tomas");
	manger.createWidget("james");
	manger.createWidget("charles");
	manger.displayAll();
	return 0;
}