/****************************************************************************/
/*!
\file Outfit.h
\author Li Zhaoyuan
\par email: 150592K@mymail.nyp.edu.sg
\brief
A class to define an Outfit.
*/
/****************************************************************************/

#ifndef OUTFIT_H_
#define OUTFIT_H_

#include "Item.h"
/****************************************************************************/
/*!
Class Outfit:
\brief Derives from Item class. Defines Outfit's variable and its method.
*/
/****************************************************************************/
class Outfit: public Item
{
public:
	Outfit(const string& kName, const int& durability_, const int& kSPECIAL);
	virtual ~Outfit();
	const int getSPECIAL();
	virtual void receiveDamage(const int& damage);

private:
	const int kSPECIAL ;
};

#endif