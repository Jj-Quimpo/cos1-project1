#include "Player.h"

Player::Player(const std::string& name) {
	mName = name.empty() ? "Straggler" : name;
	mHealth = 100;
	mCrumbs = 5;
	mAttackBonus = 0;
	mDefenseBonus = 0;
	mSpearLevel = 1;
	mShieldLevel = 1;
	mInventory = { "Splinter Spear (Lv. 1)","Soda Tab Buckler (Lv. 1)", "Stale Sugar Crystal" };
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
int Player::GetSpearLevel() const { 
	return mSpearLevel; 
}
int Player::GetShieldLevel() const {
	return mShieldLevel;
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

void Player::UpgradeAttack(int amount) {
	mAttackBonus += amount;
	std::string oldSpear = "Splinter Spear (Lv. " + std::to_string(mSpearLevel) + ")";
	mSpearLevel++;
	std::string newSpear = "Splinter Spear (Lv. " + std::to_string(mSpearLevel) + ")";

	auto it = std::find(mInventory.begin(), mInventory.end(), oldSpear);
	if (it != mInventory.end()) {
		*it = newSpear;
	}
}

void Player::UpgradeDefense(int amount) {
	mDefenseBonus += amount;
	std::string oldShield = "Soda Tab Buckler (Lv. " + std::to_string(mShieldLevel) + ")";
	mShieldLevel++;
	std::string newShield = "Soda Tab Buckler (Lv. " + std::to_string(mShieldLevel) + ")";

	auto it = std::find(mInventory.begin(), mInventory.end(), oldShield);
	if (it != mInventory.end()) {
		*it = newShield;
	}
}

void Player::AddItem(const std::string& item) {
	mInventory.push_back(item);
}
bool Player::UseHealingItem() {
	auto cubeIt = std::find(mInventory.begin(), mInventory.end(), "Sugar Cube");
	if (cubeIt != mInventory.end()) {
		mInventory.erase(cubeIt);
		ModifyHealth(35);
		return true;
	}

	auto crystalIt = std::find(mInventory.begin(), mInventory.end(), "Stale Sugar Crystal");
	if (crystalIt != mInventory.end()) {
		mInventory.erase(crystalIt);
		ModifyHealth(15);
		return true;
	}
	return false;
}
int Player::GetItemCount(const std::string& itemName) const {
	return static_cast<int>(std::count(mInventory.begin(), mInventory.end(), itemName));
}
int Player::GetHealingItemCount() const {
	int count = 0;
	for (const std::string& item : mInventory) {
		if (item == "Sugar Cube" || item == "Stale Sugar Crystal") {
			count++;
		}
	}
	return count;
}
bool Player::UseSpecificItem(const std::string& itemName) {
	auto it = std::find(mInventory.begin(), mInventory.end(), itemName);
	if (it != mInventory.end()) {
		mInventory.erase(it);

		if (itemName == "Sugar Cube") {
			ModifyHealth(35);
		}
		else if (itemName == "Stale Sugar Crystal") {
			ModifyHealth(15);
		}
		return true;
	}
	return false;
}

bool Player::IsAlive() const {
	return mHealth > 0;
}