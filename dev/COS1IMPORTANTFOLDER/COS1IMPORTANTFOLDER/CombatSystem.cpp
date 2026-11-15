#include "CombatSystem.h"
#include "Helper.h"
#include <iostream>
#include <cstdlib>
#include "Rat.h"

void CombatSystem::EngageBattle(Player& player, int currentFloor, bool isBoss)
{
	Helper::ClearConsoleWindow();

	int spawnRoll = std::rand() % 100;
	RatType selectedType = RatType::LowlyRat;

	if (isBoss) {
		int bossRoll = std::rand() % 3;
		if (bossRoll == 0) selectedType = RatType::FatRat;
		else if (bossRoll == 1) selectedType = RatType::RoachHunter;
		else selectedType = RatType::Abomination;
	}
	else {
		if (currentFloor < 5) {
			selectedType = RatType::LowlyRat;
		}
		else if (currentFloor < 10) {
			selectedType = (spawnRoll < 65) ? RatType::LowlyRat : RatType::EliteRat;
		}
		else {
			if (spawnRoll < 40) selectedType = RatType::LowlyRat;
			else if (spawnRoll < 75) selectedType = RatType::EliteRat;
			else selectedType = RatType::RatKnight;
		}
	}

	Rat enemy(selectedType);
	std::cout << "======================================================\n";
	if (isBoss) {
		std::cout << "BOSS FLOOR! " << enemy.GetName() << " APPEARS!\n";
	}
	else {
		std::cout << "RAT AMBUSH! A " << enemy.GetName() << " BLOCKS YOUR PATH!\n";
	}
	std::cout << "======================================================\n\n";

	unsigned int round = 1;

	while (player.IsAlive() && enemy.IsAlive()) {
		
		bool isDefending = false;
		int sugarCubes = player.GetItemCount("Sugar Cube");
		int staleCrystals = player.GetItemCount("Stale Sugar Crystal");

		std::cout << "[ROUND " << round << "]\n";
		std::cout << player.GetName() << " HP: " << player.GetHealth() << " | " << enemy.GetName() << " HP: " << enemy.GetHealth() << "\n";
		std::cout << "_____________________________________________________________________________________________________________\n";
		std::cout << "1) Attack (Power: " << player.GetAttackPower() << ")\n";
		std::cout << "2) Defend (Defense Bonus: " << player.GetDefenseBonus() << ")\n";
		std::cout << "3) Use Healing Item\n";
		std::cout << "4) Desperate Scramble (Try to flee)\n";
		
		unsigned int choice = Helper::GetChoice(1, 4);
		std::cout << "\n";

		if (choice == 1) {
			int attackDamage = player.GetAttackPower();
			std::cout << "You strike the " << enemy.GetName() << " for " << attackDamage << " damage!\n";
			enemy.TakeDamage(attackDamage);
		}
		else if (choice == 2) {
			isDefending = true;
			std::cout << "You tuck your antennae in and brace yourself!\n";
		}
		else if (choice == 3) {
			std::cout << "--- SELECT HEALING ITEM ---\n";
			std::cout << "1) Sugar Cube (+35 HP)             [Owned: " << sugarCubes << "]\n";
			std::cout << "2) Stale Sugar Crystal (+10 HP)    [Owned: " << staleCrystals << "]\n";
			std::cout << "3) Cancel (Go Back)\n";

			unsigned int itemChoice = Helper::GetChoice(1, 3);
			std::cout << "\n";
			if (itemChoice == 1) {
				if (player.UseSpecificItem("Sugar Cube")) {
					std::cout << "You crunch on a Sugar Cube! (+35 HP) Current HP: " << player.GetHealth() << "\n";
				}
				else {
					std::cout << "You dont have any Sugar Cubes!\n";
					continue;
				}
			}
			else if (itemChoice == 2) {
				if (player.UseSpecificItem("Stale Sugar Crystal")) {
					std::cout << "You nibble on a Stale Sugar Crystal! (+10 HP) Current HP: " << player.GetHealth() << "\n";
				}
				else {
					std::cout << "You dont have any Stale Sugar Crystal!\n";
					continue;
				}
			}
			else {
				Helper::ClearConsoleWindow();
				continue;
			}
		}
		else if (choice == 4) {
			if (isBoss) {
				std::cout << "YOU CANNOT FLEE FROM A BOSS FIGHT! " << enemy.GetName() << " blocks all exits!\n";
			}
			else if (std::rand() % 3 == 0) {
				std::cout << "SUCCESS! You slipped into a tiny crack and escaped!\n";
				Helper::PauseConsole();
				return;
			}
			else {
				std::cout << "FAILED! The " << enemy.GetName() << " corners you!\n";
			}
		}

		if (enemy.IsAlive()) {
			enemy.ExecuteTurn(player, isDefending);
		}
		round++;
		std::cout << "\n";
		Helper::PauseConsole();
		Helper::ClearConsoleWindow();
	}

	if (player.IsAlive()) {
		int reward = enemy.GetCrumbReward();
		player.ModifyCrumbs(reward);

		std::cout << "VICTORY! You defeated the " << enemy.GetName() << "!\n";
		std::cout << "[REWARD]: You scavenged " << reward << " crumbs!\n";
		Helper::PauseConsole();
	}
}