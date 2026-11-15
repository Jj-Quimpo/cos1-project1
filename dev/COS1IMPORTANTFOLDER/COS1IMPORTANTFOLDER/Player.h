#pragma once
#include <string>
#include <vector>
class Player
{
private: 
	std::string mName;
	int mHealth;
	int mCrumbs;
	int mAttackBonus;
	int mDefenseBonus;
	std::vector<std::string> mInventory;

public:
	Player(const std::string& name);

	std::string GetName() const;
	int GetHealth() const;
	int GetCrumbs() const;
	int GetAttackPower() const;
	int GetDefenseBonus() const;
	const std::vector<std::string>& GetInventory() const;

	void ModifyHealth(int amount);
	void ModifyCrumbs(int amount);
	void UpgradeAttack(int amount);
	void UpgradeDefense(int amount);
	void AddItem(const std::string& item);
	bool IsAlive() const;
};

