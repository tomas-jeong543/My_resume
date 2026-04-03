#pragma once
#include "Ticket.h"
class GeneralTicket :
    public Ticket
{
private:
    bool payByCredit;
public:
    GeneralTicket( const double& price, bool card);
    ~GeneralTicket() {};
    double getPrice() const override;
    bool getpaybyCredit() const;
    void show() const override;
};

