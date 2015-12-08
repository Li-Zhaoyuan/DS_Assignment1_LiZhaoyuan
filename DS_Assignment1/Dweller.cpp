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
	this->position_.x = position_.x;
	this->position_.y = position_.y;
}

const Vec2D Dweller::getPosition()
{
	return position_;
}

void Dweller::recieveHealthDamage(const int& health_)
{
	this->health_ -= health_;
}

void Dweller::recieveRadDamage(const int& radiation_)
{
	health_ -= radiation_;
}

void Dweller::recieveEquipmentDamage(const int& durability_)
{
	outfit_->recieveDamage(durability_) ;
	weapon_->recieveDamage(durability_);
}

void Dweller::addStimpak(const int& stimpak_)
{
	this->stimpak_ += stimpak_;
}

void Dweller::addRadaway(const int& radaway_)
{
	this->radaway_ += radaway_;
}

void Dweller::useStimpak()
{
	health_ += 20;
}

void Dweller::useRadAway()
{
	radiation_ -= 10;
}

Outfit* Dweller::assignOutfits(Outfit* outfit_)
{
	this->outfit_ = outfit_;
}

Weapon* Dweller::assignWeapon(Weapon* weapon_)
{
	this->weapon_ = weapon_;
}

bool Dweller::isDead()
{
	if (health_ <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}