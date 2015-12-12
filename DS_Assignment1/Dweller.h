/****************************************************************************/
/*!
\file Dweller.h
\author Li Zhaoyuan
\par email: 150592K@mymail.nyp.edu.sg
\brief
Contain a class to define a dweller.
*/
/****************************************************************************/


#ifndef DWELLER_H_
#define DWELLER_H_

#include "GameObject.h"
#include "Vec2D.h"
#include "Outfit.h"
#include "Weapon.h"
/****************************************************************************/
/*!
Class Dweller:
\brief Derives from GameObject class. Defines Dweller variables and method.
*/
/****************************************************************************/
class Dweller : public GameObject
{
public:
	Dweller(const string& kName, const int& SPECIAL_ = 0);
	virtual ~Dweller();
	const int getSPECIAL();
	const int getCurrentHealth();
	const int getCurrentRadDamage();
	const int getAttackDmg();
	void setPosition(const Vec2D& position_);
	const Vec2D getPosition();
	void receiveHealthDamage(const int& health_);
	void receiveRadDamage(const int& radiation_);
	void receiveEquipmentDamage(const int& durability_);
	void addStimpak(const int& stimpak_);
	void addRadAway(const int& radaway_);
	void useStimpak();
	void useRadAway();
	Outfit* assignOutfit(Outfit* outfit_);
	Weapon* assignWeapon(Weapon* weapon_);
	bool isDead();
	
private:
	//Vec2D position_();
	Vec2D position_;
	int SPECIAL_;
	int health_ ;
	int radiation_;
	int stimpak_;
	int radaway_;
	Outfit* outfit_;
	Weapon* weapon_;


};

#endif