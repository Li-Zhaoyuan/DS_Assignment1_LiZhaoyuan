#include "Dweller.h"
/****************************************************************************/
/*!
\brief
Initialize GameObject, position_, SPECIAL_, health_, radiation_, stimpak_,
radaway_,outfit_ and weapon_.
\param kName - name of dweller
\param SPECIAL_ - dweller's SPECIAL_
\return
void
*/
/****************************************************************************/
Dweller::Dweller(const string& kName, const int& SPECIAL_)
:GameObject(kName), position_(0, 0), SPECIAL_(SPECIAL_),
health_(100), radiation_(0), stimpak_(0), radaway_(0), outfit_(0),
weapon_(0)
{
}
/****************************************************************************/
/*!
\brief
destructor where will delete weapon_ and outfit_.
\return
void
*/
/****************************************************************************/
Dweller::~Dweller()
{
	delete weapon_;
	delete outfit_;
}
/****************************************************************************/
/*!
\brief
getter to get SPECIAL total value.

\return
dweller's SPECIAL_ or dweller's SPECIAL added with its outfit's special value
*/
/****************************************************************************/
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
/****************************************************************************/
/*!
\brief
getter to get the amount of health the dweller have.
\return
 current health of dweller
*/
/****************************************************************************/
const int Dweller::getCurrentHealth()
{
	return health_;
}
/****************************************************************************/
/*!
\brief
getter to get current amount of radiation the dweller have.
\return
current radiation value for dweller
*/
/****************************************************************************/
const int Dweller::getCurrentRadDamage()
{
	return radiation_;
}
/****************************************************************************/
/*!
\brief
getter to get attack damage of dweller with or without weapon

\return
total attack damage witho or without weapon
*/
/****************************************************************************/
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
/****************************************************************************/
/*!
\brief
setter to set the position of the dweller
\param position_ - coordinate x and y
\return
void
*/
/****************************************************************************/
void Dweller::setPosition(const Vec2D& position_)
{
	this->position_.x = position_.x;
	this->position_.y = position_.y;
}
/****************************************************************************/
/*!
\brief
getter to get the position of the dweller

\return
position of dweller
*/
/****************************************************************************/
const Vec2D Dweller::getPosition()
{
	return position_;
}
/****************************************************************************/
/*!
\brief
receiver to decrease health  based on the value passed in by parameter.
\param health_ - damage to health
\return void
*/
/****************************************************************************/
void Dweller::receiveHealthDamage(const int& health_)
{
	if (isDead() != true)
	{
		this->health_ -= health_;
	}
}
/****************************************************************************/
/*!
\brief
receiver to increase radiation value and decrease health based on radiation
\param radiation_ - amount of radiation received
\return
void
*/
/****************************************************************************/
void Dweller::receiveRadDamage(const int& radiation_)
{
	if (isDead() != true)
	{
		this->radiation_ += radiation_;
		health_ -= this->radiation_;
	}
}
/****************************************************************************/
/*!
\brief
receiver to decrease the durability value of outfit and weapon
\param durability_ - damage to durability
\return
void
*/
/****************************************************************************/
void Dweller::receiveEquipmentDamage(const int& durability_)
{
	if (outfit_ != 0)
	{
		outfit_->receiveDamage(durability_);
	}
	if (weapon_ != 0)
	{
		weapon_->receiveDamage(durability_);
	}
}
/****************************************************************************/
/*!
\brief
adds to the total amount of stimpak
\param stimpak_ - amount of stimpak to be added
\return
void
*/
/****************************************************************************/
void Dweller::addStimpak(const int& stimpak_)
{
	this->stimpak_ += stimpak_;
}
/****************************************************************************/
/*!
\brief
adds the amount of radaway
\param radaway_ - amount of radaway to be added
\return
void
*/
/****************************************************************************/
void Dweller::addRadAway(const int& radaway_)
{
	this->radaway_ += radaway_;
}
/****************************************************************************/
/*!
\brief
decreases amount of stimpak to increase health
\return
void
*/
/****************************************************************************/
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
/****************************************************************************/
/*!
\brief
decreases number of radaway to decrease radiation
\return
void
*/
/****************************************************************************/
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
/****************************************************************************/
/*!
\brief
assign outfit_ with new Outfit
\param outfit_ - Outfit
\return
outfit_
*/
/****************************************************************************/
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
/****************************************************************************/
/*!
\brief
assign weapon_ with new weapon

\return
weapon_
*/
/****************************************************************************/
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
/****************************************************************************/
/*!
\brief
ister to determine if the dweller is alive or not.

\return
true/false
*/
/****************************************************************************/
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