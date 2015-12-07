#ifndef WEAPON_H_
#define WEAPON_H_

#include "Item.h"

class Weapon : public Item
{
public:
	Weapon(const string& kName, const int& durability_, const int& kAttackDmg);
	virtual ~Weapon();
	const int getAttackDmg();
private:
	const int kAttackDmg;
};

#endif