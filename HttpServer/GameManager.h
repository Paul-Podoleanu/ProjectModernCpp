#pragma once
#include "DuelManager.h"
#include "Game.h"

class GameManager
{
	std::vector<GamePlayer> players;
	std::vector<Region> regions;
	DuelManager DuelManager;
	int playerCount;
	
};

//HANDLERS
class StartDuelHandler
{
public:
	crow::response operator()(const crow::request& req);
};

class ClickRegionHandler {
public:
	crow::response operator()(const crow::request& req);
};
