#include "CombatSystem.h"
#include "Helper.h"
#include <iostream>
#include <cstdlib>

void CombatSystem::EngageBattle(Player& player)
{
	Helper::ClearConsoleWindow();
	std::cout << "You stumble across a menacing rat, it's ears twitches and it sets it's red eyes upon you!\n";
	std::cout << player.GetName() << " stands ready to face the ugly rat!\n\n";

	int ratHealth = 50;
	int ratAttack = 12;
	int roachAttack = 15;
	unsigned int round = 1;

	while (player.IsAlive() && ratHealth > 0) {
		std::cout << "[ROUND " << round++ << "]\n";
		std::cout << player.GetName() << " HP: " << player.GetHealth() << " | Lowly Rat HP: " << ratHealth << "\n";
		std::cout << " 1) Attack\n";
		std::cout << " 2) Defend\n";
		std::cout << " 3) Desperate sprint (try to flee)\n";

		unsigned int choice = Helper::GetChoice(1, 3);
		std::cout << "\n";
		if (choice == 1) {
			std::cout << "[!] You flare your wings and bite the rat for " << roachAttack << " damage!\n";
			ratHealth -= roachAttack;

			if (ratHealth > 0)
			{
				std::cout << " The rat squeaks in pain and swipes at you for " << ratAttack << " damage!\n";
				player.ModifyHealth(-ratAttack);
			}
		}
		else if (choice == 2) {
			int reducedDamage = ratAttack / 3;
			std::cout << "[!] You hunker under your exoskeleton shell, preparing for an attack!\n";
			std::cout << " The rat thrashes against you, but only inflicts " << reducedDamage << " damage!\n";
			player.ModifyHealth(-reducedDamage);
		}
		else if (choice == 3) {
			if (std::rand() % 3 == 0) {
				std::cout << "[!] SUCCESS! You dodged the rats angry swipe, and fled to the next floor!\n";
				Helper::PauseConsole();
				return;
			}
			else {
				std::cout << "[!] FAILED! You were too slow and swipes and deals " << ratAttack << " damage!\n";
				player.ModifyHealth(-ratAttack);
			}
		}
		std::cout << "\n";
		Helper::PauseConsole();
		Helper::ClearConsoleWindow();
	}
	if (player.IsAlive()) {
		int rewardedCrumbs = (std::rand() % 4) + 3;
		player.ModifyCrumbs(rewardedCrumbs);

		std::cout << "[!] VICTORY! You defeated the lowly rat!\n";
		std::cout << "[Reward]: You took " << rewardedCrumbs << " crumbs from the corpse of the rat!\n";
		Helper::PauseConsole();
	}
}