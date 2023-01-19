#include "Cell.h"

Cell::Cell()
{
	this->HP = 0;
}

int Cell::getHP() const
{
	return this->HP;
}

void Cell::setHP(int newHP) 
{
	this->HP = newHP;
}

