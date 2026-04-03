#include"Counter.h"

int main()
{
	Counter  ctr(5);
	int theShort = ctr;
	std::cout << "the_short: " << theShort << endl;
	return 0;
}