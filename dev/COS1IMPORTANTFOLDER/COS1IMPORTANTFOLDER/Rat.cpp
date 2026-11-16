#include "Rat.h"
#include <iostream>
#include <cstdlib>

Rat::Rat(RatType type) {
	mType = type;
	mHealth = 0;
	mBaseAttack = 0;
	mCrumbReward = 0;

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
	else if (mType == RatType::FatRat) {
		mName = "BOSS: The Fat Rat";
		mHealth = 150;
		mBaseAttack = 18;
		mCrumbReward = 25;
	}
	else if (mType == RatType::RoachHunter) {
		mName = "BOSS: The Roach Hunter";
		mHealth = 120;
		mBaseAttack = 24;
		mCrumbReward = 30;
	}
	else if (mType == RatType::Abomination) {
		mName = "BOSS: The Wall Abomination";
		mHealth = 185;
		mBaseAttack = 22;
		mCrumbReward = 45;
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
	bool pierceArmor = false;
	// Lowly Rat Moveset
	if (mType == RatType::LowlyRat) {
		if (moveRoll < 70) {
			std::cout << "The Lowly Rat lunges forward with a quick nibble!\n";
		}
		else {
			std::cout << "The Lowly Rat panics and whips its tail wildly!\n";
			damage += 4;
		}
	}
	//Elite Rat Moveset
	else if (mType == RatType::EliteRat) {
		if (moveRoll < 60) {
			std::cout << "The Elite Rat slashes with razor-sharp claws!\n";
		}
		else {
			std::cout << "The Elite Rat lets out a piercing shriek and bites you!\n";
			damage += 7;
		}
	}
	//Rat Knight Moveset
	else if (mType == RatType::RatKnight) {
		if (moveRoll < 50) {
			std::cout << "The Rat Knight swings a sharpened sewing-needle sword!\n";
		}
		else if (moveRoll < 80) {
			std::cout << "The Rat Knight bashes you with its bottlecap shield!\n";
			damage += 6;
		}
		else {
			std::cout << "The Rat Knight chews a moldy cheese scrap and heals 5 HP!\n";
			mHealth += 5;
			return;
		}
		//BOSS FAT RAT MOVESET
	}
	else if (mType == RatType::FatRat) {
		if (moveRoll < 45) {
			std::cout << "The Fat Rat rolls its massive body forward in a Belly Slam!\n";
			damage += 8;
		}
		else if (moveRoll < 75) {
			std::cout << "The Fat Rat swallows a whole slice of crust and heals 20 HP!\n";
			mHealth += 20;
			return;
		}
		else {
			std::cout << "The Fat Rat stomps the floor, sending splinters flying!\n";
		}
	}
	//ROACH HUNTER MOVESET
	else if (mType == RatType::RoachHunter) {
		if (moveRoll < 45) {
			std::cout << "The Roach Hunter blasts a cloud of Raid Toxic Spray! (Ignores Defense!)\n";
			pierceArmor = true;
		}
		else if (moveRoll < 80) {
			std::cout << "The Roach Hunter slams a mousetrap onto your shell!\n";
			damage += 10;
		}
		else {
			std::cout << "The Roach Hunter strikes with twin toothpick daggers!\n";
			damage += 6;
		}
	}
	//ABOMINATION MOVESET
	else if (mType == RatType::Abomination) {
		if (moveRoll < 40) {
			std::cout << "The Abomination spits glowing green drain-cleaner acid! (Ignores Defense!)\n";
			pierceArmor = true;
			damage += 5;
		}
		else if (moveRoll < 75) {
			std::cout << "The Abomination thrashes with six mutated rat tail!\n";
			damage += 9;
		}
		else {
			std::cout << "The Abomination's mutated cells knit together, regenerating 25HP!\n";
			mHealth += 25;
			return;
		}
	}
	//Regular attacks get a damage reduction for defense while pierceArmor ignors
	if (!pierceArmor) {
		damage -= player.GetDefenseBonus();
		if (damage < 1) damage = 1;

		if (isPlayerDefending) {
			damage /= 3;
			std::cout << "You block most of the blow! You take " << damage << " damage!\n";
		}
		else {
			std::cout << "You take " << damage << " damage!\n";
		}
		player.ModifyHealth(-damage);
	}
}