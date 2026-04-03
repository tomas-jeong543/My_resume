#include"Square.h"

int main()
{
	Square ex(3);
	cout << "ex1\n";
	cout <<"height: " <<  ex.Get_height() << " width: " << ex.Get_width() << "\n";

	Square ex2(ex);
	cout << "ex2\n";
	cout << "height: " << ex2.Get_height() << " width: " << ex2.Get_width() << "\n";

	ex.Set_height(5);
	ex.Set_width(7);
	cout << "ex1\n";
	cout << "height: " << ex.Get_height() << " width: " << ex.Get_width() << "\n";
	cout << "ex2\n";
	cout << "height: " << ex2.Get_height() << " width: " << ex2.Get_width() << "\n";


	return 0;
}