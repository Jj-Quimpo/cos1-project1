#include "Player.h"

Player::Player(const std::string& name) {
	mName = name.empty() ? "Straggler" : name;
	mHealth = 100;
	mCrumbs = 5;
	mAttackBonus = 0;
	mDefenseBonus = 0;
	mInventory = { "Stale Sugar Crystal" };
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
int Player::GetAttackPower() const {
	return 15 + mAttackBonus;
}
int Player::GetDefenseBonus() const {
	return mDefenseBonus;
}
const std::vector<std::string>& Player::GetInventory() const {
	return mInventory;
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

void Player::AddItem(const std::string& item) {
	mInventory.push_back(item);
	if (item == "Splinter Spear") {
		mAttackBonus += 7;
	}
	else if (item == "Soda Tab Buckler") {
		mDefenseBonus += 4;
	}
}

bool Player::IsAlive() const {
	return mHealth > 0;
}