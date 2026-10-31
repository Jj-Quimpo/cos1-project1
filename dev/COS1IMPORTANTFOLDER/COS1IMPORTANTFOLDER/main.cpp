
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Helper.h"
#include "Player.h"
#include "Dungeon.h"

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	bool menuRunning = true;

	while (menuRunning) {
		std::cout << " COCKROACHES TALE: THE KITCHEN WALL \n";
		std::cout << " 1) Start Journey\n";
		std::cout << " 2) Exit Game\n";

		unsigned int choice = Helper::GetChoice(1, 2);

		switch (choice)
		{
		case 1:
		{
			std::cout << "you are in the game\n";
			std::cout << "Name: ";
			std::string roachName;
			std::getline(std::cin, roachName);

			Player userRoach(roachName);
			Dungeon gameEngine;

			gameEngine.StartGame(userRoach);

			break;
		}
		case 2:
		{
			std::cout << "\nYou decide to lay your ambitions to rest and relax for now...\n";
			menuRunning = false;
			break;
		}

		}
	}
	std::cout << "Closing game\n";
	Helper::PauseConsole();
	return 0;
}

