#include "Player.h"

Player::Player(const std::string& name) {
	mName = name.empty() ? "Straggler" : name;
	mHealth = 100;
	mCrumbs = 5;
}

std::string Player::GetName() const {
	return mName;
}
int Player::GetHealth() const {
	return mHealth;
}
int Player::GetCrumbs() const {
	return mCrumbs;
}

void Player::ModifyHealth(int amount) {
	mHealth += amount;
	if (mHealth > 100) mHealth = 100;
	if (mHealth < 0) mHealth = 0;
}

void Player::ModifyCrumbs(int amount) {
	mCrumbs += amount;
	if (mCrumbs < 0) mCrumbs = 0;
}

bool Player::IsAlive() const {
	return mHealth > 0;
}