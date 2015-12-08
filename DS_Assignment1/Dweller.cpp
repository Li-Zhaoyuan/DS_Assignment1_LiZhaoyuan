#include "Dweller.h"

Dweller::Dweller(const string& kName, const int& SPECIAL_)
:GameObject(kName), position_(0, 0), SPECIAL_(SPECIAL_),
health_(100), radiation_(0), stimpak_(0), radaway_(0), outfit_(0),
weapon_(0)
{
	
}

Dweller::~Dweller()
{
	delete weapon_;
	delete outfit_;
}

const int Dweller::getSPECIAL()
{
	return SPECIAL_;
}

const int Dweller::getCurrentHealth()
{
	return health_;
}

const int Dweller::getCurrentRadDamage()
{
	return radiation_;
}

const int Dweller::getAttackDmg()
{
	if (weapon_ != 0 && weapon_->getDurability()>0)
	{
		return weapon_->getAttackDmg();
	}
	return 1;
}

void Dweller::setPosition(const Vec2D& position_)
{
	this->position_ = position_;
}