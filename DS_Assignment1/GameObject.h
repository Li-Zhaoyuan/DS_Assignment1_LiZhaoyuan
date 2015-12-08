#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

#include <string>

using std::string;

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