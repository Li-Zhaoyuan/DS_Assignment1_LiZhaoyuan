#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

#include <string>

using std::string;

class GameObject
{
public:
	virtual ~GameObject();
	string getName();
	int getCount();
private:
	string kName;
	int count_;
protected:
	GameObject(const string kName);
};

#endif