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

		std::cout << "\nFloor " << mFloorsSurvived;

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
			std::cout << "HP: " << player.GetHealth() << " Crumbs: " << player.GetCrumbs() << " Floors Cleared: " << mFloorsSurvived << "\n";
			Helper::PauseConsole();
		}
	}

	std::cout << player.GetName() << " pershed inside the drywall.\n";
	std::cout << "Floors Explored: " << mFloorsSurvived << "\n";
}

void Dungeon::HandleRatAmbush(Player& player) {
	std::cout << "This is scenario 1";
	Helper::PauseConsole();
}

void Dungeon::HandleHungryRoaches(Player& player) {
	std::cout << "This is scenario 2";
	Helper::PauseConsole();
}

void Dungeon::HandleCrumbCache(Player& player) {
	std::cout << "This is scenario 3";
	Helper::PauseConsole();
}

void Dungeon::HandleEmptyFloor(Player& player) {
	std::cout << "This is scenario 4";
	Helper::PauseConsole();
}