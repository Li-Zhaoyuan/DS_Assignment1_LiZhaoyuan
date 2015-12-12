#include "Outfit.h"
/****************************************************************************/
/*!
\brief
Initialize Item and kSpecial.
\param rhs
kName of outfit ,durability of outfit, Special of the outfit.
\return
void
*/
/****************************************************************************/
Outfit::Outfit(const string& kName, const int& durability_, const int& kSPECIAL)
:Item(kName, durability_), kSPECIAL(kSPECIAL)
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
Outfit::~Outfit()
{

}
/****************************************************************************/
/*!
\brief
getter to return special value of the outfit.
\return
kSPECIAL
*/
/****************************************************************************/
const int Outfit::getSPECIAL()
{
	return kSPECIAL;
}
/****************************************************************************/
/*!
\brief
change durability based on damage dealt.
\param rhs
damage dealt
\return
void
*/
/****************************************************************************/
void Outfit::receiveDamage(const int& damage)
{
	durability_ -= damage;
}