#include "Item.h"
/****************************************************************************/
/*!
\brief
initialize GameObject, and durability
\return
void
*/
/****************************************************************************/
Item::Item(const string& kName, const int& durability_)
:GameObject(kName), durability_(durability_)
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
Item::~Item()
{

}
/****************************************************************************/
/*!
\brief
getter to get the value of durability
\return
durability
*/
/****************************************************************************/
const int Item::getDurability()
{
	return durability_;
}


