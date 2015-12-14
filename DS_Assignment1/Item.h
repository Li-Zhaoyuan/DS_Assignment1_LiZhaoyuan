/****************************************************************************/
/*!
\file Item.h
\author Li Zhaoyuan
\par email: 150592K@mymail.nyp.edu.sg
\brief
Contain a class to define an Item.
*/
/****************************************************************************/

#ifndef ITEM_H_
#define ITEM_H_
#include"GameObject.h"

/****************************************************************************/
/*!
Class Item:
\brief An abstract class. Defines an Item and its method
*/
/****************************************************************************/


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