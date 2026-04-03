#pragma once
#include "Ticket.h"
class AdvancedTicket:
    public Ticket
{
private:
    int advanceDays;
public:
    AdvancedTicket(const double& price, const int& days);
    ~AdvancedTicket() {};
    double getPrice() const override;
    int getAdvanceDays() const;
    void show() const override;

};

