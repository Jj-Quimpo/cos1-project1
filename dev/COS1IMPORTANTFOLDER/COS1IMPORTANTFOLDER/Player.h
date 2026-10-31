#pragma once
#include <string>
#include <vector>
class Player
{
private: 
	std::string mName;
	int mHealth;
	int mCrumbs;

public:
	Player(const std::string& name);

	std::string GetName() const;
	int GetHealth() const;
	int GetCrumbs() const;
	
	void ModifyHealth(int amount);
	void ModifyCrumbs(int amount);

	bool IsAlive() const;
};

