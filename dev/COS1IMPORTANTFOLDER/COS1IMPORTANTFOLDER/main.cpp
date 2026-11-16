
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
		std::cout << "====================================\n";
		std::cout << " COCKROACHES TALE: THE KITCHEN WALL \n";
		std::cout << "====================================\n";
		std::cout << " 1) Start Journey\n";
		std::cout << " 2) Exit Game\n";
		std::cout << "====================================\n";

		unsigned int choice = Helper::GetChoice(1, 2);

		switch (choice)
		{
		case 1:
		{
			Helper::ClearConsoleWindow();
			std::cout << "________________________________________________________________________________________________________________________\n";
			std::cout << "There are tales about the walls of the kitchen, many roaches claim there are riches of crumbs to last ones lifetime.\n";
			std::cout << "Others talk of the dangerous rats that attack any poor roach they come across.\n";
			std::cout << "Of course many roaches venture forth in search of the truth about the kitchen walls, some return many don't.\n";
			std::cout << "This is the tale of one roach who decided they wanted to quench their curisoty and witness what lies behind the plaster.\n";
			std::cout << "-------------------------------------------------------------------------------------------------------------------------\n\n";
			std::cout << "What is the name of this brave yet foolish roach: ";
			std::string roachName;
			std::getline(std::cin, roachName);

			Player userRoach(roachName);
			Dungeon gameEngine;

			gameEngine.StartGame(userRoach);

			std::cout << "\nReturning to the Main Menu...\n";
			Helper::PauseConsole();
			break;
		}
		case 2:
		{
			Helper::ClearConsoleWindow();
			std::cout << "\nYou decide to lay your ambitions to rest for now...\n\n";
			menuRunning = false;
			break;
		}

		}
	}
	std::cout << "Closing game\n";
	Helper::PauseConsole();
	return 0;
}

