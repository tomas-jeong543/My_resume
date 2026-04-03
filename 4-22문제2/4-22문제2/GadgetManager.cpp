#include "GadgetManager.h"

int GadgetManager::getInventoryCount()
{
    return gadgets.size();
}

void GadgetManager::displayAll() const
{
    for(auto gadget: gadgets){
        gadget->display();
    }
}
