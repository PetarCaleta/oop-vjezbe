#include "Player.h"
#include "Enemy.h"

Player::Player(const string& name, int health) : GameCharacter(name,health), score(0){}
Player::~Player() {}

void Player::addScore(int points) {
    score += points;
}

int Player::getScore() const {
    return score;
}