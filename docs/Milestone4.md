## Features Added
* Persistant binary leaderboard that saves and loads top 5 runs, ranked by floors survived and crumbs collected
* Between-floor management menu allowing players to continue deeper into the wall, view their inventory and eat healing items, or retire early to save their score
* Rare item drop in empty floor giving a random chance to find a sugar cube or stale sugar cyrstal
* Ugraded equipment levels that display their current level in the players inventoryas they are upgraded

## Updates to system design
* Added 'Leaderboard.h' and 'Leaderboard.cpp' using 'std::ios::binary' file stream to persist high scores across game sessions
* Updated 'Dungeon::StartGame' with a between-floor loop ('readyForNextFloor') 
* Replaced 'Helper::GetMenuChoice' in gameplay menus ('Dungeon', 'CombatSystem', and Merchant') with 'std::getline' and 'std::stoi'input parsing whil keeping 'Helper' for the main menu
*
## Refactoring Improvements
* Fixed armor-piercing boss attacks
* Rebalanced crumb cache rewards to give 3-20 and cleaned up 'Leaderboard::LoadScores' binary string reading*