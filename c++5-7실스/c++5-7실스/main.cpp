#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // !DBG_NEW
#endif
#include<iostream>
#include"GeneralTicket.h"
#include"AdvancedTicket.h"
#include"TicketManger.h"
using namespace std;

ostream& operator<<(ostream& out, const TicketManger& ins) {

	ins.show();
	return out;
}


int main()
{
	//main부분
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	cout << "202211364 정명훈" << endl;
	TicketManger manger("아이유콘서트", 10);

	manger.buy(new AdvancedTicket(1000, 40));
	manger.buy(new AdvancedTicket(1500, 30));
	manger.buy(new AdvancedTicket(2000, 25));
	manger.buy(new AdvancedTicket(1000, 5));
	manger.buy(new GeneralTicket(2000, true));
	//manger.buy(new GeneralTicket(2500, true));
	manger.buy(new GeneralTicket(1500, false));
	//manger.buy(new GeneralTicket(2700, false));

	cout << manger << endl;
	manger.showGeneralTicket(true);
	manger.showGeneralTicket(false);
	manger.showAdvancedTicket();
	
	return 0;
}