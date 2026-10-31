#pragma once
#include <string>
#include <vector>
#include "Player.h"

class Dungeon
{
private:
	int mFloorsSurvived;

	void HandleRatAmbush(Player& player);
	void HandleHungryRoaches(Player& player);
	void HandleCrumbCache(Player& player);
	void HandleEmptyFloor(Player& player);

public:
	Dungeon();
	void StartGame(Player& player);

};

