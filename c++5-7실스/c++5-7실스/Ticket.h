#pragma once
class Ticket
{
protected:
	static inline int ticketnum = 0;
	int number;
	double price;
public:

	Ticket(const double& price);
	~Ticket() {};
	int getNumber()const;
	virtual double getPrice()const;
	void setPrice(const double& price);
	virtual void show()const;
};

