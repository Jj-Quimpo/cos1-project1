#include "Rat.h"
#include <iostream>
#include <cstdlib>

Rat::Rat(RatType type) {
	mType = type;

	if (mType == RatType::LowlyRat) {
		mName = "Lowly Rat";
		mHealth = 40;
		mBaseAttack = 10;
		mCrumbReward = 3;
	}
	else if (mType == RatType::EliteRat) {
		mName = "Elite Rate";
		mHealth = 65;
		mBaseAttack = 15;
		mCrumbReward = 6;
	}
	else if (mType == RatType::RatKnight) {
		mName = "Rat Knight";
		mHealth = 95;
		mBaseAttack = 20;
		mCrumbReward = 12;
	}
}

std::string Rat::GetName() const { return mName; }
int Rat::GetHealth() const { return mHealth; }
int Rat::GetCrumbReward() const { return mCrumbReward; }
bool Rat::IsAlive() const { return mHealth > 0; }

void Rat::TakeDamage(int amount) {
	mHealth -= amount;
	if (mHealth < 0) mHealth = 0;
}

void Rat::ExecuteTurn(Player& player, bool isPlayerDefending) {
	int damage = mBaseAttack;
	int moveRoll = std::rand() % 100;

	// Lowly Rat Moveset
	if (mType == RatType::LowlyRat) {
		if (moveRoll < 70) {
			std::cout << " The Lowly Rat lunges forward with a quick nibble!\n";
		}
		else {
			std::cout << " The Lowly Rat panics and whips its tail wildly!\n";
			damage += 4;
		}
	}
	//Elite Rat Moveset
	else if (mType == RatType::EliteRat) {
		if (moveRoll < 60) {
			std::cout << " The Elite Rat slashes with razor-sharp claws!\n";
		}
		else {
			std::cout << " The Elite Rat lets out a piercing shriek and bites you!\n";
			damage += 7;
		}
	}
	//Rat Knight Moveset
	else if (mType == RatType::RatKnight) {
		if (moveRoll < 50) {
			std::cout << " The Rat Knight swings a sharpened sewing-needle sword!\n";
		}
		else if (moveRoll < 80) {
			std::cout << " The Rat Knight bashes you with its bottlecap shield!\n";
			damage += 6;
		}
		else {
			std::cout << " The Rat Knight chews a moldy cheese scrap and heals 5 HP!\n";
			mHealth += 5;
			return;
		}
	}

	// Apply defense reduction if player chose to Defend
	if (isPlayerDefending) {
		damage /= 3;
		std::cout << "You block most of the blow! You take " << damage << " damage!\n";
	}
	else {
		std::cout << "You take " << damage << " damage!\n";
	}
	player.ModifyHealth(-damage);
}