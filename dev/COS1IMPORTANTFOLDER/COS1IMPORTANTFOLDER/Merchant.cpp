#include "Merchant.h"
#include "Helper.h"
#include <iostream>

void Merchant::OpenShop(Player& player) {
	bool shopping = true;

	while (shopping) {
		Helper::ClearConsoleWindow();
		std::cout << "==========================================================\n";
		std::cout << "SHADY ROACH MERCHANT: \"GOT ANY CRUMBS?\"\n";
		std::cout << "==========================================================\n";
		std::cout << "A heavily scarred roach opens his wings to show his wares.\n";
		std::cout << "Your Stats | HP: " << player.GetHealth() << " | Crumbs: " << player.GetCrumbs() << " | ATK: " << player.GetAttackPower() << " | DEF: " << player.GetDefenseBonus() << "\n";
		std::cout << "----------------------------------------------------------\n";
		std::cout << "1) Sugar Cube (+35 HP)                     - 8 Crumbs\n";
		std::cout << "2) Stale Sugar Crystal (+15 HP)            - 5 Crumbs\n";
		std::cout << "3) Sharpened Thumbtack (+5 ATK)            - 10 Crumbs\n";
		std::cout << "4) Tin Foil Plating (+3 DEF)               - 10 Crumbs\n";
		std::cout << "5) Leave Shop\n";
		std::cout << "----------------------------------------------------------\n";

		int choice = 0;
		while (true) {
			std::cout << "What will you do? (1-5): ";
			std::string input;
			std::getline(std::cin, input);

			try {
				choice = std::stoi(input);
				if (choice >= 1 && choice <= 5) {
					break;
				}
			}
			catch (...) {

			}
			std::cout << "Invalid choice. Please try again.\n";
		}
		std::cout << "\n";

		if (choice == 1) {
			if (player.GetCrumbs() >= 8) {
				player.ModifyCrumbs(-8);
				player.AddItem("Sugar Cube");
				std::cout << "You tucked a [Sugar Cube] into your pack (Restores 35 HP when used)\n";
			}
			else {
				std::cout << "\"No credit, kid! Come back with 8 crumbs.\"\n";
			}
			Helper::PauseConsole();
		}
		else if (choice == 2) {
			if (player.GetCrumbs() >= 5) {
				player.ModifyCrumbs(-5);
				player.AddItem("Stale Sugar Crystal");
				std::cout << "You tucked a [Stale Sugar Crystal] into your pack (Restors 15 HP when used)\n";
			}
			else {
				std::cout << "\"Are you messing with me? you need 5 crumbs if you want this!\"\n";
			}
			Helper::PauseConsole();
		}
		else if (choice == 3) {
			if (player.GetCrumbs() >= 10) {
				player.ModifyCrumbs(-10);
				player.UpgradeAttack(5);
				std::cout << "The Merchant upgrades your spear with the [Thumbtack], [Splinter Spear (Lv. " << player.GetSpearLevel() << ")]!\n";
			}
			else {
				std::cout << "\"You know, you're not the only one who needs to live! I need at least 10 crumbs.\"\n";
			}
			Helper::PauseConsole();
		}
		else if (choice == 4) {
			if (player.GetCrumbs() >= 10) {
				player.ModifyCrumbs(-10);
				player.UpgradeDefense(3);
				std::cout << "The merchant rivets scrap tin onto your [Soda Tab Buckler (Lv. " << player.GetShieldLevel() << ")]!\n";
			}
			else {
				std::cout << "\"Tin foil ain't cheap. You need 10 crumbs\"\n";
			}
			Helper::PauseConsole();
		}
		else if (choice == 5) {
			std::cout << "\"Stay out of the mousetraps, friend!\" The merchant vanishes into a crack.\n";
			Helper::PauseConsole();
			shopping = false;
		}
	}
}
