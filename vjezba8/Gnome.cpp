#include "Gnome.h"
#include "Player.h"

Gnome::Gnome(const string& name) : Enemy(name, 90, 3){}
Gnome::~Gnome(){}

void Gnome::attackPlayer(Player* target) {
	if (!target || !target->isAlive()) return;
	
	target->takeDamage(5 * difficulty);
}
void Gnome::specialAbility() {
	if (health > 20) {
		cout << name << " svira treubu i zove svoje gnomove u pomoc!\n";
	}

}
void Gnome::displayStatus() const {
	cout << "[Gnome] " << name << " | Health: " << health
		<< " | Difficulty: " << difficulty;
}