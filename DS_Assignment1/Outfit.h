#ifndef OUTFIT_H_
#define OUTFIT_H_

#include "Item.h"

class Outfit: public Item
{
public:
	Outfit(const string& kName, const int& durability_, const int& kSPECIAL);
	virtual ~Outfit();
	const int getSPECIAL();

private:
	const int kSPECIAL;
};

#endif