#include "Dungeon.h"
#include "Helper.h"
#include "CombatSystem.h"
#include <iostream>
#include <cstdlib>
#include "Merchant.h"
#include "Leaderboard.h"

Dungeon::Dungeon() {
	mFloorsSurvived = 0;
	mFloorDescriptions = {
		"You enter a tight gap choked with pink fiberglass insulation.",
		"You scurry near an old electrical outlet box humming with live wires.",
		"A warm draft carries the smell of old grease from behind stove piping.",
		"The wall cavity opens up near a leaky copper water line pipe."
	};
}

void Dungeon::StartGame(Player& player) {
	std::cout << "\nYou twitch your antennae, tighten your bag and squeeze through the baseboard gap...\n";
	Helper::PauseConsole();

	while (player.IsAlive()) {
		mFloorsSurvived++;

		Helper::ClearConsoleWindow();

		std::cout << "--- Floor " << mFloorsSurvived << " ---\n\n";
		std::cout << mFloorDescriptions[std::rand() % mFloorDescriptions.size()] << "\n";
		if (mFloorsSurvived % 10 == 0) {
			std::cout << "The floor trembles... A massive shadow blocks the path ahead!\n";
			Helper::PauseConsole();
			CombatSystem::EngageBattle(player, mFloorsSurvived, true);
		}
		else if (mFloorsSurvived % 10 == 9) {
			std::cout << "A friendly lantern flickers ahead-the Shady Roach Merchant sets up camp before the boss!\n";
			Helper::PauseConsole();
			Merchant::OpenShop(player);
		}
		else {
			int scenarioRoll = (std::rand() % 100) + 1;
			if (scenarioRoll <= 25) {
				HandleRatAmbush(player);
			}
			else if (scenarioRoll <= 50) {
				HandleHungryRoaches(player);
			}
			else if (scenarioRoll <= 75) {
				HandleCrumbCache(player);
			}
			else if (scenarioRoll <= 90) {
				Merchant::OpenShop(player);
			}
			else {
				HandleEmptyFloor(player);
			}
		}
		if (player.IsAlive()) {
			bool readyForNextFloor = false;
			Helper::ClearConsoleWindow();

			while (!readyForNextFloor && player.IsAlive()) {
				std::cout << "-------------------------------------------------------\n";
				std::cout << "STATS | HP: " << player.GetHealth() << " | Crumbs: " << player.GetCrumbs() << " | Floors Cleared: " << mFloorsSurvived << "\n";
				std::cout << "-------------------------------------------------------\n";
				std::cout << " 1) Continue deeper into the wall\n";
				std::cout << " 2) Check Inventory / Use Healing Item\n";
				std::cout << " 3) End Run (Retire & Save Score)\n";

				int nextStep = 0;
				while (true) {
					std::cout << "What will you do? (1-3): ";
					std::string input;
					std::getline(std::cin, input);

					try {
						nextStep = std::stoi(input);
						if (nextStep >= 1 && nextStep <= 3) {
							break;
						}
					}
					catch (...) {

					}
					std::cout << "Invalid choice. Please try again.\n";
				}

				if (nextStep == 1) {
					Helper::ClearConsoleWindow();
					std::cout << "And so you push forward...\n";
					readyForNextFloor = true;
					Helper::PauseConsole();
				}
				else if (nextStep == 2) {
					Helper::ClearConsoleWindow();
					std::cout << "===================================================\n";
					std::cout << "   " << player.GetName() << "'S INVENTORY\n";
					std::cout << "===================================================\n";
					std::cout << "ATK Power: " << player.GetAttackPower() << " | DEF Bonus " << player.GetDefenseBonus() << "\n\n";

					for (const std::string& item : player.GetInventory()) {
						std::cout << " - " << item << "\n";
					}
					int sugarCubes = player.GetItemCount("Sugar Cube");
					int staleCrystals = player.GetItemCount("Stale Sugar Crystal");

					std::cout << "\n--- USE HEALING ITEM ---\n";
					std::cout << " 1) Eat Sugar Cube (+35 HP)          [Owned: " << sugarCubes << "]\n";
					std::cout << " 2) Eat Stale Sugar Crystal (+15 HP) [Owned] " << staleCrystals << "]\n";
					std::cout << " 3) Back\n";

					int invChoice = 0;
					while (true) {
						std::cout << "What will you do? (1-3): ";
						std::string input;
						std::getline(std::cin, input);

						try {
							invChoice = std::stoi(input);
							if (invChoice >= 1 && invChoice <= 3) {
								break;
							}
						}
						catch (...) {

						}
						std::cout << "Invalid choice. Please try again.\n";
					}
					if (invChoice == 1) {
						if (player.UseSpecificItem("Sugar Cube"))
							std::cout << "\n  Restored 35 HP! Current HP: " << player.GetHealth() << "\n";
						else
							std::cout << "\n  No Sugar Cubes in your inventory!\n";
						Helper::PauseConsole();
					}
					else if (invChoice == 2) {
						if (player.UseSpecificItem("Stale Sugar Crystal"))
							std::cout << "\n  Restored 15 HP! Current HP: " << player.GetHealth() << "\n";
						else
							std::cout << "\n  No Stale Sugar Crystals in your inventory!\n";
						Helper::PauseConsole();
					}

					Helper::ClearConsoleWindow();

				}
				else if (nextStep == 3) {
					Helper::ClearConsoleWindow;
					std::cout << " You have no desire to continue and end your run...\n";
					Helper::PauseConsole();
					break;
				}
			}

			if (!readyForNextFloor) {
				break;
			}
		}
	}

	Helper::ClearConsoleWindow();
	std::cout << "===============================================\n";
	std::cout << "YOU ARE NOTHING MORE THAN JUST A CORPSE...\n";
	std::cout << "===============================================\n\n";
	std::cout << player.GetName() << " pershed inside the drywall.\n";
	std::cout << "Floors Explored: " << mFloorsSurvived << "\n";
	std::cout << "Final Crumb Count: " << player.GetCrumbs() << "\n";
	std::cout << "===============================================\n";

	Leaderboard::RecordScore(player.GetName(), mFloorsSurvived, player.GetCrumbs());
	std::cout << "Your run has been recorded on the Leaderboard!\n";
}

void Dungeon::HandleRatAmbush(Player& player) {
	CombatSystem::EngageBattle(player, mFloorsSurvived, false);
}

void Dungeon::HandleHungryRoaches(Player& player) {
	int randomFavor = (std::rand() % 10) + 1;
	
	std::cout << "You see a small group of starving roaches among the floor.\n";
	std::cout << "----------------------------------------------------------------------------------------------------\n";
	std::cout << "\n\"Excuse me friend, would you happen to be able to spare some crumbs for us.\" one roach clicks.\n";
	std::cout << "\n1) Give the asked amount of " << randomFavor << " crumbs.\n";
	std::cout << "2) Refuse to give crumbs on move on.\n";

	int choice = 0;
	while (true) {
		std::cout << "What will you do? (1-2): ";
		std::string input;
		std::getline(std::cin, input);

		try {
			choice = std::stoi(input);
			if (choice >= 1 && choice <= 2) {
				break;
			}
		}
		catch (...) {

		}
		std::cout << "Invalid choice. Please try again.\n";
	}

	if (choice == 1)
	{
		if (player.GetCrumbs() >= randomFavor) {
			player.ModifyCrumbs(-randomFavor);
			std::cout << "\n\"Oh thank you kind friend, we will never forget this!\"\n";
			std::cout << "\n[!] Your kindness brings you good fortune! +25 HP.\n";
			player.ModifyHealth(25);
			std::cout << "Current Health: " << player.GetHealth() << "\n";
		}
		else {
			std::cout << "\"Im sorry friend but... you do not have enough.\" They slowly skitter away leaving you alone.\n";
			std::cout << "\nYou tried to help but it wasn't enough. The guilt weighs heavy on your head. -5 HP.\n";
			player.ModifyHealth(-5);
			std::cout << "Current Health: " << player.GetHealth() << "\n";
		}
	}
	else
	{
		std::cout << "\nYou shake your head. \"Get lost! If you want to live find your own.\" you clicked\n";
		std::cout << "\nBut as you try to move on one of the roaches hurls a rock towards you.\n";
		if (std::rand() % 3 == 0) {
			std::cout << "\nThe rock missed but as you turn to confront them they were no where to be seen.\n";
		}
		else {
			std::cout << "\nThe rock hits your head causing 12 damage, you try to look to see who've done it but they were no where to be seen.\n";
			player.ModifyHealth(-12);
			std::cout << "Current Health: " << player.GetHealth() << "\n";
		}
	}
	Helper::PauseConsole();
}

void Dungeon::HandleCrumbCache(Player& player) {
	
	std::cout << "You stumble across a pile of savory crubs covered in some dust.\n";
	std::cout << "----------------------------------------------------------------------------------------\n";
	std::cout << "\n1) Indulge yourself with the crumbs now to restore your health.\n";
	std::cout << "2) Carefully pack the crumbs up to use as currency for later\n";
	int choice = 0;
	while (true) {
		std::cout << "What will you do? (1-2): ";
		std::string input;
		std::getline(std::cin, input);

		try {
			choice = std::stoi(input);
			if (choice >= 1 && choice <= 2) {
				break;
			}
		}
		catch (...) {

		}
		std::cout << "Invalid choice. Please try again.\n";
	}

	if (choice == 1)
	{
		std::cout << "\n Delicious! You gorge yourself with the tasty crumbs without a second thought.";
		player.ModifyHealth(25);
		std::cout << "(+25 HP restored! Current Health: " << player.GetHealth() << ")\n";
	}
	else
	{
		int foundCrumbs = (std::rand() % 18) + 3;
		player.ModifyCrumbs(foundCrumbs);
		std::cout << "\n[!] You carfully tuck " << foundCrumbs << " crumbs into your pack!\n";
	}
	Helper::PauseConsole();
}

void Dungeon::HandleEmptyFloor(Player& player) {
	
	std::cout << "The floor is completely empty, no sign of life, completely dark.\n"; 
	std::cout << "---------------------------------------------------------------------------------------\n";
	int dropRoll = std::rand() % 100;

	if (dropRoll < 10) {
		player.AddItem("Sugar Cube");
		std::cout << "  RARE FIND! Tucked inside the insulation, you uncovered an intact [Sugar Cube]!\n";
	}
	else if (dropRoll < 30) {
		player.AddItem("Stale Sugar Crystal");
		std::cout << "  LUCKY FIND! You spotted a [Stale Sugar Crystal] wedged near the floorboards!\n";
	}
	else {
		std::cout << "It's peaceful but also a little creepy.\n";
	}
	Helper::PauseConsole();
}