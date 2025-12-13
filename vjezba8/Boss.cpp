#include "Boss.h"
#include "Player.h"

Boss::Boss(const string& name): Enemy(name, 300, 8){}
Boss::~Boss() {}

void Boss::attackPlayer(Player* target) {
	if (!target || !target->isAlive()) return;

	target->takeDamage(10 * difficulty);
}
void Boss::specialAbility() {
	health += 50;
	if (health > maxHealth) {
		health = maxHealth;
	}
	cout << name << " se regenerira!\n";
}
void Boss::displayStatus() const {
	cout << "[Boss] " << name << " | Health: " << health << "\n";
}
