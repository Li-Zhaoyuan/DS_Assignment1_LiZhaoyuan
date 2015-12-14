#include "Weapon.h"
/****************************************************************************/
/*!
\brief
Initialize Item and kAttackDmg.
\param kName - Item's Name
\param durability_ - Item's durability 
\param kAttackDmg - Item's attackDmg
\return
void
*/
/****************************************************************************/
Weapon::Weapon(const string& kName, const int& durability_, const int& kAttackDmg)
:Item(kName, durability_), kAttackDmg(kAttackDmg)
{

}
/****************************************************************************/
/*!
\brief
destructor
\return
void
*/
/****************************************************************************/
Weapon::~Weapon()
{

}
/****************************************************************************/
/*!
\brief
getter to get weapon's attack damage.
\return
kAttackDmg
*/
/****************************************************************************/
const int Weapon::getAttackDmg()
{
	return kAttackDmg;
}
/****************************************************************************/
/*!
\brief
receiver to change durability value based on half the damage dealt
\param damage - damage dealt to durability
\exception
when damage taken is 1, it does not decrease durability.
\return
void
*/
/****************************************************************************/
void Weapon::receiveDamage(const int& damage)
{
	durability_ -= (damage/2);
}