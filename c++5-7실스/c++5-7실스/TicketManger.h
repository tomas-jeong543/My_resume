#pragma once
#include "Ticket.h"
#include<string>
using std::string;

class TicketManger
{
private:
    string m_name;
    int totalNumber;
    int count = 0;
    Ticket** ticket = nullptr;
public:
    TicketManger() = delete;
    ~TicketManger();
    TicketManger(const string& name, const int number);
    void buy(Ticket* t);
    void show() const;
    void showGeneralTicket(const bool& card);
    void showAdvancedTicket();

};

