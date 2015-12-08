#include "Weapon.h"

Weapon::Weapon(const string& kName, const int& durability_, const int& kAttackDmg)
:Item(kName, durability_), kAttackDmg(kAttackDmg)
{

}

Weapon::~Weapon()
{

}

const int Weapon::getAttackDmg()
{
	return kAttackDmg;
}