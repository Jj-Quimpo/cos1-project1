#pragma once
#include <iostream>
#include <string>
#include <cstdlib>

class Helper {
private:
	static bool IntegerValidation(const char* input)
	{
		if (input == nullptr || input[0] == '\0') return false;

		int i = 0;
		if (input[i] == '-' || input[i] == '+') i++;
		if (input[i] == '\0') return false;

		while (input[i] != '\0')
		{
			if (!std::isdigit(static_cast<unsigned char>(input[i]))) return false;
		}
		return true;
	}

public: 
	static unsigned int GetChoice(unsigned int min, unsigned int max)
	{
		std::string input;
		unsigned int choice = 0;
		while (true)
		{
			std::cout << "What will you do? (" << min << "-" << max << "): ";
			std::getline(std::cin, input);

			if (IntegerValidation(input.c_str()))
			{
				long long value = std::strtoll(input.c_str(), nullptr, 10);

				if (value >= static_cast<long long>(min) && value <= static_cast<long long>(max))
				{
					choice = static_cast<unsigned int>(value);
					break;
				}
			}
			std::cout << "Invalid choice. Please try again.\n";
		}
		return choice;
	}

	static void PauseConsole()
	{
		std::cout << "Press Enter to continue...";
		std::cin.get();
	}
};