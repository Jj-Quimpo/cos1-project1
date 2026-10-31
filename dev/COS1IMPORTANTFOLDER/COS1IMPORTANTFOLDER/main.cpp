
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Helper.h"

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
			break;
		}
		case 2:
		{
			std::cout << "\nYou are now exiting the game\n";
			menuRunning = false;
			break;
		}

		}
	}
	std::cout << "Closing game\n";
	Helper::PauseConsole();
	return 0;
}

