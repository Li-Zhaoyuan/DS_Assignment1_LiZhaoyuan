/****************************************************************************/
/*!
\file GameObject.h
\author Li Zhaoyuan
\par email: 150592K@mymail.nyp.edu.sg
\brief
A class to store name and number of objects.
*/
/****************************************************************************/

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include <string>

using std::string;

/****************************************************************************/
/*!
Class GameObject:
\brief An abstract class. Defines its variables and method.
*/
/****************************************************************************/

class GameObject
{
public:
	virtual ~GameObject();
	string getName();
	static int getCount();
private:
	string kName;
	static int count_;
protected:
	GameObject(const string kName);
};

#endif