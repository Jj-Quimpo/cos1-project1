#pragma once
#include <string>
#include "Player.h"
enum class RatType
{
	LowlyRat,
	EliteRat,
	RatKnight,
	//BOSSES
	FatRat,
	RoachHunter,
	Abomination
};

class Rat
{
private:
	std::string mName;
	RatType mType;
	int mHealth;
	int mBaseAttack;
	int mCrumbReward;

public:
	Rat(RatType type);

	std::string GetName() const;
	int GetHealth() const;
	int GetCrumbReward() const;
	bool IsAlive() const;

	void TakeDamage(int amount);
	void ExecuteTurn(Player& player, bool isPlayerDefending);
};

