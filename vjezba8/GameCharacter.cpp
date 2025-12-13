#include "GameCharacter.h"


GameCharacter::GameCharacter(const string& n, int h) : name(n), health(h), maxHealth(h) {}

GameCharacter::~GameCharacter() {}

void GameCharacter::takeDamage(int amount) {
	health -= amount;
	if (health < 0) health = 0;
}

bool GameCharacter::isAlive() const{
	return health > 0;
}

string GameCharacter::getName() const {
	return name;
}

int GameCharacter::getHealth() const {
	return health;
}

