#include "Leaderboard.h"
#include "Helper.h"
#include <iostream>
#include <fstream>
#include <algorithm>

const std::string Leaderboard::FILE_NAME = "leaderboard.bin";

std::vector<ScoreEntry> Leaderboard::LoadScores()
{
	std::vector<ScoreEntry> scores;
	std::ifstream inFile(FILE_NAME, std::ios::binary);
	if (!inFile.is_open()) {
		return scores;
	}
	int count = 0;
	inFile.read(reinterpret_cast<char*>(&count), sizeof(count));

	for (int i = 0; i < count; i++) {
		ScoreEntry entry;
		int nameLength = 0;

		inFile.read(reinterpret_cast<char*>(&entry.floors), sizeof(entry.floors));
		inFile.read(reinterpret_cast<char*>(&entry.crumbs), sizeof(entry.crumbs));
		inFile.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));

		if (!inFile || nameLength <= 0 || nameLength > 256) break;

		std::string loadedName(nameLength, '\0');
		inFile.read(&loadedName[0], nameLength);
		entry.name = loadedName;

		scores.push_back(entry);
	}
	inFile.close();
	return scores;
}

void Leaderboard::SaveScores(const std::vector<ScoreEntry>& scores)
{
	std::ofstream outFile(FILE_NAME, std::ios::binary);
	if (!outFile.is_open()) {
		std::cout << "[DEBUG] ERROR: Could not open " << FILE_NAME << "for writing!\n";
		return;
	}
	int count = static_cast<int>(scores.size());
	outFile.write(reinterpret_cast<const char*>(&count), sizeof(count));

	for (const ScoreEntry& entry : scores) {
		outFile.write(reinterpret_cast<const char*>(&entry.floors), sizeof(entry.floors));
		outFile.write(reinterpret_cast<const char*>(&entry.crumbs), sizeof(entry.crumbs));

		int nameLength = static_cast<int>(entry.name.length());
		outFile.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
		outFile.write(entry.name.c_str(), nameLength);
	}
	outFile.close();
}

void Leaderboard::RecordScore(const std::string& playerName, int floorsSurvived, int finalCrumbs)
{
	std::vector<ScoreEntry> scores = LoadScores();
	scores.push_back({ playerName, floorsSurvived, finalCrumbs });

	std::sort(scores.begin(), scores.end(), [](const ScoreEntry& a, const ScoreEntry& b) { if (a.floors != b.floors) return a.floors > b.floors; return a.crumbs > b.crumbs; });

	if (scores.size() > 5)
	{
		scores.resize(5);
	}
	SaveScores(scores);
}

void Leaderboard::DisplayLeaderboard()
{
	std::vector<ScoreEntry> scores = LoadScores();
	Helper::ClearConsoleWindow();

	std::cout << "========================================================\n";
	std::cout << "      KITCHEN WALL HALL OF LEGENDS (TOP 5 RUNS)\n";
	std::cout << "========================================================\n";

	if (scores.empty()) {
		std::cout << "No runs recorded yet. Crawl into the walls to make a name for yourself!\n";
	}
	else {
		for (size_t i = 0; i < scores.size(); i++) {
			std::cout << " #" << (i + 1) << " | " << scores[i].name << " - Floor " << scores[i].floors << " (" << scores[i].crumbs << " Crumbs)\n";
		}
	}
	std::cout << "=========================================================\n";
}