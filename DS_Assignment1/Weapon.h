#ifndef WEAPON_H_
#define WEAPON_H_

class Weapon
{
public:
	Weapon(const string& kName, const int& durability_, const int& kAttackDmg);
	virtual ~Weapon();
	const int getAttackDmg();
private:
	const int kAttackDmg;
};

#endif