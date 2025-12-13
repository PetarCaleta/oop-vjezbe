#ifndef ENEMY_H
#define ENEMY_H

#include "GameCharacter.h"
class Player;

class Enemy : public GameCharacter {
protected:
	int difficulty;
public:
	Enemy(const string& name, int health, int difficulty);
	virtual ~Enemy();

	virtual void attackPlayer(Player* target) = 0;
};


#endif // !ENEMY_H
