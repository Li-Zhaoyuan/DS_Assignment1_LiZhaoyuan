/****************************************************************************/
/*!
\file Weapon.h
\author Li Zhaoyuan
\par email: 150592K@mymail.nyp.edu.sg
\brief
Contain a class to define Weapon.
*/
/****************************************************************************/

#ifndef WEAPON_H_
#define WEAPON_H_

#include "Item.h"
/****************************************************************************/
/*!
Class Weapon:
\brief Derives from Item class. Defines Weapon's variables and methods
*/
/****************************************************************************/
class Weapon : public Item
{
public:
	Weapon(const string& kName, const int& durability_, const int& kAttackDmg);
	virtual ~Weapon();
	const int getAttackDmg();
	virtual void receiveDamage(const int& damage);
private:
	const int kAttackDmg;
};

#endif