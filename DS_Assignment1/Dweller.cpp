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
	if (outfit_ != 0 && outfit_->getDurability() > 0)
	{
		int SPECIALvalue= SPECIAL_;
		int totalSPECIALvalue=0;
		int outfitSPECIALvalue = outfit_->getSPECIAL();
		for (int position = 1000000; position >= 1; position /= 10)
		{
			SPECIALvalue = (SPECIAL_ / position)-((SPECIAL_/(position*10))*10);
			outfitSPECIALvalue = (outfit_->getSPECIAL() / position) - ((outfit_->getSPECIAL() / (position * 10))*10);
			SPECIALvalue += outfitSPECIALvalue;
			if (SPECIALvalue > 9)
			{
				SPECIALvalue = 9;
			}
			totalSPECIALvalue += SPECIALvalue*position;
		}
		return totalSPECIALvalue;
	}
	else
	{
		return SPECIAL_;
	}
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
	else
	{
		return 1;
	}
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

void Dweller::receiveHealthDamage(const int& health_)
{
	if (isDead() != true)
	{
		this->health_ -= health_;
	}
}

void Dweller::receiveRadDamage(const int& radiation_)
{
	if (isDead() != true)
	{
		this->radiation_ += radiation_;
		health_ -= this->radiation_;
	}
}

void Dweller::receiveEquipmentDamage(const int& durability_)
{
	if (outfit_ != 0)
	{
		outfit_->receiveDamage(durability_);
	}
	if (weapon_ != 0)
	{
		weapon_->receiveDamage(durability_/2);
	}
}

void Dweller::addStimpak(const int& stimpak_)
{
	this->stimpak_ += stimpak_;
}

void Dweller::addRadAway(const int& radaway_)
{
	this->radaway_ += radaway_;
}

void Dweller::useStimpak()
{
	if (isDead() != true)
	{
		if (stimpak_ != 0)
		{
			health_ += 20;
			stimpak_ -= 1;
			if (health_ > 100)
			{
				health_ = 100;
			}
		}
	}
	else
	{
		return;
	}
}

void Dweller::useRadAway()
{
	if (isDead() != true)
	{
		if (radaway_ != 0)
		{
			if (radiation_ > 0)
			{
				radaway_ -= 1;
				radiation_ -= 10;
			}
			if (radiation_ < 0)
			{
				radiation_ = 0;
			}
		}
	}
	else
	{
		return;
	}
}

Outfit* Dweller::assignOutfit(Outfit* outfit_)
{
	if (isDead() == false)
	{
		delete this->outfit_;
		this->outfit_ = new Outfit(outfit_->getName(), outfit_->getDurability(), outfit_->getSPECIAL());
		return this->outfit_;
	}
	else
	{
		return this->outfit_;
	}
}

Weapon* Dweller::assignWeapon(Weapon* weapon_)
{
	if (isDead() == false)
	{
		delete this->weapon_; 
		this->weapon_ = new Weapon(weapon_->getName(), weapon_->getDurability(), weapon_->getAttackDmg());
		return this->weapon_;
	}
	else
	{
		return this->weapon_;
	}
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