#include"Dice.h"
#include<ctime>

void Dice::roll()

{
	srand(static_cast<unsigned>(time(NULL)));
	faceValue = (rand() % 6 )+ 1;
}