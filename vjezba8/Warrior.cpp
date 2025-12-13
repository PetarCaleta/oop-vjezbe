#include "Warrior.h"
#include "Enemy.h"

Warrior::Warrior(const string&name) : Player(name, 120), shieldActive(false){}
Warrior::~Warrior(){}

void Warrior::attackEnemy(Enemy* target) {
	if (!target || !target->isAlive()) return;

	target->takeDamage(20);
	if (!target->isAlive()) {
		addScore(10);
	}
}

void Warrior::specialAbility() {
	shieldActive = true;
	cout << name << "aktivira stit!\n";
}

void Warrior::takeDamage(int amount) {
	if (shieldActive) {
		amount /= 2;
		shieldActive = false;
	}
	GameCharacter::takeDamage(amount);
}
void Warrior::displayStatus() const{
	cout << "[Warrior]" << name << " | Health: " << health << " | Score: " << score << "\n";
}

