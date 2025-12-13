#include <vector>
#include <algorithm>
#include "Warrior.h"
#include "Mage.h"
#include "Gnome.h"
#include "Boss.h"

int main() {
    std::vector<GameCharacter*> characters;

    Warrior* conan = new Warrior("Conan");
    Mage* merlin = new Mage("Merlin");
    Gnome* gnomeo = new Gnome("Gnomeo");
    Gnome* sneaky = new Gnome("Sneaky");
    Boss* dragon = new Boss("Dragon");

    characters = { conan, merlin, gnomeo, sneaky, dragon };

    conan->attackEnemy(gnomeo);
    conan->displayStatus(); gnomeo->displayStatus();

    merlin->attackEnemy(sneaky);
    merlin->displayStatus(); sneaky->displayStatus();

    gnomeo->attackPlayer(conan);
    conan->displayStatus(); gnomeo->displayStatus();

    merlin->attackEnemy(gnomeo);
    dragon->attackPlayer(merlin);
    merlin->attackEnemy(gnomeo);

    conan->attackEnemy(dragon);
    merlin->attackEnemy(dragon);

    std::cout << "\n--- Special Abilities ---\n";
    for (auto c : characters)
        if (c->isAlive())
            c->specialAbility();

    std::cout << "\n--- Survivors ---\n";
    GameCharacter* healthiest = nullptr;

    for (auto c : characters) {
        if (c->isAlive()) {
            c->displayStatus();
            if (!healthiest || c->getHealth() > healthiest->getHealth())
                healthiest = c;
        }
    }

    if (healthiest)
        std::cout << "\nNajviše zdravlja ima: "
        << healthiest->getName() << '\n';

    for (auto c : characters)
        delete c;

    return 0;
}