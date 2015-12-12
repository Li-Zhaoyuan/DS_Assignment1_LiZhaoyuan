#include "GameObject.h"
/****************************************************************************/
/*!
\brief
Initialize kName and increasing the count when objects of this type is instantiated
\param rhs
Object's Name
\return
void
*/
/****************************************************************************/
GameObject::GameObject(const string kName)
:kName(kName)
{
	count_ += 1;
}
/****************************************************************************/
/*!
\brief
Decreasing the count when objects of this type is deleted
\return
void
*/
/****************************************************************************/
GameObject::~GameObject()
{
	count_ -= 1;
}
/****************************************************************************/
/*!
\brief
Returns name of the object, getter.
\return
kName
*/
/****************************************************************************/
string GameObject::getName()
{
	return kName;
}
/****************************************************************************/
/*!
\brief
Returns number of object instantiated.
\return
count_
*/
/****************************************************************************/
int GameObject::getCount()
{
	return count_;
}

int GameObject::count_ = 0;