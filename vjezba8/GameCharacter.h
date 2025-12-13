#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H

#include <iostream>
#include <string>
using namespace std;

class GameCharacter {
protected:
	string name;
	int health;
	int maxHealth;
public:
	GameCharacter(const string& name, int health);
	virtual ~GameCharacter();

	virtual void displayStatus() const = 0;
	virtual void specialAbility() = 0;

	void takeDamage(int amount);
	bool isAlive() const;

	string getName() const;
	int getHealth() const;

};
#endif 