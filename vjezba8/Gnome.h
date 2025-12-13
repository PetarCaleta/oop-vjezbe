#ifndef GNOME_H
#define GNOME_H

#include "Enemy.h"

class Gnome : public Enemy {
public:
	Gnome(const string& name);
	~Gnome();

	virtual void attackPlayer(Player* target) override;
	void specialAbility() override;
	void displayStatus() const override;

};

#endif // !GNOME_H
