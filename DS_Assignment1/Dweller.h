#ifndef DWELLER_H_
#define DWELLER_H_

#include "GameObject.h"
#include "Vec2D.h"
#include "Outfit.h"
#include "Weapon.h"

class Dweller : public GameObject
{
public:
	Dweller(const string& kName, const int& SPECIAL_);
	virtual ~Dweller();
	const int getSPECIAL();
	const int getCurrentHealth();
	const int getCurrentRadDamage();
	const int getAttackDmg();
	void setPosition(const Vec2D& position_);
	const Vec2D getPosition();
	void recieveHealthDamage(const int& health_);
	void recieveRadDamage(const int& radiation_);
	void recieveEquipmentDamage(const int& durability_);
	void addStimpak(const int& stimpak);
	void addRadaway(const int& radaway);
	void useStimpak();
	void useRadAway();
	Outfit* assignOutfits(Outfit* outfit_);
	Weapon* assignWeapon(Weapon* weapon_);
	bool isDead();
private:
	Vec2D position_;
	int SPECIAL_;
	int health_;
	int radiation_;
	int stimpak_;
	int radaway_;
	Outfit* outfit_;
	Weapon* weapon_;


};

#endif