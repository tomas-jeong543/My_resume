#include "WidgetManager.h"

shared_ptr<Widget> WidgetManager::createWidget(const string& name)
{
	shared_ptr< Widget> newwidgetptr = make_shared<Widget>(name);
	widgets.push_back(newwidgetptr);
	return newwidgetptr;
}

void WidgetManager::displayAll() const
{
	for (int i = 0; i < widgets.size(); i++) {
		widgets[i]->display();
	}
}
