#ifndef MAGE_H
#define MAGE_H

#include "Player.h"

class Mage : public Player {
	int mana;
public:
	Mage(const string& name);
	~Mage();

	void attackEnemy(Enemy* target) override;
	void specialAbility() override;
	void displayStatus() const override;
};

#endif // !MAGE_h
