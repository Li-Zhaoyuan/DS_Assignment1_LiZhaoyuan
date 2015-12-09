#ifndef ITEM_H_
#define ITEM_H_
#include"GameObject.h"
class Item : public GameObject
{
public:
	Item(const string& kName, const int& durability_);
	virtual ~Item();
	virtual void receiveDamage(const int& damage) = 0;
	const int getDurability();
private:

protected:
	int durability_;
};

#endif