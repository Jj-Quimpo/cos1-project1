#pragma once
#include<string>
#include<vector>

struct ScoreEntry
{
	std::string name;
	int floors;
	int crumbs;
};

class Leaderboard
{
private:
	static const std::string FILE_NAME;
	static std::vector<ScoreEntry> LoadScores();
	static void SaveScores(const std::vector<ScoreEntry>& scores);

public:
	static void RecordScore(const std::string& playerName, int floorsSurvived, int finalCrumbs);
	static void DisplayLeaderboard();
};

