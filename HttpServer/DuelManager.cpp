#include "DuelManager.h"

//DUELMANAGER CODE

void DuelManager::NormalPlayerDuel(GamePlayer playerOne, GamePlayer playerTwo, Region region)
{
}

void DuelManager::BaseDuel(GamePlayer playerOne, GamePlayer playerTwo, Region base)
{
}


//HANDLER CODE
//Posibil sa nu fie necesar aici, doar sa fie necesar in GameManager.cpp
crow::response StartDuelHandler::operator()(const crow::request& req)
{
    auto urlArgs = parseUrlArgs(req.body);
    auto username1 = urlArgs["username1"];
    auto username2 = urlArgs["username2"];
	auto region = urlArgs["region"];
	auto isBase = urlArgs["base"];


    
    if (isBase == "region") {
        for (auto game : db.iterate<Lobby>()) {
            
        }
        //NormalPlayerDuel()

        return crow::response(200);
    }

	if (isBase == "base") {
		//BaseDuel()
		return crow::response(200);
	}

	return crow::response(200);
    
}

