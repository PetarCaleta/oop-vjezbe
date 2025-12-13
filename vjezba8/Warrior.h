#ifndef WARRIOR_H
#define WARRIOR_H

#include "Player.h"

class Warrior:public Player {
	bool shieldActive;
public:
	Warrior(const string& name);
	~Warrior();

	void attackEnemy(Enemy* target) override;
	void specialAbility() override;
	void takeDamage(int amount);
	void displayStatus() const override;
};

#endif // !WARRIOR_H
