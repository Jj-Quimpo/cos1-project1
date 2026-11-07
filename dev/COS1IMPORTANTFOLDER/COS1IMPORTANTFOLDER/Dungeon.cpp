#include "Dungeon.h"
#include "Helper.h"
#include <iostream>
#include <cstdlib>

Dungeon::Dungeon() {
	mFloorsSurvived = 0;

}

void Dungeon::StartGame(Player& player) {
	
	while (player.IsAlive()) {
		mFloorsSurvived++;

		std::cout << "\nFloor " << mFloorsSurvived << "\n";

		int scenarioRoll = (std::rand() % 100) + 1;
		if (scenarioRoll <= 25) {
			HandleRatAmbush(player);
		}
		else if (scenarioRoll <= 55) {
			HandleHungryRoaches(player);
		}
		else if (scenarioRoll <= 85) {
			HandleCrumbCache(player);
		}
		else {
			HandleEmptyFloor(player);
		}

		if (player.IsAlive()) {
			std::cout << "\nSTATS | HP: " << player.GetHealth() << " | Crumbs: " << player.GetCrumbs() << " | Floors Cleared: " << mFloorsSurvived << "\n";
			std::cout << "And so you continue forward...\n";
			Helper::PauseConsole();
		}
	}

	Helper::ClearConsoleWindow();
	std::cout << "YOU ARE NOTHING MORE THAN JUST A CORPSE...";
	std::cout << player.GetName() << " pershed inside the drywall.\n";
	std::cout << "Floors Explored: " << mFloorsSurvived << "\n";
	std::cout << "Final Crumb Count: " << player.GetCrumbs() << "\n";
}

void Dungeon::HandleRatAmbush(Player& player) {
	std::cout << "scenario 1";
	Helper::PauseConsole();
}

void Dungeon::HandleHungryRoaches(Player& player) {
	int randomFavor = (std::rand() % 10) + 1;
	std::cout << "You see a small group of starving roaches among the floor.\n";
	std::cout << "\n\"Excuse me friend, would you happen to be able to spare some crumbs for us.\" one roach clicks.\n";
	std::cout << "\n1) Give the asked amount of " << randomFavor << " crumbs.\n";
	std::cout << "2) Refuse to give crumbs on move on.\n";

	unsigned int choice = Helper::GetChoice(1, 2);

	if (choice == 1)
	{
		if (player.GetCrumbs() >= randomFavor) {
			player.ModifyCrumbs(-randomFavor);
			std::cout << "\n\"Oh thank you kind friend, we will never forget this!\"\n";
			std::cout << "\n[!] Your kindness brings you good fortune! +10 HP.\n";
			player.ModifyHealth(10);
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
			std::cout << "\nThe rock hits your head causing 15 damage, you try to look to see who've done it but they were no where to be seen.\n";
			player.ModifyHealth(-15);
			std::cout << "Current Health: " << player.GetHealth() << "\n";
		}
	}
}

void Dungeon::HandleCrumbCache(Player& player) {
	std::cout << "You stumble across a pile of savory crubs covered in some dust.\n";
	std::cout << "\n1) Indulge yourself with the crumbs now to restore your health.\n";
	std::cout << "2) Carefully pack the crumbs up to use as currency for later\n";
	unsigned int choice = Helper::GetChoice(1, 2);

	if (choice == 1)
	{
		std::cout << "\n Delicious! You gorge yourself with the tasty crumbs without a second thought.";
		player.ModifyHealth(25);
		std::cout << "(+25 HP restored! Current Health: " << player.GetHealth() << ")\n";
	}
	else
	{
		int foundCrumbs = (std::rand() % 4) + 2;
		player.ModifyCrumbs(foundCrumbs);
		std::cout << "\n[!] You carfully tuck " << foundCrumbs << " crumbs into your pack!\n";
	}
}

void Dungeon::HandleEmptyFloor(Player& player) {
	std::cout << "The floor is completely empty, no sign of life, completely dark. It's peaceful but also a little creepy.\n";
}