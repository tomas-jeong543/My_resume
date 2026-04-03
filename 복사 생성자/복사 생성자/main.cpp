#include"Cat.h"
using namespace std;

int main()
{
	Cat Frisky;
	cout << "Frisky's age:: " << Frisky.Get_Age() << endl;
	cout << "Setting Frisky to 6 ...\n";
	Frisky.Set_Age(6);
	cout << "creatung boots for ftisky... \n";
	Cat boots(Frisky);
	cout << "frisky's age: " << Frisky.Get_Age() << endl;
	cout << "boot's age: " << boots.Get_Age() << endl;
	cout << "setting frisky to 7... \n";
	Frisky.Set_Age(7);
	cout << "frisky's age: " << Frisky.Get_Age() << endl;
	cout << "boot's age: " << boots.Get_Age() << endl;
	return 0;
}