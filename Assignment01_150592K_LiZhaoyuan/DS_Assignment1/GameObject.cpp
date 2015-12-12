#include "GameObject.h"

GameObject::GameObject(const string kName)
:kName(kName)
{
	count_ += 1;
}
GameObject::~GameObject()
{
	count_ -= 1;
}

string GameObject::getName()
{
	return kName;
}
int GameObject::getCount()
{
	return count_;
}

int GameObject::count_ = 0;