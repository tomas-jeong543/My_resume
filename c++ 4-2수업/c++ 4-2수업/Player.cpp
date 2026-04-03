#include"Player.h"

void Player::Setname(const string& name)
{

	this->name = name;
}

void Player::roll(Dice& d1, Dice& d2)
{
	d1.roll();
	d2.roll();
	total = d1.getFaceValue() + d2.getFaceValue();
}
