#include "Enemy.h"

Enemy::Enemy(const string& name, int health, int difficulty) : 
	GameCharacter(name, health), difficulty(difficulty){ }

Enemy::~Enemy() {};